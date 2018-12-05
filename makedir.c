#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
void makedir(char* dirName, char* curLoc){
	strcat(curLoc, "/");
	mkdir(strcat(curLoc, dirName), S_IRWXU);	
}
