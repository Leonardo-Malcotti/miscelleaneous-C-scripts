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

//--------------------------------------------------------------------------------

#define MAX_L_NAME 100
#define MAX_EXT_LEN 5

//enum e typedef format/s servono a 
//determinare che tipo di file creare
enum formats{nil,c,cpp,tex,bash,h};
typedef int format;
format ofFormat(string str);
FILE * createFile(string name, format f);

//Modelli file da creare
//TODO: permettere l'aggiunta di argomenti variabili
void writeC(FILE * f);
void writeLaTex(FILE * f);
void writeBash(FILE * f); //lo so che è un po' inutile, ma mi dimentico sempre come si fa
void writeCpp(FILE * f);
void writeH(FILE * f, string name);

//--------------------------------------------------------------------------------

int main(int argc, string argv[]){

	if(argc==1){
		printf("%s: no argoument found\n", PROGNAME);
		exit(1);
	}

	int i;
	bool name_contr = true;
	format F = nil;
	string nomeFile = newstring(MAX_L_NAME);
	
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
	
	if(nfile == NULL){
		printf("%s: failed to create file\n", PROGNAME);
		free(nomeFile);
		exit(1);
	}

	/*
	Scrive il contenuto
	*/

	switch(F){
		case c : writeC(nfile);break;
		case cpp : writeCpp(nfile);break;
		case tex : writeLaTex(nfile);break;
		case bash : writeBash(nfile);break;
		case h : writeH(nfile,nomeFile);break;
		default : break;
	}

	free(nomeFile);
	fclose(nfile);
	return 0;
}

//--------------------------------------------------------------------------------


/*
Modello per i file latex
*/
void writeLaTex(FILE * f){
	fprintf(f, "\\documentclass[a4paper]{article}\n");
	fprintf(f, "\\usepackage[T1]{fontenc}\n");
	fprintf(f, "\\usepackage[utf8]{inputenc}\n");
	fprintf(f, "\\usepackage[italian]{babel}\n\n");
	fprintf(f, "\\begin{document}\n\n");
	fprintf(f, "\\end{document}\n");
}

/*
Modello per i file C
*/
void writeC(FILE * f){
	string libs = "#include<stdlib.h>\n#include<string.h>\n#include<stdio.h>\n\n";
	string mainF = "int main(int argc, char *argv[]){\n\n	return 0;\n}\n\n";

	fprintf(f, "%s%s",libs,mainF);
}

/*
Modello per i file Cpp
*/
void writeCpp(FILE * f){
	string libs = "#include<iostream>\n\nusing namespace std;\n\n";
	string mainF = "int main(int argc, cahr *argv[]){\n\n	return 0;\n}\n\n";

	fprintf(f, "%s%s",libs,mainF);
}

/*
"Modello" per uno script bash, lol
*/
void writeBash(FILE * f){
	fprintf(f, "#!/bin/bash\n\nexit 0\n");
}

/*
Modello per un header
*/
void writeH(FILE * f, string name){
	fprintf(f, "#ifndef __%s_H__\n",strToUpper(name));
	fprintf(f, "#define __%s_H__\n",strToUpper(name));
	fprintf(f, "\n\n#endif\n");
}

//---------------------------------------------------------------------------------


FILE * createFile(string name, format f){
	string fullName = newstring(strlen(name)+MAX_EXT_LEN);
	strcpy(fullName,name);

	switch(f){
		case c : strcat(fullName,".c");break;
		case cpp : strcat(fullName,".cpp");break;
		case tex : strcat(fullName,".tex");break;
		case bash : strcat(fullName,".sh");break;
		case h : strcat(fullName,".h");break;
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
	if(eql(str,"-tex")){
		return tex;
	}
	if(eql(str,"-bash")){
		return bash;
	}
	if(eql(str,"-h")){
		return h;
	}

	return nil;
}