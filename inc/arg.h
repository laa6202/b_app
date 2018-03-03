#ifndef __ARG_H
#define __ARG_H

#include <time.h>

typedef unsigned char 	U8;
typedef unsigned short 	U16;
typedef unsigned int 		U32;

typedef struct {
	U8 head;
	U8 pics;
	U16 height;
	U16 width;
}	FHEAD,*pFHEAD;

typedef struct {
	time_t now;
} PTAIL,*pPTAIL;

typedef struct {
//	U16 bfType;		//write 2 bytes first in action
	U32 bfSize;
	U16 bfReversed1;
	U16 bfReversed2;
	U32	bfOffBits;
}	BMPFILEHEAD,*pBMPFILEHEAD;

	

int WriteBMPFileHead(FILE * fid,int height,int width);
int WriteBMPInfoHead(FILE * fid,int height,int width);
int WriteBMPRGBQUAD(FILE * fid);
int WriteBMPContent(FILE * fid,const char * content);



#endif

