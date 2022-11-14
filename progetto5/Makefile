#makefile che serve per rendere più veloce la compilazione

main=main
out=assembler

all: ${main}.o library.o
	@gcc -o ${out} ${main}.o library.o library.h

${main}.o: ${main}.c library.h
	@gcc -c ${main}.c

library.o: library.c library.h
	@gcc -c library.c

clean:
	@rm -f *.o
