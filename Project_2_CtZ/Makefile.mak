#NAME: Ian Paul, Emma Paul, Abdulhalim Bambang
#EMAIL: pauli@onid.oregonstate.edu
#CLASS: CS325
#ASSIGNMENT: Project 2

CC=gcc
DEBUG=-g
CFLAGS=$(DEBUG) -Wall
PROGS=Alg1 Alg2 Alg3 Alg4 Alg1Timing Alg2Timing Alg3Timing Alg4Timing Alg3Input Alg4Input


all: $(PROGS)
	
	
#This program runs the 1st Algorithm with the Arrays given	
Alg1: Alg1.o
	$(CC) $(CFLAGS) -o Alg1 Alg1.o

Alg1.o: Alg1.c
	$(CC) $(CFLAGS) -c Alg1.c	
	
	
#This program runs the 2nd Algorithm with the Arrays given	
Alg2: Alg2.o
	$(CC) $(CFLAGS) -o Alg2 Alg2.o

Alg2.o: Alg2.c
	$(CC) $(CFLAGS) -c Alg2.c
	
	
#This program runs the 3rd Algorithm with the Arrays given	
Alg3: Alg3.o
	$(CC) $(CFLAGS) -o Alg3 Alg3.o

Alg3.o: Alg3.c
	$(CC) $(CFLAGS) -c Alg3.c
	
#This program runs the 4th Algorithm with the Arrays given	
Alg4: Alg4.o
	$(CC) $(CFLAGS) -o Alg4 Alg4.o

Alg4.o: Alg4.c
	$(CC) $(CFLAGS) -c Alg4.c
	
#This program runs the 1st Algorithm with randomly generated arrays	
Alg1Timing: Alg1Timing.o
	$(CC) $(CFLAGS) -o Alg1Timing Alg1Timing.o

Alg1Timing.o: Alg1Timing.c
	$(CC) $(CFLAGS) -c Alg1Timing.c
	
#This program runs the 2nd Algorithm with randomly generated arrays	
Alg2Timing: Alg2Timing.o
	$(CC) $(CFLAGS) -o Alg2Timing Alg2Timing.o

Alg2Timing.o: Alg2Timing.c
	$(CC) $(CFLAGS) -c Alg2Timing.c
	
#This program runs the 3rd Algorithm with randomly generated arrays	
Alg3Timing: Alg3Timing.o
	$(CC) $(CFLAGS) -o Alg3Timing Alg3Timing.o

Alg3Timing.o: Alg3Timing.c
	$(CC) $(CFLAGS) -c Alg3Timing.c
	
#This program runs the 4th Algorithm with randomly generated arrays	
Alg4Timing: Alg4Timing.o
	$(CC) $(CFLAGS) -o Alg4Timing Alg4Timing.o

Alg4Timing.o: Alg4Timing.c
	$(CC) $(CFLAGS) -c Alg4Timing.c
	
	
#Alg 3 for Output
Alg3Input: Alg3Input.o
	$(CC) $(CFLAGS) -o Alg3Input Alg3Input.o

Alg3Input.o: Alg3Input.c
	$(CC) $(CFLAGS) -c Alg3Input.c

#Alg 4 for Output
Alg4Input: Alg4Input.o
	$(CC) $(CFLAGS) -o Alg4Input Alg4Input.o

Alg4Input.o: Alg4Input.c
	$(CC) $(CFLAGS) -c Alg4Input.c
		
	
clean:
	rm -f $(PROGS) *.o *~
