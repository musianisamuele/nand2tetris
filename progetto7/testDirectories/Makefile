all: main.o dir.o list.o list.o
	gcc -o main main.o dir.o list.o

main.o: main.c global.h
	gcc -c main.c

dir.o: dir.c global.h
	gcc -c dir.c

list.o: list.c global.h
	gcc -c list.c

clean:
	rm -f *.o

deb:
	gcc -o main -g main.c dir.c list.c
