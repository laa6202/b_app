#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include "file_op.h"

int MakeDir(const char * dir){
	DIR * dirid;
	dirid = opendir(dir);
	if(dirid ==NULL){
		mkdir(dir,0775);
		printf("%s Not Exist,build it. \n",dir);
	}		
	else{ 
	//	printf("dirid != NULL\n");
	}
	return 0;
}




int GetSrcFn(char * absFn,char * fn,const char * dir,long int * offset){
	memset(fn,0,250);
	DIR * dirid;
	dirid = opendir(dir);
	if(dirid == NULL){
		printf("Error! Src Dir is NOT exist.\n");
		exit(-1);
	}
	seekdir(dirid,*offset);
	
	struct dirent *ptrDir;
	ptrDir = readdir(dirid);
	if(ptrDir == NULL){
		printf("No Src File Exist.\n");
		return -1;
	}
	while(strncmp(ptrDir->d_name,".",1) == 0){
		printf("%s\n",ptrDir->d_name);
		ptrDir = readdir(dirid);
		if(ptrDir == NULL){
			printf("No File Exist after . or ..  \n");
			return -1;
		}
	}
	if(ptrDir == NULL){
		printf("No Next Src File Exist.\n");
		return -1;
	}
	*offset = telldir(dirid);
	strcpy(absFn,dir);
	strcat(absFn,"/");
	strcat(absFn,ptrDir->d_name);
	strcpy(fn,ptrDir->d_name);
//	printf("GetSrcFn file name = %s\n",ptrDir->d_name);
	closedir(dirid);
	return 0;
}


int GetDstFn(char * dstAbsFn,const char * dstDir,const char * stNow,const char * srcFn){
//	printf("st_now = %s\n",stNow);
	strcpy(dstAbsFn,dstDir);
	strcat(dstAbsFn,"/");
	strcat(dstAbsFn,stNow);
	strcat(dstAbsFn,srcFn);
	strcat(dstAbsFn,".bmp");
//	printf("dstAbsFn = %s\n",dstAbsFn);
	return 0;
}

 

