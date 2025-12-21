/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : Debugging Header
	Date : 04/12/2025
*/

#ifndef __ME_DEBUG_H__
#define __ME_DEBUG_H__

typedef enum {
	ME_DBG_NFM=0,
	ME_DBG_VIDEO=1,
	ME_DBG_INFO=2
} me_debug_mode;


typedef struct 
{
	me_debug_mode mode;
	int level;
	char * message_debug;
} me_debug;



void debug(me_debug* md, 	const char * me_no_format_message);

void debug_p1(me_debug* md, const char * me_formatted_message, int * p1);

void debug_p2(me_debug* md, const char * me_formatted_message, int * p1, int * p2);

void debug_p3(me_debug* md, const char * me_formatted_message, int * p1, int *p2, int *p3);

void debug_p4(me_debug* md, const char * me_formatted_message, int * p1, int *p2, int *p3, int *p4);

void no_blocking_debug(me_debug * md, const char * me_formatted_message);

#endif