#!/bin/bash
rm ./complete.asm

for file in operating_system/*.vm
do
	./VMtranslator ${file}
done

for file in pong/*.vm
do
	./VMtranslator ${file}
done

for file in operating_system/*.asm
do
	cat ${file} >> ./complete.asm
done

for file in pong/*.asm
do
	cat ${file} >> ./complete.asm
done
