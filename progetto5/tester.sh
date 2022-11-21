#/bin/bash!

rm asm/*.hack

for entry in asm/*
do
	./assembler $entry
	echo "./assembler $entry"
done

mv asm/*.hack hack/

for entry in asm/*
do
	../../tools/Assembler.sh $entry
	echo "../../tools/Assembler.sh $entry"
done

cd asm/

for entry in *.hack
do
	echo "diff ../hack/$entry $entry"
	diff ../hack/$entry $entry
done

