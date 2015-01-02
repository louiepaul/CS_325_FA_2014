CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=changegreedy changedp


all: $(PROGS)
	
	
#This program runs the changegreedy algorithm
changegreedy: changegreedy.o
	$(CC) $(CFLAGS) -o changegreedy changegreedy.o

changegreedy.o: changegreedy.c
	$(CC) $(CFLAGS) -c changegreedy.c	
	
#This program runs the changedp algorithm
changedp: changedp.o
	$(CC) $(CFLAGS) -o changedp changedp.o

changedp.o: changedp.c
	$(CC) $(CFLAGS) -c changedp.c	
	

	
clean:
	rm -f $(PROGS) *.o *~
