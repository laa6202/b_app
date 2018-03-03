#include <stdio.h>

#include "action.h"
#include "source.h"


int main(int argv,char **argc){
	char srcDir[250];
	char dstDir[250];
	GetDir(argv,argc,dstDir,srcDir);

	SINFO sinfo;
	SetSourceInfo(&sinfo,srcDir);
	SourceDir(sinfo);

	Action(dstDir,srcDir);

	return 0;
}
