#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "source.h"

int SetSourceInfo(pSINFO psinfo,const char * srcDir){
	int nFile = 10;	
	strcpy(psinfo->dir,srcDir);
	psinfo->nFile = nFile;
	psinfo->height = 768;
	psinfo->width = 1024;
	psinfo->pics = 60;
	psinfo->fn = malloc(nFile*sizeof(psinfo->fn[250]));
	for(int i=0;i<nFile;i++){
		strcpy(*(psinfo->fn + i),srcDir);
		strcat(*(psinfo->fn + i),"/13");
		char num[3];
		sprintf(num,"%02d",i*5);
		strcat(*(psinfo->fn + i),num);
		strcat(*(psinfo->fn + i),".dat");
		
//		printf("%d : %s\n",i,*(psinfo->fn + i));	
	}
	return 0;
}


int SourceDir(const SINFO sinfo){
//	printf("...SourceDir...\n");
	for(int i=0;i<sinfo.nFile;i++)
		SourceFile(sinfo,i);
	return 0;
}


int SourceFile(const SINFO sinfo,int index){
	printf("...SourceFile...%d...\n",index);
	SRCHEAD srcHead;
	srcHead.head = 0x35;
	srcHead.pics = sinfo.pics;
	srcHead.width = sinfo.width;
	srcHead.height = sinfo.height;
	U8 * content;
	int len = sinfo.width * sinfo.height / 2;
	content = malloc(len);
	FILE *fid = fopen(*(sinfo.fn+index),"w");
	fwrite(&srcHead,1,sizeof(srcHead),fid);
	for(int i=0;i<sinfo.pics;i++){
		SetContent(sinfo,content);
		fwrite(content,1,len,fid);
		time_t now;
		time(&now);
		now += i; // for no same
		fwrite(&now,1,sizeof(now),fid);
	}
	free(content);
	fclose(fid);
	return 0;
}


int SetContent(const SINFO sinfo,U8 * content){

	int len = sinfo.width * sinfo.height /2 ;
	memset(content,0x30,len);	
	for(int i=0;i<len;i++)
		*(content+i) = (i & 0xff);

	return 0;
}



