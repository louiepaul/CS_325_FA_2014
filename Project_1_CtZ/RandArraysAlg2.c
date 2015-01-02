/*
Project:	CS325 - Closest to Zero
Section:	Algorithm 2
File:		RandArraysAlg2.c
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
int newSum;

//CHANGE THIS FOR TIMING TESTING
int sizeOfRandArray = 100;




int main(int argc, char *argv[])
{
	
	int randArray[sizeOfRandArray];
	printf("Random Array size: %d \n", sizeOfRandArray);

	time_t t;
	srand((unsigned) time(&t));
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//random array generator		
				
	int randArraySize = (int) sizeof(randArray) / sizeof(randArray[0]);
	
	for (j = 0; j < randArraySize; j++)
	{
		randArray[j] = rand() % 1999 + (-1000); //http://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c 
	}
	
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	arraySize = (sizeof(randArray) / sizeof(randArray[0]));
	//printf("Random Array size: %d \n", arraySize);

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
		printf("\n");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//For loops to generate closest to zero and subset array values 

//int subArrayStartPos = position;
//int subArraySize = arraySize;

	startTimer = time(&startTime); //start timing 
	clock_t tic = clock();

for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += randArray[i];
	}

	 newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= randArray[j];

		if (abs(newSum) < lowestSum || lowestSum == NULL)
			{
				lowestSum = abs(newSum);
			    startPos = position;
				endPos = j; 
			}
		if (newSum == 0)
			{
				zeroFlag = 1;
				zeroPosStart = position;
				zeroPosEnd = j; 
			}

	}
	
	sum = 0;//have to reset sum 
	position++;
}


clock_t toc = clock(); //http://stackoverflow.com/questions/5248915/execution-time-of-c-program
printf("\nTotal time to complete: %f seconds\n\n", (double)(toc - tic) / CLOCKS_PER_SEC);
printf("\nSubset Array:\n");
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	printf("[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		printf("%d", randArray[i]);
		lowestSum += randArray[i];

		if (i <= zeroPosEnd-2)
		{
			printf(", ");
		}
		
	}
		printf("],");
		printf("%d\n", abs(lowestSum));
}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	printf("[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		printf("%d", randArray[i]);
		lowestSum += randArray[i];

		if (i < endPos-1)
		{
			printf(", ");
		}
	
	}
		printf("],");
		printf("%d\n", abs(lowestSum));
}


return 0;
}