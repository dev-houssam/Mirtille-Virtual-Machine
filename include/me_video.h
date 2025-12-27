/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : C Video
	Date : 04/12/2025
*/



#ifndef __ME_VIDEO_H__
#define __ME_VIDEO_H__

//#include "me_system.h"
#include "me_serializer.h"
#include <stdint.h>
//#define NDEBUG
#include <assert.h>
#include <math.h>

struct ME_Video;

struct ME_System;



typedef enum {
	ME_VIDEO_STATE_INVALID = -1,
	ME_VIDEO_STATE_KO 	   =  0,
	ME_VIDEO_STATE_OK 	   =  1
} ME_VIDEO_STATE_T;



typedef struct { } Designer;


typedef struct {
	void (*callback)(float *); //struct ME_Video* video

	struct ME_System *sys;

	uint8_t *bufferFront1;
	uint8_t *bufferSwap2;
	uint8_t *bufferBack3;

	Designer designerBuffer;

	uint8_t *_dataBuf;
} ME_Video;

// Création et Liaison système
ME_Video * me_create_video();
// Configuration et ajustement
void me_configuration_init_video(ME_Video* video);

void * Screen(void * arg);

// Display Window Server (DWS) for system
void me_windows_openGL_loop();

void me_setDataBuffer(ME_Video* video, uint8_t *dataBuf, uint16_t offset);
void me_readAndDrawDesigner(ME_Video* video, uint8_t color, uint16_t zoom, const Designer *ds);
void me_fillDesigner(ME_Video* video, uint16_t color, uint16_t zoom, const Designer *pt);
void me_drawDesigner(ME_Video* video, uint8_t color, int16_t x, int16_t y);
uint8_t *me_getPage(ME_Video* video, uint8_t page);
//void me_updateDisplay(ME_Video* video, uint8_t page);
void me_saveOrLoad(ME_Video* video, ME_Serializer *ser);

//Real time printing in screen

static void * callback();

#endif