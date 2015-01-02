CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall -lm
PROGS=tsp_final


all: $(PROGS)
		
tsp_final: tsp_final.o
	$(CC) $(CFLAGS) -o tsp_final tsp_final.o

tsp_final.o: tsp_final.c
	$(CC) $(CFLAGS) -c tsp_final.c	
		
clean:
	rm -f $(PROGS) *.o *~
