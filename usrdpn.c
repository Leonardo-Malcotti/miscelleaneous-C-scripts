#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"utils.h"

/*
Tool per la risoluzione di dipendenze di file sorgente (principalmente c)

feature:
- legge gli include del file e cerca di risolvere le dipendenze per le librerie mancanti
- può basarsi su un file dpn di input
- utilizza curl per scaricare i .h e .c necessari da github
- se la librerie è già nel percorso del codice sorgente non fa nulla

funzionamento:
utilizza un file index per tenere in memoria i nomi e gli url dei .h e .c
legge tutti gli inlcude del file tenendo in memoria quelli definiti dall'utente
controlla se ha un metch nel suo index:
se c'è e il file esiste già non fa nulla, se no li scarica con curl e li salva nel percorso del sorgente
se non c'è ritorna errore e chiede all'utente se può fornire un url:
se non lo fornisce non fa nulla
se lo fornisce lo salva nell'index e scarica il file

utilizzo:

usrdpn nomefile.c
*/


int main(int argc, string argv[]){

	if(argc==1){
		printf("%s: no argoument found\n", PROGNAME);
		exit(1);
	}

	FILE src * = fopen(argv[1],"r");






	
	return 0;
}

