#!/bin/bash
rm test_files/*.asm

for file in test_files/*.vm
do
	./VMtranslator ${file}
done

for file in test_files/*.tst
do
	printf "\nComparazione di ${file}\n"
	../../tools/CPUEmulator.sh ${file}
done
