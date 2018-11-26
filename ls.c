#include "ls.h"
#include <stdio.h>
#include <dirent.h>
#include <string.h>
/*ls function, takes in an argument parameters and an argument loc*/
char * ls(char * params, char * loc){
  //if(strcmp(params[1],'a')==0){
//	all = true;
  //}
  DIR *dir;
  struct dirent *ent;
  if ((dir = opendir (loc)) != NULL) {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL) {//iterates through every item in loc
      	if(ent->d_name[0]!='.'){//checks to see if item ought to be ignored
      		printf ("%s\n", ent->d_name);//prints item + newline
	}
    }
    closedir (dir);//cleans up
  } else {
    /* could not open directory */
    perror ("");
    return "EXIT_FAILURE";
  }
}
