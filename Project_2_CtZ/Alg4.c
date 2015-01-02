/*
Project:	CS325 - Project 2
Section:	Algorithm 4
File:		Alg4.c
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

//static int fullArray1[] = {360,-948,-29,447,515,-53,491,761,719,-854};

//static int fullArray1[] = {360,-948,-29,447,515,-53,491,761,719,-854,77,-677,473,-262,95,844,84,875,241,-320,143,-888,-524,947,652,-260,-503,-882,-692,-223,-745,-245,37,387,-602,-862,-125,653,938,635,-960,375,-555,730,-198,-691,74,-336,112,62,-319,-877,416,646,207,616,608,-737,143,-747,387,788,105,258,408,517,451,-718,-358,-118,738,72,457,551,-726,580,297,-662,135,-220,-267,773,117,-669,905,152,789,-243,901,-241,-223,-380,668,514,-916,-723,957,-222,605,371};

static int fullArray1[] = {-536,565,-319,653,667,67,331,297,-688,-963,730,725,-298,21,-797,557,-286,-641,290,151,-271,534,730,-865,986,-4,984,-762,-792,-450,428,753,49,-245,-141,-710,-325,862,-294,859,-517,-911,-671,-223,-577,-778,-916,871,835,541,-986,-593,-913,357,358,478,-616,-958,440,-75,-155,-645,508,-29,715,275,-633,790,-441,-6,98,-232,78,-941,67,-29,539,791,-702,-81,-477,481,-978,-901,784,-563,-589,712,860,373,872,315,-13,-691,953,-602,-380,-834,-734,-778};

int i;
int j;
int sum; 
int arraySize;
int subArraySize;
int startPos;
int lowestSum = NULL;

int temp;
int tempPos;

int sum1, sum2;
int sumArray1, sumArray2;
int arraySize1, arraySize2, fullArraySize;
int subArraySize1, subArraySize2;
int startPos1, startPos2;
int y, z;

int array1FinalStartPos, array2FinalStartPos;
int array1FinalSize, array2FinalSize;


int lowestSumPos1, lowestSumPos2;



int main(int argc, char *argv[])
{

fullArraySize = (sizeof(fullArray1) / sizeof(fullArray1[0]));

arraySize1 = fullArraySize / 2;
arraySize2 = fullArraySize / 2;


int array1[arraySize1];
int sum1Array[arraySize1];

int array2[arraySize2];
int sum2Array[arraySize2];

int array1Sums[arraySize1];
int array1SumsPos[arraySize1];

int array2Sums[arraySize2];
int array2SumsPos[arraySize2];

for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+50];
	}



subArraySize1 = arraySize1;

subArraySize2 = arraySize2;


//finding sums of array 1
for(i = 0; i < arraySize1; i++)
{
	sumArray1 += array1[i];

}
//populating sum1Array
	
	sum1Array[0] = sumArray1;
	
for(i = 1; i < arraySize1; i++)
{
	sum1Array[i] = sum1Array[i-1] - array1[i-1];
}



//Populate sum2Array
for(i = 0; i < arraySize2; i++)
{
	sumArray2 += array2[i];
	sum2Array[i] = sumArray2;
}


//populating array sums positions
	for (i = 0; i < arraySize1; i++)
	{
		array1SumsPos[i] = i;
	}	
	for (i = 0; i < arraySize2; i++)
	{
		array2SumsPos[i] = i;
	}
	

	

//Sorting sum1Array and array1SumsPos
     for (i = 0; i < (arraySize1 - 1); i++)
     {
          for (j = 0; j < arraySize1 - 1 - i; j++ )
          {
               if (sum1Array[j] > sum1Array[j+1])
               {
					//for sorting array elements
                    temp = sum1Array[j+1];
                    sum1Array[j+1] = sum1Array[j];
                    sum1Array[j] = temp;
					
					//for sorting array position
					tempPos = array1SumsPos[j+1];
                    array1SumsPos[j+1] = array1SumsPos[j];
                    array1SumsPos[j] = tempPos;
					
               }
          }
     }

	 


	

//Sorting sum2Array and array2SumsPos
     for (i = 0; i < (arraySize2 - 1); i++)
     {
          for (j = 0; j < arraySize2 - 1 - i; j++)
          {
               if (sum2Array[j] > sum2Array[j+1])
               {
					//for sorting array elements
                    temp = sum2Array[j+1];
                    sum2Array[j+1] = sum2Array[j];
                    sum2Array[j] = temp;
					
					//for sorting array position
					tempPos = array2SumsPos[j+1];
                    array2SumsPos[j+1] = array2SumsPos[j];
                    array2SumsPos[j] = tempPos;
					
               }
          }
     }
	 
  

//pitting to find lowest
for(i = 0; i < arraySize1; i++)
{
	sum1 = sum1Array[i];
	
	for(j = 0; j < arraySize2; j++)
	{
	
		
		sum2 = sum2Array[j];
		
		sum = sum1 + sum2;
		
		//printf("%d + %d = %d\n", sum1, sum2, sum);
		
		if (abs(sum) < lowestSum || lowestSum == NULL)
		{
			lowestSum = abs(sum);
			//printf("Struck Gold!! ");
			//printf("%d\n", lowestSum);
			//array1FinalStartPos
			//array1FinalSize
			//array2FinalStartPos
			//array2FinalSize
			//printf("array2SumsPos: %d\n",array2SumsPos[j]);
			//printf("sum2Array Value: %d\n",sum2Array[j]);
			array1FinalStartPos = array1SumsPos[i];
			array1FinalSize = arraySize1 - array1FinalStartPos;
			
			
			array2FinalStartPos = 0;
			array2FinalSize = array2SumsPos[j];
					   
		}
	}
}

printf("\n");
sum1 = 0;
sum2 = 0;
		printf("(");
		printf("[");
		for (z = array1FinalStartPos; z < arraySize1; z++)
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
		for (z = 0; z <= array2FinalSize; z++)
		{
			printf("%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize)
			{
				printf(", ");
			}
		}
		printf("]) = ");
		//printf("%d\n", sum2);
		
		lowestSum = sum1+sum2;
		
		printf("%d\n", lowestSum);
		


return 0;
}