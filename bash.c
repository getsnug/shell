/*This is the main file of the project. This file contains the REPL loop.
REPL stands for Read, Evaluate, Print, Loop. The Loop function is called
within the main and is responsible for calling functions that read evaluate and print.*/
#include <string.h>
#include "ls.h"
#include "cd.h"
#include <stdio.h>
#include <stdlib.h>
#include "touch.h"
/*function declarations*/
char * cd();
void touch();
char curLoc[256] = "/"; //current location of the user
/*read reads in an input from the user and splits it up every whitespace*/
char ** read(){
    char inp[256];
    scanf("%[^\t\n]s", inp);//scans until whitespace that isn't a space
    char * str = strtok(inp, " ");//splits string up every space
    int space = 0, i;
    char ** out = NULL;//initializes output pointers
    /*This while loop splits up by every space so that the function returns
    a parsed string*/
    while(str){
	out = realloc(out, sizeof(char*)*++space);
	if(out==NULL) exit(-1);//FAIL
	out[space-1] = str;
	out[i++] = str;
	str = strtok(NULL, " ");
    }
    out=realloc(out, sizeof(char*)*(space+1));
    out[space] = 0;
    return out;
}
/*Execute takes in all of the arguments that are read by read and calls
the appropriate function*/
int execute(char ** argsIn){
   char args[256][256];//THIS LINE SHOULD DO NOTING BUT IF REMOVED THE COE BREAKS???
    if(strcmp(argsIn[0], "ls") ==  0){//Checks if the user wants ls
	if(argsIn[1]==NULL){//checks if ls has a path paramater, still needs actual parameters 
		ls(curLoc);
	}else{
		if(argsIn[1][0]=='-'){//checks if there is a param
			if(argsIn[2]!=NULL){
				ls(argsIn[1], argsIn[2]);
			}else{
				ls(argsIn[1], curLoc);
			}
		}
		else{// if no params it goes with the curLoc
			ls(curLoc, argsIn[1]);
		}
	}
    }
    else if(strcmp(argsIn[0], "cd") == 0){//cd function, currently throws a seg fault when run, likely the same one that touch throws
	//printf("%s", cd(curLoc, argsIn[1]));
	strcpy(curLoc, cd(curLoc, argsIn[1]));
	return(1);
    }
    else if(strcmp(argsIn[0], "pwd")==0){//creates a file currently throws a seg fault, likely the same as cd's
	printf("%s\n", curLoc);
	}
    else if(strcmp(argsIn[0], "touch")==0){//creates a file currently throws a seg fault, likely the same as cd's
	if(argsIn[1]!=NULL){//checks if filename is entered
	    touch(argsIn[1]);
	}else{
	    printf("%s", "you need to enter a filename");
	}
	return(1);
    }
    else{
        printf("command not found\n");
    }
    return(1);
}
/*main repl loop*/
void loop(void){
    char **line;
    int status = 1;
    do{
	printf("%s\n", "runing loop");
        printf("user@%s>\n", curLoc);
        line = read();
	status =  execute(line);//this line currently throws an error when execute returns a value greater than 0
    }while(status!=0);
}
int main(int argc, char** argv){
    loop();
    return 0;
}
