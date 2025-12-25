#include "../include/me_system.h"

ME_System * create_MirtilleSystem(){
	ME_System * me_system = (ME_System *) malloc(sizeof(ME_System));
	if(me_system == NULL){
		return NULL;
	}
	assert(me_system != NULL);

	return me_system;
}


void me_init_System(ME_System * me_system, const char * title){
	// TODO : HERE
	assert(me_system != NULL);
	assert(title != NULL);
}

void me_configuration_init_system(ME_System * me_system){
	// TODO : HERE
	assert(me_system != NULL);
}

void me_destroy_System(ME_System * me_system){
	// TODO : HERE
	assert(me_system != NULL);
}
