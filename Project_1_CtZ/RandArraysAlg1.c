/*
Project:	CS325 - Closest to Zero
Section:	Algorithm 1
File:		RandArraysAlg1.c
Authors: 	Ian Paul, Emma Paul, Abdulhalim Bambang
*/
// ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//variables for timing
time_t startTime;
time_t endTime;
double totalTime = 0;
double startTimer;
double endTimer;

int i, j, k, z, sum, subsetSize, arraySize, position, tempSize;

int lowestSum = NULL; //variable to store lowest Sum when found while iterating through 
int startPos, endPos; //variables to store the beginning and end index positions in the array for the sub array 

int zeroPosStart, zeroPosEnd;
int zeroFlag = 0;


int randArraySize;

int sizeOfRandArray; 


int main(int argc, char *argv[])
{

	sizeOfRandArray = atoi(argv[1]);
	time_t t;
	srand((unsigned) time(&t));
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//random array generator		
				
			
	int randArray[sizeOfRandArray];
	randArraySize = (int) sizeof(randArray) / sizeof(randArray[0]);
	
	for (j = 0; j < randArraySize; j++)
	{
		randArray[j] = rand() % 1999 + (-1000); //http://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c 
	}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	arraySize = (sizeof(randArray) / sizeof(randArray[0]));
	printf("Random Array size: %d \n", arraySize);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Prints random array: 
	printf("[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		printf("%d", randArray[j]);
		if (j < arraySize-1)
		{
			printf(", ");
		}
	}
		printf("]");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	startTimer = time(&startTime); //start tiing 
	clock_t tic = clock();

	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += randArray[k];					
			}

			if (abs(sum) < lowestSum || lowestSum == NULL)
			{
				lowestSum = abs(sum);
				startPos = position;
				endPos = subsetSize; 
			}
			
			if (sum == 0)
			{
				zeroFlag = 1;
				zeroPosStart = position;
				zeroPosEnd = subsetSize; 
			}
		
			sum = 0;
			subsetSize++;	
		}
		
		position++;
		subsetSize = position;
		arraySize--;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
clock_t toc = clock(); //http://stackoverflow.com/questions/5248915/execution-time-of-c-program
printf("\n\nTotal time to complete: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

printf("\nSubset Array:\n");

if (zeroFlag == 1)
	{
	lowestSum = 0;
	printf("[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		printf("%d", randArray[i]);
		lowestSum += randArray[i];

		if (i <= zeroPosEnd-1)
		{
			printf(", ");
		}
		
	}
		printf("],");
		printf("%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;


printf("[");
for(i = startPos ; i <= endPos ; i++)
{
	printf("%d", randArray[i]);
	lowestSum += randArray[i];

	if (i <= endPos-1)
	{
		printf(", ");
	}
	
}
	printf("],");
	printf(" %d\n\n", abs(lowestSum));
}
return 0;
}