all:
	gcc -c mymalloc.c main.c
	gcc -Wl,--wrap,malloc -Wl,--wrap,free -o main main.o mymalloc.o
clean:
	rm *.o a.out main
