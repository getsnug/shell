#include "cd.h"
#include <stdio.h>
#include <string.h>
char* cd(char *currLoc, char *newLoc){
	printf("%s\n", newLoc);
	if(strcmp(newLoc, "\n")==0){//checks if an argument was passed
		return currLoc;
	}else if(strcmp(newLoc, "/")==0){//returns user to highest direcotry
		return "/";
	}else{//changes returns current location string with new string appended
		char * y;
		char x[256]; 
		strcpy(x, currLoc);
		strcat(x, newLoc);
		strcat(x, "/");
		printf("%s\n", x);
		strcpy(y, x);
		return(y);
	}
}