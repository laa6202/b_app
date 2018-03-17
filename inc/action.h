#ifndef __ACTION_H
#define __ACTION_H

#include <time.h>

int Action(char * dstDir,char *srcDir);
int GetDir(int argv,char **argc,char * dstDir,char * srcDir,int * bSource);
int ActionPreSrcFn(char * dstDir,const char * srcAbsFn,const char * srcFn);
int ActionFrame(unsigned char* ,int ,int ,const char * ,const char *,const char * );
int CorrectStNow(char *);


#endif

