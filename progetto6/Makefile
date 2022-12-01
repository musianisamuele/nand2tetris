DESTINATION=

all: global.h library.o main.o
	gcc -o VMtranslator library.o main.o

main.o: global.h main.c
	gcc -c main.c

library.o: global.h library.c
	gcc -c library.c
