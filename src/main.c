#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "../include/me_error.h"
#include "../include/me_engine.h"


/*int parseOption(const char * path, const char * path, &me_dataPath){
	return 0;
}*/

static bool me_parseOption(const char *arg, const char *longCmd, const char **opt);

static const char *USAGE = 
	"ME - Mirtille Virtual Machine \n"
	"Usage: mirtille [OPTIONS]...\n"
	"  --datapath=PATH   Path to where the OS is installed (default '.')\n"
	"  --savepath=PATH   Path to where the save files are stored (default '.')\n";



int me_checkOptions(int argc, char const *argv[], const char * me_dataPath, const char * me_savePath) {
	for (int i = 1; i < argc; ++i) {
		int opt = false;
		if (strlen(argv[i]) >= 2) {
			opt |= me_parseOption(argv[i], "datapath=", &me_dataPath);
			opt |= me_parseOption(argv[i], "savepath=", &me_savePath);

		}
		if (!opt) {
			printf("%s\n",USAGE);
			return ME_EXIT_FAILURE; //0 à vérifier en urgence !!!!
		}
	}
	return 1;
}



static bool me_parseOption(const char *arg, const char *longCmd, const char **opt) {
	bool ret = false;
	if (arg[0] == '-' && arg[1] == '-') {
		if (strncmp(arg + 2, longCmd, strlen(longCmd)) == 0) {
			*opt = arg + 2 + strlen(longCmd);
			ret = true;
		}
	}
	return ret;
}


MIRTILLE_MACHINE_ERROR_CODE 
main(int argc, char const *argv[])
{
	const char *me_dataPath = ".";
	const char *me_savePath = ".";

	if(0 == me_checkOptions(argc, argv, me_dataPath, me_savePath)){
		return ME_EXIT_FAILURE;
	}

	
	Mirtille_Engine * me = me_create_MirtilleEngine(NULL, NULL, me_dataPath, me_savePath);
	me_configuration_init_engine(me);
	me_run(me);


	me_destroy_MirtilleEngine(me);

	return ME_EXIT_FAILURE;
}