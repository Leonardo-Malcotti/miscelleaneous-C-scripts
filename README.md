# miscelleaneous C scripts

Un vario insieme di programmi C più o meno utili che punta alla automazione di azioni comuni

### Install

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/install.sh)"
```


## Advinstall

Advanced Install

strumento per l'installazione di binari

feature:
- copia i binari indicati nella cartella /usr/local/bin (standard)
- permette di specificare un persorso diverso con -p , -path
- se gli viene passato un file sorgente lo compila (supporto principale per c e swift, file senza dipendenze)
- permette di specificare il compilatore con -c 
- installa se stesso con -self
una versione verbose sarebbe utile

utilizzo

advinstall [-p|-c][arg flag][binaries...]

## Advrm

Advanced Remove

strumento per la rimozione di binari avanzato

feature:
- esegue rm del binario indicato in /usr/local/bin
- mostra i binari installati ? (-list?)

usage:

advrm [flag?] binario

## Nprog

New Program

strumento per la creazione di file con una struttura prefatta

feature:
- crea un progetto standard in base alle flag passate (indicano il linguaggio?)
- interpreta la struttura in base alla estensione
- se non ha la estensione la aggiunge in base alle flag passate
- permette di personalizzare le librerie inserite
- other tings?

utilizzo

nprog [tipo] nome[estensione] [flags]

## utils.h

Header contenente alcune macro e costanti utili.

