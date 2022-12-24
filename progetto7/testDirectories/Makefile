all: main.o dir.o
	gcc -o main main.o dir.o

main.o: main.c global.h
	gcc -c main.c

dir.o: dir.c global.h
	gcc -c dir.c

clean:
	rm -f *.o

deb:
	gcc -o main -g main.c dir.c
