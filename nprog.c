#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"utils.h"

/*
strumento per la creazione di file con una struttura prefatta

feature:
- crea un progetto standard in base alle flag passate (indicano il linguaggio?)
- interpreta la struttura in base alla estensione
- se non ha la estensione la aggiunge in base alle flag passate
- permette di personalizzare le librerie inserite
- other tings?

utilizzo

nprog [tipo] nome[estensione] [flags]

*/

/*
typedef char* string;
typedef char bool;
enum boolean{false,true};
#define PROGNAME argv[0]
#define newstring(len) (char*)calloc(len,sizeof(char))
#define startWith(str,chr) (str[0]==chr)
#define isFlag(str) startWith(str,'-')
#define eql(str1,str2) (strcmp(str1,str2)==0)
*/
#define MAX_L_NAME 100

//enum e typedef format/s servono a 
//determinare che tipo di file creare
enum formats{nil,c,cpp};
typedef int format;
format ofFormat(string str);

FILE * createFile(string name, format f);

//TODO: permettere l'aggiunta di argomenti variabili
void writeC(FILE * f);

int main(int argc, string argv[]){

	if(argc==1){
		printf("%s: no argoument found\n", PROGNAME);
		exit(1);
	}

	int i;
	bool name_contr = true;
	format F = nil;
	string nomeFile = newstring(MAX_L_NAME);
	//errore se non ci sono argomenti
	
	/*
	Lettura argomenti
	*/

	for(i=1;i<argc;i++){

		if(isFlag(argv[i])){

			//l'unica flag che può essere prima 
			//del nome del file è il tipo di formato
			if(i==1){
				F = ofFormat(argv[i]);
			}
			//TODO
			//... ecc
		} else {
			if(name_contr){
				strcpy(nomeFile,argv[i]);
			} else {
				printf("%s: too many file names\n", PROGNAME);
				free(nomeFile);
				exit(1);
			}
		}

	}

	/*
	Crea il file
	*/

	FILE * nfile = createFile(nomeFile,F);
	free(nomeFile);
	if(nfile == NULL){
		printf("%s: failed to create file\n", PROGNAME);
		exit(1);
	}

	/*
	Scrive il contenuto
	*/

	switch(F){
		case c : writeC(nfile);break;
		case cpp : break;
		default : break;
	}

	fclose(nfile);
	return 0;
}

void writeC(FILE * f){
	string libs = "#include<stdlib.h>\n#include<string.h>\n#include<stdio.h>\n\n";
	string defines = "typedef char* string;\ntypedef char bool;\nenum boolean{false,true};\n#define PROGNAME argv[0]\n#define newstring(len) (char*)calloc(len,sizeof(char))\n#define startWith(str,chr) (str[0]==chr)\n\n";
	string mainF = "int main(int argc, string argv[]){\n\n	return 0;\n}\n\n";

	fprintf(f, "%s%s%s",libs,defines,mainF);
}

FILE * createFile(string name, format f){
	string fullName = newstring(strlen(name)+5);
	strcpy(fullName,name);

	switch(f){
		case c : strcat(fullName,".c");break;
		case cpp : strcat(fullName,".cpp");break;
		default : break;
	}

	FILE * ret = fopen(fullName,"w");
	free(fullName);

	return ret;
}


format ofFormat(string str){
	if(eql(str,"-c")){
		return c;
	}
	if(eql(str,"-cpp")){
		return cpp;
	}


	return nil;
}