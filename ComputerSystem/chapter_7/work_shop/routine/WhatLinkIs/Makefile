cmd:
	@echo " nolink\n linkmain linkstr merge\n clean"

nolink:
	gcc -o nolink no_link.c

linkmain:
	gcc -o linkmain.o -c link_part1_main.c

linkstr:
	gcc -o linkstr.o -c link_part2_str.c

merge:
	gcc -o link linkmain.o linkstr.o

clean:
	rm *.o link nolink

