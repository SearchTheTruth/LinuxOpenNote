all :
	gcc main.c add.c sub.c -o nolib
	gcc -c add.c sub.c
	ar rcs libmymath.a add.o sub.o
	gcc main.c libmymath.a -o uselib
clean :
	rm *.o *.a
