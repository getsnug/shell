#include <string.h>
#include "ls.h"
#include "cd.h"
#include <stdio.h>
#include <stdlib.h>
#include "touch.h"
/*function declarations*/
char * cd();
void touch();
char * curLoc = "/"; //current location of the user
/*read reads in an input from the user and splits it up every whitespace*/
char ** read(){
    char inp[256];
    scanf("%[^\t\n]s", inp);//scans until whitespace that isn't a space
    char * str = strtok(inp, " ");//splits string up every space
    int space = 0, i;
    char ** out = NULL;//initializes output pointers
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

int execute(char ** argsIn){
   char args[256][256];//THIS LINE SHOULD DO NOTING BUT IF REMOVED THE COE BREAKS???
    if(strcmp(argsIn[0], "ls") ==  0){
	if(argsIn[1]==NULL){//checks if ls has a path paramater, still needs actual parameters 
		ls(curLoc);
	}else{
		if(argsIn[1][0]=='-'){
			if(argsIn[2]!=NULL){
				ls(argsIn[1], argsIn[2]);
			}else{
				ls(argsIn[1], curLoc);
			}
		}
		else{
			ls("r", argsIn[1]);
			}
	}
    }
    else if(strcmp(argsIn[0], "cd") == 0){//cd function, currently throws a seg fault when run, likely the same one that touch throws
	//printf("%s", cd(curLoc, argsIn[1]));
	curLoc = cd(curLoc, "20");
	return(0);
    }
    else if(strcmp(argsIn[0], "pwd")==0){//creates a file currently throws a seg fault, likely the same as cd's
	printf("%s\n", curLoc);
	}
    else if(strcmp(argsIn[0], "touch")==0){//creates a file currently throws a seg fault, likely the same as cd's
	if(argsIn[1]!=NULL){//checks if filename is entered
		printf("%s", "test");
	    touch(argsIn[1]);
	}else{
	    printf("%s", "you need to enter a filename");
	}
	return(0);
    }
    else{
        printf("command not found\n");
    }
    return(0);
}
/*main repl loop*/
void loop(void){
    char **line;
    int status = 1;
    do{
        printf("user@%s>", curLoc);
        line = read();
	status =  execute(line);//this line currently throws an error when execute returns a value greater than 0
    }while(status);
}
int main(int argc, char** argv){
    loop();
    return 0;
}
