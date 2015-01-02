/*
Project:	CS325 - Project 2
Section:	Algorithm 3
File:		Alg3.c
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

//static int fullArray1[] = {360,-948,-29,447,53,-53,491,761,719,-854};

static int fullArray1[] = {360,-948,-29,447,515,-53,491,761,719,-854,77,-677,473,-262,95,844,84,875,241,-320,143,-888,-524,947,652,-260,-503,-882,-692,-223,-745,-245,37,387,-602,-862,-125,653,938,635,-960,375,-555,730,-198,-691,74,-336,112,62,-319,-877,416,646,207,616,608,-737,143,-747,387,788,105,258,408,517,451,-718,-358,-118,738,72,457,551,-726,580,297,-662,135,-220,-267,773,117,-669,905,152,789,-243,901,-241,-223,-380,668,514,-916,-723,957,-222,605,371};

//static int fullArray1[] = {-536,565,-319,653,667,67,331,297,-688,-963,730,725,-298,21,-797,557,-286,-641,290,151,-271,534,730,-865,986,-4,984,-762,-792,-450,428,753,49,-245,-141,-710,-325,862,-294,859,-517,-911,-671,-223,-577,-778,-916,871,835,541,-986,-593,-913,357,358,478,-616,-958,440,-75,-155,-645,508,-29,715,275,-633,790,-441,-6,98,-232,78,-941,67,-29,539,791,-702,-81,-477,481,-978,-901,784,-563,-589,712,860,373,872,315,-13,-691,953,-602,-380,-834,-734,-778};

//static int fullArray1[] = {715,-782,469,548,438,290,-560,-916,573,362,654,494,62,-128,-589,22,159,-674,-875,-490,393,-460,317,350,-232,872,-470,443,814,-702,0,-126,352,945,905,113,-393,-248,-477,720,-546,102,785,-826,19,-943,-872,-857,-50,-935,894,416,-794,-448,769,-88,728,-935,96,-126,847,-324,-924,389,-643,-253,-523,-292,786,974,-155,-644,-895,-246,771,-457,-584,537,477,-34,879,-782,0,158,-5,-452,211,-780,-786,-638,819,751,-226,-392,-685,-764,17,-916,823,-562};


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


int main(int argc, char *argv[])
{

fullArraySize = (sizeof(fullArray1) / sizeof(fullArray1[0]));

arraySize1 = fullArraySize / 2;
arraySize2 = fullArraySize / 2;

int array1[arraySize1];
int array2[arraySize2];


for (i = 0; i < arraySize1; i++)
	{
		array1[i] = fullArray1[i];
	}
	
for (i = 0; i < arraySize2; i++)
	{
		array2[i] = fullArray1[i+arraySize2];
	}



subArraySize1 = arraySize1;

subArraySize2 = arraySize2;



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

//printing results
sum1 = 0;
sum2 = 0;		
lowestSum = 0; 

		printf("(");
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
		printf("]) = ");
		

		
		lowestSum = sum1+sum2;
		
		printf("%d\n", lowestSum);
	


return 0;
}