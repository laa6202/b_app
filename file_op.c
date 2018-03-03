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
	//	printf("build dir : %s \n",dir);
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
//		printf("No Next Src File Exist.\n");
		return -1;
	}

	while(strncmp(ptrDir->d_name,".",1) == 0){
		ptrDir = readdir(dirid);
	}

	if(ptrDir == NULL){
//		printf("No Next Src File Exist.\n");
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




