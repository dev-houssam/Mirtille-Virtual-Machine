/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : Debugging
	Date : 04/12/2025
*/

#include "../include/me_debug.h"
#include <pthread.h>
#include <stdio.h>


void debug(me_debug* md, 	const char * me_no_format_message){
    fprintf(stderr, "%s\nLEVEL: %d\n", md->message_debug, md->level);
}

void debug_p1(me_debug* md, const char * me_formatted_message, int * p1){
    fprintf(stderr, "%s::%d\n", md->message_debug, *p1);
}

void debug_p2(me_debug* md, const char * me_formatted_message, int * p1, int * p2){
    fprintf(stderr, "%s::%d::%d\n", md->message_debug, *p1, *p2);
}

void debug_p3(me_debug* md, const char * me_formatted_message, int * p1, int *p2, int *p3){
    fprintf(stderr, "%s::%d::%d::%d\n", md->message_debug, *p1, *p2, *p3);
}

void debug_p4(me_debug* md, const char * me_formatted_message, int * p1, int *p2, int *p3, int *p4){
    fprintf(stderr, "%s::%d::%d::%d::%d\n", md->message_debug, *p1, *p2, *p3, *p4);
}

void* no_bloking_printing(void* me_arg) {
	me_debug * md = (me_debug * ) me_arg;
    fprintf(stderr, "%s\nLEVEL: %d\n", md->message_debug, md->level);
    return NULL;
}


void no_blocking_debug(me_debug * md, const char * me_formatted_message){
	if (md == NULL) return;

	md->message_debug = me_formatted_message;
	md->level = 0;

	switch(md->mode){
		case ME_DBG_NFM:
			pthread_t thread;
			pthread_create(&thread, NULL, (void *) md, NULL);
			fprintf(stderr, "%s: %s\n", "Non no_blocking_debug mode error", md->message_debug);
			break; 
		default:
			break;
	}
}