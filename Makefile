all: main

main: main.o strops.o
	gcc main.o strops.o -o main

main.o: main.c
	gcc -c main.c -o main.o

strops.o: strops.c
	gcc -c strops.c -o strops.o

clean:
	rm -f main *.o *~
