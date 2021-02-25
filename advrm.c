#include<stdlib.h>
#include<string.h>
#include"utils.h"
/*
strumento per la rimozione di binari avanzato

feature:
- esegue rm del binario indicato in /usr/local/bin
- mostra i binari installati ? (-list?)

usage:

advrm [flag?] binario
*/


#define STD_PATH "/usr/local/bin"
#define C_COMPILER "gcc"
#define SWIFT_COMPILER "swiftc"


#define newstring(len) (char*)calloc(len,sizeof(char))

int f_remove(string bin, string path);

int main(int argc, string argv[]){

	int ret = f_remove(argv[1],STD_PATH);

	return ret;
}

int f_remove(string bin, string path){
	string command = newstring(9+strlen(bin)+strlen(path));
	strcpy(command,"sudo rm ");
	strcat(command, path);
	strcat(command, "/");
	strcat(command, bin);
	int ret = system(command);
	free(command);
	return ret;
}
