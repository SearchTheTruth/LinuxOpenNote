main : foo1.o main.o foo2.o
	gcc -o main main.o foo1.o foo2.o

main.o : main.c
	@echo "main.c complie..."
	gcc -c main.c

foo1.o : foo1.c
	@echo "foo1.c complie..."
	gcc -c foo1.c

foo2.o : foo2.c
	@echo "foo2.c complie..."
	gcc -c foo2.c

clean:
	rm *.o main
