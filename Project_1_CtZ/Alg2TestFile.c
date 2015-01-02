/*
Project:	CS325 - Closest to Zero
Section:	Algorithm 2
File:		Alg2TestFile.c
Authors: 	Ian Paul, Emma Paul, Abdulhalim Bambang
*/
// ------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <getopt.h>
#include <errno.h>

int i, j, k, z, sum, subsetSize, arraySize, position, tempSize;
int newSum;
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
	char outputFileName[] = "input_results_Alg2.txt";
    
    myFile = fopen(argv[1], "r");

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



//start algorithm for array 1 
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray1[i];
	}

	 newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray1[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray1[i]);
		lowestSum += testArray1[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray1[i]);
		lowestSum += testArray1[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 1 

//start of array 2 

//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)
	{
		fprintf(outputFile,"%d", testArray2[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");

//start algorithm for array 2
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray2[i];
	}

	newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray2[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray2[i]);
		lowestSum += testArray2[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray2[i]);
		lowestSum += testArray2[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 2


//start of array 3


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

//start algorithm for array 3
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray3[i];
	}

	int newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray3[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray3[i]);
		lowestSum += testArray3[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray3[i]);
		lowestSum += testArray3[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 3

//start of array 4 


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

//start algorithm for array 4
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray4[i];
	}

	int newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray4[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray4[i]);
		lowestSum += testArray4[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray4[i]);
		lowestSum += testArray4[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 4

//start of array 5

//Prints given array: 
	fprintf(outputFile,"[");
	for (j = 0; j < arraySize; j++)
	{
		fprintf(outputFile,"%d", testArray5[j]);
		if (j < arraySize-1)
		{
			fprintf(outputFile,", ");
		}
	}
		fprintf(outputFile,"], ");

//start algorithm for array 5 
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray5[i];
	}

	int newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray5[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray5[i]);
		lowestSum += testArray5[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray5[i]);
		lowestSum += testArray5[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 5

//start of array 6


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

//start algorithm for array 6 
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray6[i];
	}

	int newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray6[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray6[i]);
		lowestSum += testArray6[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray6[i]);
		lowestSum += testArray6[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 6

//start of array 7


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

//start algorithm for array 7 
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray7[i];
	}

	int newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray7[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray7[i]);
		lowestSum += testArray7[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray7[i]);
		lowestSum += testArray7[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 7


//start of array 8


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

//start algorithm for array 8
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray8[i];
	}

	newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray8[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray8[i]);
		lowestSum += testArray8[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray8[i]);
		lowestSum += testArray8[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;


//end of array 8


//start of array 9 


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

//start algorithm for array 9 
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray9[i];
	}

	int newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray9[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray9[i]);
		lowestSum += testArray9[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
	}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray9[i]);
		lowestSum += testArray9[i];

		if (i < endPos-1)
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
	position = 0;
	newSum = 0;
	sum = 0;

//end of array 9

//start of array 10 

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



//start algorithm for array 10
for(z = position; z < arraySize; z++)
{
	for (i = position; i < arraySize; i++)
	{
		sum += testArray10[i];
	}

	 newSum = sum;

	for (j = arraySize; j > position; j--)
	{

		newSum -= testArray10[j];

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Printing results: 
if (zeroFlag == 1)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = zeroPosStart ; i < zeroPosEnd ; i++)
	{
		fprintf(outputFile,"%d", testArray10[i]);
		lowestSum += testArray10[i];

		if (i <= zeroPosEnd-2)
		{
			fprintf(outputFile,", ");
		}
		
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
}


else if (zeroFlag == 0)
{
	lowestSum = 0;
	fprintf(outputFile,"[");
	
	for(i = startPos ; i < endPos ; i++)
	{
		fprintf(outputFile,"%d", testArray10[i]);
		lowestSum += testArray10[i];

		if (i < endPos-1)
		{
			fprintf(outputFile,", ");
		}
	
	}
		fprintf(outputFile,"],");
		fprintf(outputFile,"%d\n", abs(lowestSum));
}

	

//end of array 10

fclose(outputFile);	

return 0;
}
