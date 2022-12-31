
all: global.h library.o list.o string.o translater.o dir.o function_organizer.o main.o
	gcc -o VMtranslator library.o list.o string.o translater.o dir.o function_organizer.o main.o

main.o: global.h main.c
	gcc -c main.c

library.o: global.h library.c
	gcc -c library.c

list.o: global.h list.c
	gcc -c list.c

string.o: global.h string.c
	gcc -c string.c

translater.o: global.h translater.c
	gcc -c translater.c

dir.o: global.h dir.c
	gcc -c dir.c

function_organizer.o: global.h function_organizer.c
	gcc -c function_organizer.c

clean:
	rm -f *.o

deb:
	gcc -g -o VMtranslator library.c list.c string.c translater.c main.c
