/*
Project:	CS325 - Project 2
Section:	Algorithm 3
File:		Alg3Timing.c
Authors: 	Ian Paul, Emma Paul, Abdulhalim Bambang
*/
// ------------------------------------------------



#include <stdio.h>//
#include <stdlib.h>//
#include <string.h>//
#include <time.h>//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>




//static int array1[] = {360,-948,-29,447,515,-53,491,761,719,-854,77,-677,473,-262,95,844,84,875,241,-320,143,-888,-524,947,652,-260,-503,-882,-692,-223,-745,-245,37,387,-602,-862,-125,653,938,635,-960,375,-555,730,-198,-691,74,-336,112,62,-319,-877,416,646,207,616,608,-737,143,-747,387,788,105,258,408,517,451,-718,-358,-118,738,72,457,551,-726,580,297,-662,135,-220,-267,773,117,-669,905,152,789,-243,901,-241,-223,-380,668,514,-916,-723,957,-222,605,371};

//static int array2[] = {-536,565,-319,653,667,67,331,297,-688,-963,730,725,-298,21,-797,557,-286,-641,290,151,-271,534,730,-865,986,-4,984,-762,-792,-450,428,753,49,-245,-141,-710,-325,862,-294,859,-517,-911,-671,-223,-577,-778,-916,871,835,541,-986,-593,-913,357,358,478,-616,-958,440,-75,-155,-645,508,-29,715,275,-633,790,-441,-6,98,-232,78,-941,67,-29,539,791,-702,-81,-477,481,-978,-901,784,-563,-589,712,860,373,872,315,-13,-691,953,-602,-380,-834,-734,-778};

int i;
int j;
int sum; 
int arraySize;
int subArraySize;
int startPos;
int lowestSum = NULL;

int sum1, sum2;
int arraySize1, arraySize2, fullArraySize;
int subArraySize1, subArraySize2;
int startPos1, startPos2;
int y, z;

int array1FinalStartPos, array2FinalStartPos;
int array1FinalSize, array2FinalSize;

//variables for timing
time_t startTime;
time_t endTime;
double totalTime = 0;
double startTimer;
double endTimer;

//CHANGE THIS FOR TIMING TESTING
#define sizeToTest 100
#define halfSizeToTest 50//Must be half of sizeToTest



static int fullArray1[sizeToTest];

int sizeOfRandArray = sizeToTest;


int fullArraySize = sizeToTest;

arraySize1 = halfSizeToTest;
arraySize2 = halfSizeToTest;


static int array1Sums[halfSizeToTest];
static int array1SumsPos[halfSizeToTest];
static int array2Sums[halfSizeToTest];
static int array2SumsPos[halfSizeToTest];
static int array1[halfSizeToTest];
static int array2[halfSizeToTest];


int main(int argc, char *argv[])
{
	
	printf("Random Array size: %d \n\n", sizeOfRandArray);
	

	time_t t;
	srand((unsigned) time(&t));
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//random array generator		
					
	
	for (j = 0; j < fullArraySize; j++)
	{
		fullArray1[j] = rand() % 1999 + (-1000); //http://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c 
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}

	

arraySize1 = (sizeof(array1) / sizeof(array1[0]));
subArraySize1 = arraySize1;

arraySize2 = (sizeof(array2) / sizeof(array2[0]));
subArraySize2 = arraySize2;



startTimer = time(&startTime); //start timing 
clock_t tic = clock();
	
	
	
//Algorithm loops
///////////////////////////////////////////////////////


//getting sums
for (i = arraySize1; i > 0; i--)
{

	for (j = startPos1; j < subArraySize1; j++)
	{
		
		sum1 += array1[j];
		
	}

	startPos1++;
	//second array loops
			for (y = 0; y < arraySize2; y++)
				{		

					for (z = 0; z < subArraySize2; z++)
					{
						

						sum2 += array2[z];

					}
					sum = sum1+sum2;
					
							
				if (abs(sum) < lowestSum || lowestSum == NULL)
					{
						lowestSum = abs(sum);
					   
					   array1FinalStartPos = startPos1;
					   array1FinalSize = subArraySize1;
					   
					   array2FinalStartPos = 0;
					   array2FinalSize = subArraySize2;
					   
					}
					
					
					
					
					subArraySize2--;
					sum2 = 0;
				}	
	

	sum1 = 0;
	subArraySize2 = arraySize2;

}



///////////////////////////////////////////////////////
clock_t toc = clock(); //http://stackoverflow.com/questions/5248915/execution-time-of-c-program

printf("[");
for (i = 0; i < arraySize1; i++)
{
	printf("%d", array1[i]);
		if (i < arraySize1-1)
		{
			printf(", ");
		}
}
printf("], ");

printf("[");
for (i = 0; i < arraySize2; i++)
{
	printf("%d", array2[i]);
		if (i < arraySize2-1)
		{
			printf(", ");
		}
}
printf("], ");




sum1 = 0;
sum2 = 0;		
lowestSum = 0; 

		//printf("(");
		printf("[");
		for (z = array1FinalStartPos -1; z < array1FinalSize; z++)
		{
			printf("%d", array1[z]);
			sum1 += array1[z];
			if (z < array1FinalSize-1)
			{
				printf(", ");
			}
		}
		printf("], ");


		printf("[");
		for (z = 0; z <= array2FinalSize -1; z++)
		{
			printf("%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize -1)
			{
				printf(", ");
			}
		}
		printf("], ");
		

		
		lowestSum = sum1+sum2;
		
		printf("%d\n", lowestSum);
printf("\nTotal time to complete: %f seconds\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);


return 0;
}