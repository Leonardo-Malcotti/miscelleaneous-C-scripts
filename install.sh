#!/bin/bash

curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/advinstall.c >> advinstall.c
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/advrm.c >> advrm.c 
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/nprog.c >> nprog.c 
curl -fsSL https://raw.githubusercontent.com/Leonardo-Malcotti/miscelleaneous-C-scripts/master/utils.h >> utils.h 

gcc advinstall.c -o advinstall
./advinstall advrm.c 
./advinstall nprog.c 
./advinstall -self 

echo "per utilizzare gli script aggiungi /usr/local/bin al tuo path di sistema"

rm advinstall.c 
rm advrm.c 
rm nprog.c 
rm utils.h
rm advinstall

exit 0
