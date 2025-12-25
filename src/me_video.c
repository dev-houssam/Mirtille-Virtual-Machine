/*
	Author : Houssam BACAR
	Project Name : Mirtille Virtual Machine
	Description : C Video
	Date : 21/12/2025
*/


#include "../include/me_video.h"
#include "../include/me_system.h"
#include "../include/me_debug.h"
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

const char * compileTest(){return "gcc filename.c -lGL -lGLU -lglut";}

void me_windows_openGL_loop() {
    //Test
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.0, 0.5);
    glEnd();
    

	//Use server to update display buffer
	//me_updateDisplay(ME_Video* video, uint8_t pageServer);
}

void display() {
	
    glClear(GL_COLOR_BUFFER_BIT);
    me_windows_openGL_loop();
    glFlush();
    
}

ME_Video * me_create_video(){
	//assert(subStub != NULL);
	ME_Video *  video = (ME_Video *) malloc(sizeof(ME_Video));
	if(NULL == video){
		perror("Cannot allocate video memory : me_init_video(ME_Video * video, ME_System * subStub)");
		exit(EXIT_FAILURE);
	}
	if (video->sys == NULL)
	{
		free(video);
	}else{
		fprintf(stdout, "%s\n", "Configuration video system");
	}
	// We use system configuration to make setting for video
	//subStub.setVideoState = ME_VIDEO_STATE_OK; // 1 for OK
	return video;
}

void me_configuration_init_video(ME_Video * video) {

	assert(video != NULL);
	/*paletteIdRequested = NO_PALETTE_CHANGE_REQUESTED;

	uint8_t* tmp = (uint8_t *)malloc(4 * VID_PAGE_SIZE);
	memset(tmp,0,4 * VID_PAGE_SIZE);
	
	for (int i = 0; i < 4; ++i) {
    //_pages[i] = tmp + i * VID_PAGE_SIZE;
	}*/
	int argc = 1;
	char fakeParam[] = "fake";
	char *fakeargv[] = { fakeParam, NULL };

	// INIT using OpenGL
	glutInit(&argc, fakeargv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("MirtilleVirtualMachine");
    glutDisplayFunc(display);
    glutMainLoop();
}

void * Screen(void * arg){
	ME_Video* video = (ME_Video *) arg;
	me_configuration_init_video(video);
}

void me_setDataBuffer(ME_Video * video, uint8_t *dataBuf, uint16_t offset) {
	assert(video != NULL);
	//dataBuf = dataBuf;
	//pData.pc = dataBuf + offset;
}


void me_readAndDrawDesigner(ME_Video* video, uint8_t color, uint16_t zoom, const Designer *ds) {
	assert(video != NULL);
	/*uint8_t i = _pData.fetchByte();

	//This is 
	if (i >= 0xC0) {	// 0xc0 = 192

		// WTF ?
		if (color & 0x80) {   //0x80 = 128 (1000 0000)
			color = i & 0x3F; //0x3F =  63 (0011 1111)   
		}

		// pc is misleading here since we are not reading bytecode but only
		// vertices informations.
		polygon.readVertices(_pData.pc, zoom);

		fillPolygon(color, zoom, pt);



	} else {
		i &= 0x3F;  //0x3F = 63
		if (i == 1) {
			warning("Video::readAndDrawPolygon() ec=0x%X (i != 2)", 0xF80);
		} else if (i == 2) {
			readAndDrawPolygonHierarchy(zoom, pt);

		} else {
			warning("Video::readAndDrawPolygon() ec=0x%X (i != 2)", 0xFBB);
		}
	}*/

}

void me_fillDesigner(ME_Video* video, uint16_t color, uint16_t zoom, const Designer *pt){
	assert(video != NULL);
}

void me_drawDesigner(ME_Video* video, uint8_t color, int16_t x, int16_t y){
	assert(video != NULL);
}


void me_readAndDrawDesignerHierarchy(ME_Video * video, uint16_t zoom, const Designer *ds) {
	assert(video != NULL);
	assert(ds != NULL);
}

uint8_t *me_getPage(ME_Video * video, uint8_t page) {
	assert(video != NULL);
	uint8_t *p;
	return p;
}

/*void me_updateDisplay(ME_Video* video, uint8_t page) {
	assert(video != NULL);*/
	//debug(ME_DBG_VIDEO, "Video::me_updateDisplay(%d)", bufferFront1);
/*
	if (page != 0xFE) {
		// S'il faut echanger les buffer: on le fait
		if (page == 0xFF) {
			me_SWAP(video->bufferSwap2, video->bufferFront1);
		} else {
			video->bufferFront1 = me_getPage(video->bufferBack3);
		}
	}
*/
	//Q: Why 160 ?
	//A: Because one byte gives two palette indices so
	//   we only need to move 320/2 per line.
  //video->sys->updateDisplay(bufferFront1);
//}

void me_saveOrLoad(ME_Video* video, ME_Serializer *ser) {
	assert(video != NULL);
	assert(ser != NULL);
}

static void * callback() {

}

