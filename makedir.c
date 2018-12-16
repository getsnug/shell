/*This is the mkdir function which should make a directory, however it does not work well now*/
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
void makedir(char* dirName, char* curLoc){
	strcat(curLoc, "/");//appends / so that the directory can be made at the proper path
	mkdir(strcat(curLoc, dirName), S_IRWXU);//makes the directory
}
