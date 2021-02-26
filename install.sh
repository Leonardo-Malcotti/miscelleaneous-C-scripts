#!/bin/bash

#check OS
OS="$(uname)"
if [[ "$OS" == "Darwin" ]]; then
	abort "Only MacOS (maybe linux) is supported."
fi

#check for curl and gcc
if ! command -v curl >/dev/null; then
    abort "You must have cURL installed to continue."
fi

if ! command -v gcc >/dev/null; then
    abort "You must have a C compiler (gcc) installed to continue."
fi

#download files
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/advinstall.c >> advinstall.c
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/advrm.c >> advrm.c 
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/nprog.c >> nprog.c 
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/utils.h >> utils.h 

#compile and install
gcc advinstall.c -o advinstall
./advinstall advrm.c 
./advinstall nprog.c 
./advinstall -self 

echo "per utilizzare gli script aggiungi /usr/local/bin al tuo path di sistema"

#clean
rm advinstall.c 
rm advrm.c 
rm nprog.c 
rm utils.h

exit 0
