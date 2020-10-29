all:
	gcc -E hello.c -o hello.i
	gcc -S hello.i -O0 -o hello.s
	gcc -c hello.s -o hello.o
	gcc hello.o -o hello

clean:
	rm hello.i hello.s hello.o hello

