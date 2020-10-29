all:
	gcc -shared -fpic -o libshow.so show.c
	gcc -o main main.c ./libshow.so
clean:
	rm *.o *.so main a.out
