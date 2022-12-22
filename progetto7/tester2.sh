#!/bin/bash

for file in operating_system/*.vm
do
	grep -o -i push ${file} | wc -l
	grep -o -i pop ${file} | wc -l
done

for file in pong/*.vm
do
	grep -o -i push ${file} | wc -l
	grep -o -i pop ${file} | wc -l
done
