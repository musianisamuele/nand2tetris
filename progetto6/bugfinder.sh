#!/bin/bash

#Usando tester.sh scopro quali file non funzionano piu'.
#Questo script prende in input il nome di un file, lo traduce con il VMtranslator
#nuovo e il VMtranslator vecchio (che funziona) e fa la differenza tra i file per vedere
#dove sono gli errori

file=$1

./VMtranslator_working ${file}.vm
mv ${file}.asm ${file}_working.asm

./VMtranslator ${file}.vm

diff ${file}.asm ${file}_working.asm

rm ${file}_working.asm


