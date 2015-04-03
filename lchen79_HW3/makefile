part1.o: part1.c
	gcc -c part1.c

read_puzzle.o: read_puzzle.c color_demo.o color_demo.h
	gcc -c read_puzzle.c color_demo.o

color_demo.o: color_demo.c
	gcc -c color_demo.c

simpleio.o: simpleio.c
	gcc -c simpleio.c

wsearch: wsearch.c read_puzzle.o read_puzzle.h simpleio.o simpleio.h 
	gcc -o wsearch wsearch.c color_demo.o read_puzzle.o simpleio.o

