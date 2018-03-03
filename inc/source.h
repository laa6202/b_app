#ifndef __SOURCE_H
#define __SOURCE_H

typedef unsigned char U8;
typedef unsigned short  U16;

typedef struct {
	char dir[250];
	int  nFile;
	int  height;
	int  width;
	int  pics;
	char (*fn)[250];
}SINFO,*pSINFO;

	
typedef struct {
	U8 head;
	U8 pics;
	U16 height;
	U16  width;
}SRCHEAD,*pSRCHEAD;

	
int SetSourceInfo(pSINFO psinfo,const char * srcDir);

int SourceDir(SINFO sinfo);
int SourceFile(SINFO sinfo,int index) ;
int SetContent(SINFO sinfo,U8 * content);


#endif

