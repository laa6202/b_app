#include <stdio.h>

#include "arg.h"

int WriteBMPFileHead(FILE * fid,int height,int width){
	BMPFILEHEAD bmpFileHead;
//	bmpFileHead.bfType = 0x4D42;
	U32 fileSize = 14;
	fileSize += 40;
	fileSize += (4*16);
	U32 headSize = fileSize;
	fileSize += (height * width /2);
	bmpFileHead.bfSize = fileSize;
	bmpFileHead.bfReversed1 =0;	
	bmpFileHead.bfReversed2 =0;
	bmpFileHead.bfOffBits=headSize;	
	fwrite(&bmpFileHead,1,sizeof(BMPFILEHEAD),fid);
	return 0;
}


int WriteBMPInfoHead(FILE * fid,int height,int width){
	BMPINFOHEAD bmpInfoHead;
	bmpInfoHead.biSize = 40;
	bmpInfoHead.biWidth = width;
	bmpInfoHead.biHeight = height;
	bmpInfoHead.biPlanes = 1;
	bmpInfoHead.biBitCount = 4;
	bmpInfoHead.biCompression = 0;
	bmpInfoHead.biSizeImage = height * width /2;
	bmpInfoHead.biXPelsPerMeter = 0xEC4;
	bmpInfoHead.biYPelsPerMeter = 0xEC4;
	bmpInfoHead.biClrUsed = 16;
	bmpInfoHead.biClrImportant = 16;
	fwrite(&bmpInfoHead,1,sizeof(BMPINFOHEAD),fid);
	return 0;
}


int WriteBMPRGBQUAD(FILE * fid){

	return 0;
}


int WriteBMPContent(FILE * fid,const char * content){

	return 0;
}


