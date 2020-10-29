all:
	gcc -o main main.c
	gcc -shared -fpic -o libmymalloc.so mymalloc.c -ldl
	@echo "\nHow To Use\n LD_PRELOAD=\"./libmymalloc.so\" ./main"
clean:
	rm *.o a.out main *.so
