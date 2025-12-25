#ifndef __ME_AI_H__
#define __ME_AI_H__

#include <assert.h>

typedef struct {
	void (*evaluate)(void *);
} ME_AI;


void me_init_ai(ME_AI * me_ai);

#endif