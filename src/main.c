#include <stdio.h>


int me_checkOptions(char * me_dataPath, char * me_savePath) {
	for (int i = 1; i < argc; ++i) {
		bool opt = false;
		if (strlen(argv[i]) >= 2) {
			opt |= parseOption(argv[i], "datapath=", &dataPath);
			opt |= parseOption(argv[i], "savepath=", &savePath);

		}
		if (!opt) {
			printf("%s",USAGE);
			return ME_EXIT_FAILURE; //0 à vérifier en urgence !!!!
		}
	}
	return 1;
}


static const char *USAGE = 
	"ME - Mirtille Virtual Machine \n"
	"Usage: mirtille [OPTIONS]...\n"
	"  --datapath=PATH   Path to where the OS is installed (default '.')\n"
	"  --savepath=PATH   Path to where the save files are stored (default '.')\n";

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


enum MIRTILLE_MACHINE_ERROR_CODE 
main(int argc, char const *argv[])
{
	const char *me_dataPath = ".";
	const char *me_savePath = ".";

	if(0 == me_checkOptions(&me_dataPath, &me_savePath)){
		return ME_EXIT_FAILURE;
	}
	
	Mirtille_Engine * me = me_create_MirtilleEngine(stub, me_dataPath, me_savePath);
	me_configuration_init(me);
	me_run(me);


	me_destroy_MirtilleEngine(me);

	return ME_EXIT_FAILURE;
}