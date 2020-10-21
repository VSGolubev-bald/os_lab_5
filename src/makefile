all: main

main: libarr.so dynamic.o static.o
	gcc -o static static.o -L. -larr -Wl,-rpath,.
	gcc -o dynamic dynamic.o -ldl

dynamic.o: dynamic.c
	gcc -c dynamic.c

static.o: static.c
	gcc -c static.c

libarr.so: APIarray.o
	gcc -shared -o libarr.so APIarray.o

arrayAPI.o : APIarray.c
	gcc -c -fPIC APIarray.c

clean:
	rm -f *.o *.so static dynamic
