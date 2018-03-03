#include <stdio.h>

#include "arg.h"

int WriteBMPFileHead(FILE * fid,int height,int width){
	BMPFILEHEAD bmpFileHead;
//	bmpFileHead.bfType = 0x3435;
	bmpFileHead.bfSize = 0x36373839;
	bmpFileHead.bfReversed1 =0;	
	bmpFileHead.bfReversed2 =0;	
	fwrite(&bmpFileHead,1,sizeof(BMPFILEHEAD),fid);
	return 0;
}


int WriteBMPInfoHead(FILE * fid,int height,int width){

	return 0;
}


int WriteBMPRGBQUAD(FILE * fid){

	return 0;
}


int WriteBMPContent(FILE * fid,const char * content){

	return 0;
}


