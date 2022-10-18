#!/bin/bash
for filename in ./progetto3/*.tst
do
	out="$(../nand2tetris/tools/HardwareSimulator.sh $filename)"
	
	echo $filename ": " $out
	
	counter=$((counter+1))
done

echo "Elementi confrontati:" $counter
