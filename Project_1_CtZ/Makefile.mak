#NAME: Ian Paul, Emma Paul, Abdulhalim Bambang
#EMAIL: pauli@onid.oregonstate.edu
#CLASS: CS325
#ASSIGNMENT: Project 1

CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=Alg1TestFile Alg2TestFile RandArraysAlg1 RandArraysAlg2


all: $(PROGS)
	
	
#This program runs the 1st Algorithm with the Arrays given	
Alg1TestFile: Alg1TestFile.o
	$(CC) $(CFLAGS) -o Alg1TestFile Alg1TestFile.o

Alg1TestFile.o: Alg1TestFile.c
	$(CC) $(CFLAGS) -c Alg1TestFile.c	
	
	
#This program runs the 2nd Algorithm with the Arrays given	
Alg2TestFile: Alg2TestFile.o
	$(CC) $(CFLAGS) -o Alg2TestFile Alg2TestFile.o

Alg2TestFile.o: Alg2TestFile.c
	$(CC) $(CFLAGS) -c Alg2TestFile.c
	
	
#This program runs the 1st Algorithm with randomly generated arrays	
RandArraysAlg1: RandArraysAlg1.o
	$(CC) $(CFLAGS) -o RandArraysAlg1 RandArraysAlg1.o

RandArraysAlg1.o: RandArraysAlg1.c
	$(CC) $(CFLAGS) -c RandArraysAlg1.c	

	
#This program runs the 1st Algorithm with randomly generated arrays	
RandArraysAlg2: RandArraysAlg2.o
	$(CC) $(CFLAGS) -o RandArraysAlg2 RandArraysAlg2.o

RandArraysAlg2.o: RandArraysAlg2.c
	$(CC) $(CFLAGS) -c RandArraysAlg2.c	

		
	
clean:
	rm -f $(PROGS) *.o *~
