/*
Project:	CS325 - Project 2
Section:	Algorithm 2
File:		Alg2.c
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

static int array1[] = {360,-948,-29,447,515,-53,491,761,719,-854};
static int array2[] = {-536,565,-319,653,667,67,331,297,-688,-963};
//static int arrayPos[10];
static int array1Sums[10];
static int array1SumsPos[10];
static int array2Sums[10];
static int array2SumsPos[10];

int i;
int j;
int a;
int temp;
int tempPos;
int sum; 
int arraySize;
int subArraySize;
int startPos;
int lowestSum = NULL;

int sum1, sum2;
int arraySize1, arraySize2;
int subArraySize1, subArraySize2;
int startPos1, startPos2;
int y, z;

int array1FinalStartPos, array2FinalStartPos;
int array1FinalSize, array2FinalSize;

int lowestSumPos1, lowestSumPos2;


int main(int argc, char *argv[])
{



//finding sums for array 1 and storing them into array1Sums
arraySize1 = (sizeof(array1) / sizeof(array1[0]));
for (i = arraySize1 -1; i >= 0; i--)
{
	for (j = startPos1; j < arraySize1; j++)
	{
		sum1 += array1[j];
	}
	array1Sums[startPos1] = sum1;
	sum1 = 0;
	startPos1++;	
}


//finding sums for array 2 and storing them into array2Sums
arraySize2 = (sizeof(array2) / sizeof(array2[0]));
for (i = arraySize2 -1; i >= 0; i--)
{
	for (j = startPos2; j < arraySize2; j++)
	{
		sum2 += array2[j];
	}
	array2Sums[startPos2] = sum2;
	sum2 = 0;
	startPos2++;	
}


//printing array1Sums
//printf("Sum Array 1\n");
	//printf("[");
	for (i = 0; i < arraySize1; i++)
	{
		//printf("%d", array1Sums[i]);
		array1SumsPos[i] = i;
			//if (i < arraySize1-1)
			//{
				//printf(", ");
			//}
	}
	//printf("]");
	
//printf("\nSum Array 1 Positions\n");
	//printf("[");
	//for (i = 0; i < arraySize1; i++)
	//{
		//printf("%d", array1SumsPos[i]);
		//array1SumsPos[i] = i;
			//if (i < arraySize1-1)
			//{
				//printf(", ");
			//}
	//}
	//printf("]\n\n");
	
//printing array2Sums
//printf("Sum Array 2\n");
	//printf("[");
	for (i = 0; i < arraySize2; i++)
	{
		//printf("%d", array2Sums[i]);
		array2SumsPos[i] = i;
			//if (i < arraySize2-1)
			//{
				//printf(", ");
			//}
	}
	//printf("]");

	
//printf("\nSum Array 2 Positions\n");
	//printf("[");
	//for (i = 0; i < arraySize2; i++)
	//{
		//printf("%d", array2SumsPos[i]);
		//array2SumsPos[i] = i;
			//if (i < arraySize2-1)
			//{
				//printf(", ");
			//}
	//}
	//printf("]\n\n");

	
//Sorting array1Sums and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); ++i)
     {
          for (j = 0; j < arraySize1 - 1 - i; ++j )
          {
               if (array1Sums[j] > array1Sums[j+1])
               {
					//for sorting array elements
                    temp = array1Sums[j+1];
                    array1Sums[j+1] = array1Sums[j];
                    array1Sums[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }
	 
//Sorting array2Sums and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++ )
          {
               if (array2Sums[j] > array2Sums[j+1])
               {
					//for sorting array elements
                    temp = array2Sums[j+1];
                    array2Sums[j+1] = array2Sums[j];
                    array2Sums[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }

	 
// Printing sorted order for array1Sums
//printf("Sum Array 1 Sorted\n");
	//printf("[");
	//for (i = 0; i < arraySize1; i++)
	//{
		//printf("%d", array1Sums[i]);
		//array1SumsPos[i] = i;
			//if (i < arraySize1-1)
			//{
				//printf(", ");
			//}
	//}
	//printf("]");
	
//printf("\nSum Array 1 Sorted Positions\n");
	//printf("[");
	//for (i = 0; i < arraySize1; i++)
	//{
		//printf("%d", array1SumsPos[i]);
		//array1SumsPos[i] = i;
			//if (i < arraySize1-1)
			//{
				//printf(", ");
			//}
	//}
	//printf("]\n");
	
// Printing sorted order for array2Sums
//printf("Sum Array 2 Sorted\n");
	//printf("[");
	//for (i = 0; i < arraySize2; i++)
	//{
		//printf("%d", array2Sums[i]);
		//array1SumsPos[i] = i;
			//if (i < arraySize2-1)
			//{
				//printf(", ");
			//}
	//}
	//printf("]");
	
//printf("\nSum Array 2 Sorted Positions\n");
	//printf("[");
	//for (i = 0; i < arraySize2; i++)
	//{
		//printf("%d", array2SumsPos[i]);
		//array1SumsPos[i] = i;
			//if (i < arraySize2-1)
			//{
				//printf(", ");
			//}
	//}
	//printf("]\n");
	
	
	//array2FinalSize = subArraySize2;
	//array2FinalStartPos = startPos2;
				
	//array1FinalSize = subArraySize1;
	//array1FinalStartPos = startPos1;	
	
for (i = 0; i < arraySize1; i++)
{
	sum1 = array1Sums[i];
	array1FinalStartPos = array1SumsPos[i];
	for (j = 0; j < arraySize2; j++)
	{
		sum2 = array2Sums[j];
		array2FinalStartPos = array2SumsPos[j];		
		
		sum = sum1 + sum2;
		
			if (abs(sum) < lowestSum || lowestSum == NULL)
			{
				lowestSum = abs(sum);
				lowestSumPos1 = array1FinalStartPos;
				lowestSumPos2 = array2FinalStartPos;
		
			}
		
	}
}

//printf("\n\nLowest Sum: %d\n", lowestSum);
//printf("Element to start from on Array 1: %d\n", array1[lowestSumPos1]);
//printf("Position to start from on Array 1: %d\n", lowestSumPos1);

//printf("Element to start from on Array 2: %d\n", array2[lowestSumPos2]);
//printf("Position to start from on Array 2: %d\n", lowestSumPos2);

sum1 = 0;
sum2 = 0;
		printf("(");
		printf("[");
		for (z = lowestSumPos1; z < arraySize1; z++)
		{
			printf("%d", array1[z]);
			sum1 += array1[z];
			if (z < arraySize1-1)
			{
				printf(", ");
			}
		}
		printf("], ");
		//printf("%d\n", sum1);

		printf("[");
		for (z = lowestSumPos2; z < arraySize2; z++)
		{
			printf("%d", array2[z]);
			sum2 += array2[z];
			if (z < arraySize2-1)
			{
				printf(", ");
			}
		}
		printf("]) = ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		
		printf("%d\n", lowestSum);

/*
printf("Given Array\n");
	printf("[");
	for (i = 0; i < arraySize; i++)
	{
		printf("%d", array1[i]);
		arrayPos[i] = i;
			if (i < arraySize-1)
			{
				printf(", ");
			}
	}
	printf("]\n");

printf("Array Positions\n");	
	printf("[");
	for (i = 0; i < arraySize; i++)
	{
		printf("%d", arrayPos[i]);
		
			if (i < arraySize-1)
			{
				printf(", ");
			}
	}
	printf("]\n\n");
	
//Sorting	
     for (i = 0; i < (arraySize - 1); ++i)
     {
          for (j = 0; j < arraySize - 1 - i; ++j )
          {
               if (array1[j] > array1[j+1])
               {
					//for sorting array elements
                    temp = array1[j+1];
                    array1[j+1] = array1[j];
                    array1[j] = temp;
					
					//for sorting array position
					tempPos = arrayPos[j+1];
                    arrayPos[j+1] = arrayPos[j];
                    arrayPos[j] = tempPos;
					
               }
          }
     }

	 
printf("Sorted Array\n");	 
	printf("[");
	for (i = 0; i < arraySize; i++)
	{
		printf("%d", array1[i]);
			if (i < arraySize-1)
			{
				printf(", ");
			}
	}
	printf("]\n");
	
printf("Array Positions\n");	
	printf("[");
	for (i = 0; i < arraySize; i++)
	{
		printf("%d", arrayPos[i]);
		
			if (i < arraySize-1)
			{
				printf(", ");
			}
	}
	printf("]\n\n");
	
*/
	

return 0;
}