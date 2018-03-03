#ifndef __ARG_H
#define __ARG_H

#include <time.h>

typedef unsigned char U8;
typedef unsigned short U16;

typedef struct {
	U8 head;
	U8 pics;
	U16 height;
	U16 width;
}	FHEAD,*pFHEAD;

typedef struct {
	time_t now;
} PTAIL,*pPTAIL;


#endif

