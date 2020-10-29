all:
	gcc -shared -fpic -o libshow.so show.c
	gcc -rdynamic -o main main.c -ldl
clean:
	rm *.o *.so main a.out
