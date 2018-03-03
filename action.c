//action.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "action.h"
#include "file_op.h"
#include "arg.h"

int GetDir(int argv,char **argc,char * dstDir,char * srcDir){
//	printf("argv = %d\n",argv);
//	printf("argc[0] = %s\n",argc[0]);
	if(argv == 1){
		printf("Error : lost parameter for src and dst Dir!\n");
		printf("Usage : ./b_app srcDir dstDir\n");
		exit(-1);
	}		
	if(argv >= 2){
		getcwd(srcDir,250);
		strcat(srcDir,"/");
		strcat(srcDir,argc[1]);
		strcpy(dstDir,srcDir);
		strcat(dstDir,"_out");
		printf("srcDir = %s\n",srcDir);
		printf("dstDir = %s\n",dstDir);
	}
	if(argv >= 3){
		getcwd(dstDir,250);
		strcat(dstDir,"/");
		strcat(dstDir,argc[2]);
		printf("dstDir = %s\n",dstDir);
	}
	MakeDir(srcDir);
	MakeDir(dstDir);
	return 0;
}



int Action(char * dstDir,char * srcDir){
	printf("...action...%s...\n",dstDir);
	char srcFn[250];
	char srcAbsFn[250];
	long int offset=0;	
	int nfExist = 0;
	int i=0;
	do{
		i++;
		printf("Src File %d:\n",i);
		nfExist = GetSrcFn(srcAbsFn,srcFn,srcDir,&offset);
		if(nfExist != 0)
			break;
		ActionPreSrcFn(dstDir,srcAbsFn,srcFn);
	}while(nfExist==0);
	
	printf("done\n");
	
	return 0;
}


int ActionPreSrcFn(char * dstDir, const char * srcAbsFn,const char * srcFn){
	printf("ActionPreSrcFn=%s  ",srcAbsFn);
	FILE * fid = fopen(srcAbsFn,"r");
	unsigned char head;
	fread(&head,1,sizeof(head),fid);
	unsigned char pics;
	fread(&pics,1,sizeof(pics),fid);
	unsigned short height;
	unsigned short width;
	fread(&height,1,sizeof(height),fid);
	fread(&width,1,sizeof(width),fid);
	printf("p=%d  ",pics);
	printf("w=%d  ",width);
	printf("h=%d\n",height);
	int len = height * width /2; 
	unsigned char content[len];
	time_t stamp;
	for(int i=0;i<pics;i++){
		fread(content,1,len,fid);
		fread(&stamp,1,sizeof(stamp),fid);
//		if(i<2)	//only handle first 2 frame
		ActionFrame(content,height,width,stamp,dstDir,srcFn);
	}
	fclose(fid);
	return 0;
}


int ActionFrame(unsigned char * content,int height,int width,time_t stamp,const char * dstDir,const char * srcFn){
//	printf("ActionFrame:%ld\t%s\n",stamp,srcFn);
	char dstAbsFn[250];
	GetDstFn(dstAbsFn,dstDir,stamp,srcFn);
	FILE * fid = fopen(dstAbsFn,"wb");
	U16 bm = 0x4D42;
	fwrite(&bm,1,sizeof(U16),fid);
	WriteBMPFileHead(fid,height,width);
	WriteBMPInfoHead(fid,height,width);
	WriteBMPRGBQUAD(fid);
	WriteBMPContent(fid,content,width*height/2);
	fclose(fid);	
	return 0;
}




