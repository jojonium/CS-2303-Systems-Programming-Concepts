CFLAGS = -Wall

life: life.o board.o
	gcc $(CFLAGS) life.o board.o -o life -lm

life.o: life.c board.h
	gcc $(CFLAGS) -c life.c -o life.o

board.o: board.c
	gcc $(CFLAGS) -c board.c -o board.o

clean:
	rm -f board.o life.o life
