#!/bin/bash
rm ./complete.asm

for file in operating_system/*.vm
do
<<<<<<< HEAD
	#printf "./VMtranslator ${file}\n"
=======
>>>>>>> 40e2b9f (First commit)
	./VMtranslator ${file}
done

for file in pong/*.vm
do
<<<<<<< HEAD
	#printf "./VMtranslator ${file}\n"
=======
>>>>>>> 40e2b9f (First commit)
	./VMtranslator ${file}
done

for file in operating_system/*.asm
do
<<<<<<< HEAD
	echo "${file}" >> ./complete.asm
=======
>>>>>>> 40e2b9f (First commit)
	cat ${file} >> ./complete.asm
done

for file in pong/*.asm
do
<<<<<<< HEAD
	echo "${file}" >> ./complete.asm
	cat ${file} >> ./complete.asm
done

line=$(cat ./complete.asm | wc -l)
printf "Linee tot: ${line}\n"
printf "Exeed: "
echo "${line} - 32767" | bc -l
=======
	cat ${file} >> ./complete.asm
done
>>>>>>> 40e2b9f (First commit)
