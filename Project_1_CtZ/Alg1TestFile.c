/*
Project:	CS325 - Closest to Zero
Section:	Algorithm 1
File:		Alg1TestFile.c
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


//variables for timing
time_t startTime;
time_t endTime;
double totalTime = 0;
double startTimer;
double endTimer;

int i, j, k, z, sum, subsetSize, arraySize, position, tempSize;


int absSum;
int lowestSum = NULL; //variable to store lowest Sum when found while iterating through 
int startPos, endPos; //variables to store the beginning and end index positions in the array for the sub array 

int zeroPosStart, zeroPosEnd;
int zeroFlag = 0;


static int testArray1[100];
static int testArray2[100];
static int testArray3[100];
static int testArray4[100];
static int testArray5[100];
static int testArray6[100];
static int testArray7[100];
static int testArray8[100];
static int testArray9[100];
static int testArray10[100];

int junk;

int main(int argc, char *argv[])
{
    FILE *myFile, *outputFile;

	char outputFileName[] = "input_results_Alg1.txt";
    myFile = fopen(argv[1], "r");

    //read file into array
    if (myFile == NULL)
    {
        printf("Error Reading File\n");
        exit (0);
    }
	

//Scans first line for first array
	fscanf(myFile, "[", &junk);
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray1[i]);
	}
	fscanf(myFile, "]\n", &junk);
		
	
//Scans second line for second array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray2[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans third line for third array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray3[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans fourth line for fourth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray4[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans fifth line for fifth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray5[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans sixth line for sixth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray6[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans seventh line for seventh array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray7[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans eighth line for eighth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray8[i]);
	}
	fscanf(myFile, "]\n", &junk);

//Scans ninth line for ninth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray9[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//Scans tenth line for tenth array	
	fscanf(myFile, "[", &junk);
				
	for(i = 0; i < 100; i++)
	{
		fscanf(myFile, "\n%d,", &testArray10[i]);
	}
	fscanf(myFile, "]\n", &junk);
	
//close file	
	fclose(myFile);	


//opens output file
	outputFile = fopen(outputFileName, "w");
	
	if(outputFile == NULL)
	{
		fprintf(stderr, "Can't open output file %s!\n", outputFileName);
		exit(1);
	}
	

	
//starts algorithm	for array 1
	arraySize = (sizeof(testArray1) / sizeof(testArray1[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray1[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray1[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray1[i]);
		lowestSum += testArray1[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray1[i]);
		lowestSum += testArray1[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
	
// end of array 1
	
	
//starts algorithm for array 2
	arraySize = (sizeof(testArray2) / sizeof(testArray2[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray2[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray2[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray2[i]);
		lowestSum += testArray2[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray2[i]);
		lowestSum += testArray2[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 2


//starts algorithm for array 3
	arraySize = (sizeof(testArray3) / sizeof(testArray3[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray3[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray3[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray3[i]);
		lowestSum += testArray3[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray3[i]);
		lowestSum += testArray3[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 3

//starts algorithm for array 4
	arraySize = (sizeof(testArray4) / sizeof(testArray4[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray4[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray4[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray4[i]);
		lowestSum += testArray4[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray4[i]);
		lowestSum += testArray4[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 4


//starts algorithm for array 5
	arraySize = (sizeof(testArray5) / sizeof(testArray5[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray5[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray5[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray5[i]);
		lowestSum += testArray5[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray5[i]);
		lowestSum += testArray5[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 5

//starts algorithm for array 6
	arraySize = (sizeof(testArray6) / sizeof(testArray6[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray6[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray6[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray6[i]);
		lowestSum += testArray6[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray6[i]);
		lowestSum += testArray6[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 6

//starts algorithm for array 7
	arraySize = (sizeof(testArray7) / sizeof(testArray7[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray7[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray7[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray7[i]);
		lowestSum += testArray7[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray7[i]);
		lowestSum += testArray7[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 7

//starts algorithm for array 8
	arraySize = (sizeof(testArray8) / sizeof(testArray8[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray8[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray8[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray8[i]);
		lowestSum += testArray8[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray8[i]);
		lowestSum += testArray8[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 8

//starts algorithm for array 9
	arraySize = (sizeof(testArray9) / sizeof(testArray9[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray9[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray9[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray9[i]);
		lowestSum += testArray9[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray9[i]);
		lowestSum += testArray9[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 9

//starts algorithm for array 10
	arraySize = (sizeof(testArray10) / sizeof(testArray10[0]));


//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c
	{
		fprintf(outputFile,"%d", testArray10[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");
		
//For loops to generate closest to zero and subset array values 
	position = 0;
	tempSize = arraySize;
	subsetSize = 0;
	
	for ( z = 0; z < tempSize; z++)
	{
		for (i = 0; i < arraySize; i++)
		{
			for (k = position; k <= subsetSize; k++)
			{		
				sum += testArray10[k];					
			}

			absSum = abs(sum);
			
			if(absSum < lowestSum || lowestSum == NULL)
			{
				lowestSum = absSum;
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

if (zeroFlag == 1)
	{
	lowestSum = 0;
	fprintf(outputFile,"[");
	for(i = zeroPosStart ; i <= zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray10[i]);
		lowestSum += testArray10[i];

		if (i <= zeroPosEnd-1)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", lowestSum);
		
	}

else if (zeroFlag == 0)
	{
	lowestSum = 0;

	fprintf(outputFile,"[");
	for(i = startPos ; i <= endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray10[i]);
		lowestSum += testArray10[i];

		if (i <= endPos-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"],");
		
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}
	
	startPos = 0;
	endPos = 0;
	zeroPosStart = 0;
	zeroPosEnd = 0;
	lowestSum = NULL;
	zeroFlag = 0;
	
// end of array 10

//close file	
	fclose(outputFile);	

return 0;
}