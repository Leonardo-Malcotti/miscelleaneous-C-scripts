# miscelleaneous C scripts

Un vario insieme di programmi C più o meno utili che punta alla automazione di azioni comuni

### Install

#### Script

Utilizza il seguente comando per scaricare e avviare lo script di installazione. 

```bash
sudo /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/install.sh)"
```

#### Clone

Per compilare da solo gli script clona la repo.
Per la compilazione è consigliato di utilizzare advinstall:

```bash
gcc advinstall.c -o advinstall ; ./advinstall -self
```

## Advinstall

Advanced Install

strumento per l'installazione di binari.

feature:
- copia i binari indicati nella cartella /usr/local/bin (standard)
- permette di specificare un persorso diverso con -p , -path (not supported yet)
- se gli viene passato un file sorgente lo compila (supporto principale per c e swift, file senza dipendenze)
- permette di specificare il compilatore con -c (not supported yet)
- installa se stesso con -self
- flag -v per verbose (not supported yet)

utilizzo

advinstall [-p|-c|-v][arg flag][binaries...] | -self


## Advrm

Advanced Remove

strumento per la rimozione di binari.

feature:
- esegue rm del binario indicato in /usr/local/bin
- mostra i binari installati (not supported yet)

utilizzo

advrm binario


## Nprog

New Program

strumento per la creazione di file con una struttura prefatta.

feature:
- crea un progetto standard in base alle flag passate
- interpreta la struttura in base alla estensione (not supported yet)
- se non ha la estensione la aggiunge in base alle flag passate
- permette di personalizzare le librerie inserite (not supported yet)

utilizzo

nprog [tipo] nome[estensione] [flags]


## utils.h

Header contenente alcune macro e costanti utili.

