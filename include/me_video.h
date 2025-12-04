/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : C Video
	Date : 04/12/2025
*/



#ifndef __ME_VIDEO_H__
#define __ME_VIDEO_H__

#include "intern.h"

struct StrEntry {
	uint16_t id;
	const char *str;
};

struct Polygon;

struct Serializer;
struct System;


typedef struct {
	typedef void (void *drawLine)(Video * video, int16_t x1, int16_t x2, uint8_t col);

	static const uint8_t _font[];
	static const StrEntry _stringsTableEng[];
	static const StrEntry _stringsTableDemo[];

	System *sys;

	uint8_t paletteIdRequested, currentPaletteId;
	uint8_t *_pages[4];

	// I am almost sure that:
	// _curPagePtr1 is the work buffer
	// _curPagePtr2 is the background buffer1
	// _curPagePtr3 is the background buffer2
	uint8_t *_curPagePtr1, *_curPagePtr2, *_curPagePtr3;

	Polygon polygon;
	int16_t _hliney;

	//Precomputer division lookup table
	uint16_t _interpTable[0x400];

	Ptr _pData;
	uint8_t *_dataBuf;
} Video ;


void me_init(Video * video, Resource *res, System *stub);

void me_configuration_init_video(Video * video);

void me_setDataBuffer(Video * video, uint8_t *dataBuf, uint16_t offset);

void me_readAndDrawPolygon(Video * video, uint8_t color, uint16_t zoom, const Point &pt);

void me_fillPolygon(Video * video, uint16_t color, uint16_t zoom, const Point &pt);

void me_readAndDrawPolygonHierarchy(Video * video, uint16_t zoom, const Point &pt);

int32_t me_calcStep(Video * video, const Point &p1, const Point &p2, uint16_t &dy);

void me_drawString(Video * video, uint8_t color, uint16_t x, uint16_t y, uint16_t strId);

void me_drawChar(Video * video, uint8_t c, uint16_t x, uint16_t y, uint8_t color, uint8_t *buf);

void me_drawPoint(Video * video, uint8_t color, int16_t x, int16_t y);

void me_drawLineBlend(Video * video, int16_t x1, int16_t x2, uint8_t color);

void me_drawLineN(Video * video, int16_t x1, int16_t x2, uint8_t color);

void me_drawLineP(Video * video, int16_t x1, int16_t x2, uint8_t color);

uint8_t *me_getPage(Video * video, uint8_t page);

void me_changePagePtr1(Video * video, uint8_t page);

void me_fillPage(Video * video, uint8_t page, uint8_t color);

void me_copyPage(Video * video, uint8_t src, uint8_t dst, int16_t vscroll);

void me_copyPage(Video * video, const uint8_t *src);

void me_changePal(Video * video, uint8_t pal);

void me_updateDisplay(Video * video, uint8_t page);

void me_saveOrLoad(Video * video, Serializer &ser);


#endif