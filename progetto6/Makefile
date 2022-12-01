DESTINATION=

all: global.h library.o list.o main.o
	gcc -o VMtranslator library.o list.o main.o

main.o: global.h main.c
	gcc -c main.c

library.o: global.h library.c
	gcc -c library.c

list.o: global.h list.c
	gcc -c list.c

clean:
	rm -f *.o

deb:
	gcc -g -o VMtranslator library.c main.c
