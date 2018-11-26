#include <stdio.h>
void touch(char * fName){
	printf("%s\n", fName);//test print statement delete later
	FILE *newFile;//creates pointer to the new file
	newFile = fopen(fName, "w");//opens the new file
	fprintf(newFile, " ");//writes a space to the new file, not sure if this is necessary
	fclose(newFile);//cleans up the file
}
