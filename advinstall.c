#include<stdlib.h>
#include<string.h>
#include<stdio.h>
/*
strumento per l'installazione di binari avanzato

feature:
- copia i binari indicati nella cartella /usr/local/bin (standard)
- permette di specificare un persorso diverso con -p , -path
- se gli viene passato un file sorgente lo compila (supporto principale per c e swift, file senza dipendenze)
- permette di specificare il compilatore con -c 
- installa se stesso con -self
una versione verbose sarebbe utile

utilizzo

advanced binary install advinstall

advinstall [-p|-c][arg flag][binaries...]
*/

#define STD_PATH "/usr/local/bin"
#define C_COMPILER "gcc"
#define SWIFT_COMPILER "swiftc"
#define PROGNAME argv[0]
typedef char* string;
typedef char bool;
enum boolean{false,true};

#define newstring(len) (char*)calloc(len,sizeof(char))

/*wrapper per il comando install.          */
/*  bin : il nome del file.                */
/*  path : il percorso in cui installarlo. */
int install (string bin, string path);

/*esegue il comando di compilazione adeguato*/
/*basandosi sulla estensione passata per arg*/
/*  src : il nome del file                  */
/*  ext : la estensione del file            */
string compile (string src, string ext);

/*wrapper per rm*/
int remove(string bin);

int main(int argc, string argv[]){

	/*TODO: lettura argomenti*/

	/*TODO: gestione di più file di input (multithread)*/
	/*
	while((argv--)>=0){
		fork ecc
	}*/

	string bin;

	/*flag -self, autoinstallazione*/
	if(strcmp(argv[1],"-self")==0){
		bin = newstring(12);
		strcpy(bin,"advinstall.c");
	} else {
		bin = newstring(strlen(argv[1]));
		strcpy(bin,argv[1]);
	}
	
	/*compilazione automatica*/
	string ext = strrchr(bin,'.');
	if(ext!=NULL){

		strcpy(bin,compile(bin,ext));
		if(bin==NULL){
			fprintf(stderr, "%s : fallita la compilazione di %s\n",PROGNAME,argv[1]);
			exit(1);
		}
	}

	/*installazione*/

	int ret = install(bin,STD_PATH);
	//cancella il binario creato temporanemente
	ret += remove(bin);
	return ret;
};

int remove(string bin){
	string command = newstring(9+strlen(bin));
	strcpy(command,"sudo rm ");
	strcat(command, bin);
	int ret = system(command);
	free(command);
	return ret;
}

int install(string bin, string path){
	string command = newstring(15+strlen(bin)+strlen(path));
	strcpy(command,"sudo install ");
	strcat(command, bin);
	strcat(command, " ");
	strcat(command, path);
	int ret = system(command);
	free(command);
	return ret;
}

string compile (string src, string ext){
	string command;
	string bin = newstring(strlen(src)-strlen(ext));
	strncpy(bin,src,strlen(src)-strlen(ext));
	if (strcmp(ext,".c")==0){
		command = newstring(8+strlen(src)+strlen(bin));
		strcpy(command,"gcc -o ");
		strcat(command,bin);
		strcat(command," ");
		strcat(command,src);
		if(system(command)<0){
			bin = NULL;
		}
		free(command);
	}

	return bin;
}






