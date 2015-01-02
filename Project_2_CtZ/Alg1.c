/*
Project:	CS325 - Project 2
Section:	Algorithm 1
File:		Alg1.c
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

static int array1[] = {360,-948,-29,447,515,-53,491,761,719,-854,77,-677,473,-262,95,844,84,875,241,-320,143,-888,-524,947,652,-260,-503,-882,-692,-223,-745,-245,37,387,-602,-862,-125,653,938,635,-960,375,-555,730,-198,-691,74,-336,112,62,-319,-877,416,646,207,616,608,-737,143,-747,387,788,105,258,408,517,451,-718,-358,-118,738,72,457,551,-726,580,297,-662,135,-220,-267,773,117,-669,905,152,789,-243,901,-241,-223,-380,668,514,-916,-723,957,-222,605,371};

static int array2[] = {-536,565,-319,653,667,67,331,297,-688,-963,730,725,-298,21,-797,557,-286,-641,290,151,-271,534,730,-865,986,-4,984,-762,-792,-450,428,753,49,-245,-141,-710,-325,862,-294,859,-517,-911,-671,-223,-577,-778,-916,871,835,541,-986,-593,-913,357,358,478,-616,-958,440,-75,-155,-645,508,-29,715,275,-633,790,-441,-6,98,-232,78,-941,67,-29,539,791,-702,-81,-477,481,-978,-901,784,-563,-589,712,860,373,872,315,-13,-691,953,-602,-380,-834,-734,-778};

int i;
int j;
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


int main(int argc, char *argv[])
{

arraySize1 = (sizeof(array1) / sizeof(array1[0]));
subArraySize1 = arraySize1;

arraySize2 = (sizeof(array2) / sizeof(array2[0]));
subArraySize2 = arraySize2;

//Prints given array: 
for (i = subArraySize1 -1; i >= 0; i--)
{

	//printf("\nSub Array 1 Size: %d\n", i + 1);
	//printf("[");
	for (j = startPos1; j < arraySize1; j++)
	{
		
		//printf("%d", array1[j]);
		sum1 += array1[j];
		//if (j < subArraySize1-1)
		//{
			//printf(", ");
		//}
	}
		//printf("], ");
		//printf("%d\n", sum1);
	
	
	for (y = subArraySize2 -1; y >= 0; y--)
	{
		//printf("\nSub Array 2 Size: %d\n", y + 1);
		//printf("[");
		for (z = startPos2; z < arraySize2; z++)
		{
			//printf("%d", array2[z]);
			sum2 += array2[z];
			//if (z < subArraySize2-1)
			//{
				//printf(", ");
			//}
		}
		//printf("], ");
		//printf("%d\n", sum2);
		
		sum = sum1 + sum2;
		
		//printf("Total sum of both sums:%d\n", sum);
		
		
				if (abs(sum) < lowestSum || lowestSum == NULL)
			{
				lowestSum = abs(sum);
			    array2FinalSize = subArraySize2;
				array2FinalStartPos = startPos2;
				
				array1FinalSize = subArraySize1;
				array1FinalStartPos = startPos1;
				
			}
		
		
		sum2 = 0;
		startPos2++;	
		
	}
	
	sum1 = 0;
	startPos1++;	
	//subArraySize--;

	
	sum2 = 0;
	startPos2 = 0;
	
}

//int array1FinalStartPos, array2FinalStartPos;
//int array1FinalSize, array2FinalSize;
		

		printf("(");
		printf("[");
		for (z = array1FinalStartPos; z < array1FinalSize; z++)
		{
			printf("%d", array1[z]);
			sum1 += array1[z];
			if (z < array1FinalSize-1)
			{
				printf(", ");
			}
		}
		printf("], ");
		//printf("%d\n", sum1);

		printf("[");
		for (z = array2FinalStartPos; z < array2FinalSize; z++)
		{
			printf("%d", array2[z]);
			sum2 += array2[z];
			if (z < array2FinalSize-1)
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