#makefile che serve per rendere più veloce la compilazione

main=main
out=assembler

all: ${main}.o library.o list.o predefined.o string.o
	@gcc -o ${out} ${main}.o library.o list.o predefined.o string.o library.h

${main}.o: ${main}.c library.h
	@gcc -c ${main}.c

library.o: library.c library.h
	@gcc -c library.c

list.o: list.c library.h
	@gcc -c list.c

predefined.o: predefined.c library.h
	@gcc -c predefined.c

string.o: string.c library.h
	@gcc -c string.c

clean:
	@rm -f *.o

deb:
	@gcc library.h library.c list.c predefined.c string.c main.c -g -o assembler
