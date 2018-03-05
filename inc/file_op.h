#ifndef __FILE_OP_H
#define __FILE_OP_H

#include <time.h>

int MakeDir(const char * dir);
int GetSrcFn(char * absFn,char * fn,const char * dir,long int *  offset);
int GetDstFn(char * fn,const char * dir,const char * now,const char * srcFn);


#endif
