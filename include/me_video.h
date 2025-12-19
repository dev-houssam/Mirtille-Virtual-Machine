/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : C Video
	Date : 04/12/2025
*/



#ifndef __ME_VIDEO_H__
#define __ME_VIDEO_H__

//#include "intern.h"
#include <stdint.h>

struct StrEntry {
	uint16_t id;
	char *str;
};

struct Polygon;

struct Serializer;

struct ME_System;

struct ME_Video;

typedef struct { } Designer;

typedef struct {
	void (*drawLine)(struct ME_Video* video, int16_t x1, int16_t x2, uint8_t col);

	ME_System *sys;

	uint8_t paletteIdRequested, currentPaletteId;
	uint8_t *_pages[4];

	uint8_t *bufferFront1;
	uint8_t *bufferSwap2;
	uint8_t *bufferBack3;

	Designer designerBuffer;

	uint8_t *_dataBuf;
} ME_Video;


void me_init(ME_Video* video, ME_Resource *res, ME_System *stub);
void me_configuration_init_video(ME_Video* video);
void me_setDataBuffer(ME_Video* video, uint8_t *dataBuf, uint16_t offset);
void me_readAndDrawDesigner(ME_Video* video, uint8_t color, uint16_t zoom, const Designer *ds);
void me_fillDesigner(ME_Video* video, uint16_t color, uint16_t zoom, const Designer *pt);
void me_readAndDrawPolygonHierarchy(ME_Video* video, uint16_t zoom, const Designer *pt);
int32_t me_calcStep(ME_Video* video, const Designer *p1, const Designer *p2, uint16_t *dy);
void me_drawString(ME_Video* video, uint8_t color, uint16_t x, uint16_t y, uint16_t strId);
void me_drawChar(ME_Video* video, uint8_t c, uint16_t x, uint16_t y, uint8_t color, uint8_t *buf);
void me_drawDesigner(ME_Video* video, uint8_t color, int16_t x, int16_t y);
void me_drawLineBlend(ME_Video* video, int16_t x1, int16_t x2, uint8_t color);
void me_drawLineN(ME_Video* video, int16_t x1, int16_t x2, uint8_t color);
void me_drawLineP(ME_Video* video, int16_t x1, int16_t x2, uint8_t color);
uint8_t *me_getPage(ME_Video* video, uint8_t page);
void me_changePagePtr1(ME_Video* video, uint8_t page);
void me_fillPage(ME_Video* video, uint8_t page, uint8_t color);
void me_copyPage(ME_Video* video, uint8_t src, uint8_t dst, int16_t vscroll);
void me_copyPage(ME_Video* video, const uint8_t *src);
void me_changePal(ME_Video* video, uint8_t pal);
void me_updateDisplay(ME_Video* video, uint8_t page);
void me_saveOrLoad(ME_Video* video, Serializer *ser);


#endif