/*Cd takes in a current location as a string and returns a new path in the system*/
#include "cd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* cd(char *currLoc, char *newLoc){
	if(strcmp(newLoc, "\n")==0){//checks if an argument was passed
		return currLoc;
	}else if(strcmp(newLoc, "/")==0){//returns user to highest direcotry
		return "/";
	}else{//changes returns current location string with new string appended
		char * y;
		y = malloc(256);
		char x[256]; 
		strcpy(x, currLoc);
		strcat(x, newLoc);
		strcat(x, "/");
		strcpy(y, x);
		return(y);
	}
}
