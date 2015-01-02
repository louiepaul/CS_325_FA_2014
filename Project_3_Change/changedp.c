/*
Project:	CS325 - Project 3
Section:	Change DP
File:		changedp.c
Authors: 	Ian Paul, Emma Paul, Abdulhalim Bambang
*/
// ------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>//
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <memory.h>

char ch[10];
int numCount;
int numFlag = 0;
int lastFlag = 0;

//variables for file input and output names
char userInputFileName[50];
char outputFile[100];

int i = 0;
int j = 0;
//int V[] = {1, 10, 25, 50};
//int O[] = {0, 0, 0, 0};

int C = 0;
//int C = 8;
int size = 0; //size for num of elements in V  
int numCols = 0;
int num;


int A[4][41];
int used[4][41];
int temp;

//void changegreedy(int *O, int *V, int C, int numCount, char *outputFile);

void optimal_coins_set(int i, int j, int *V, int used[numCount][numCols], int *O);
void changedp(int i, int j, int numCols, int size, int *V, int *O, int used[numCount][numCols], int A[numCount][numCols], char *outputFile);

int main(int argc, char *argv[])
{
//input user defined file to open and create name for output file
////////////////////////////////////////////////////////////
char* addToFileName;
addToFileName = "_change.txt";


for (i=0; i<strlen(argv[1])-4; i++)
	{
	userInputFileName[i] = argv[1][i];
	}



strcat(outputFile, userInputFileName);
strcat(outputFile, addToFileName);

//printf("%s\n",userInputFileName);
//printf("%s\n",outputFile);
//done
//////////////////


//scan file to get the denomination array (V)
///////////////////////////////////////////////////////////
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );
        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
			exit(0);
        }
 else 
        {
			while (fscanf(file, "%c", ch) != EOF)
			{
			   if(*ch == '\n')
				{
					break;
				}
			   if(*ch > 57 || *ch < 48)
			   {
					numFlag = 0;
			   }
			   else
			   {
					numFlag = 1;
			   }
			   if (numFlag == 1 && lastFlag == 0)
			   {
					numCount++;
			   }
			   lastFlag = numFlag;
			}

		}

			fclose(file);
			
		
int V[numCount];

for(i = 0; i < numCount; i++)
{
	V[i] = 0;
}

int O[numCount];	

for(i = 0; i < numCount; i++)
{
	O[i] = 0;
}		


//create V and used arrays based on how many coins
///////////////////////////////////////////////////////////

        // We assume argv[1] is a filename to open
        FILE *fileAgain = fopen( argv[1], "r" );
        /* fopen returns 0, the NULL pointer, on failure */
        if ( fileAgain == 0 )
        {
            printf( "Could not open file\n" );
			exit(0);
        }
        else 
        {	

			for (i = 0; i < numCount; i++)
			{
				fscanf(fileAgain, "%*[^0-9]%d", &V[i] );

			}

					
//While loop to itterate through all lines of input			
/////////////////////////////////////////////////////////////		
			while((fscanf(fileAgain, "%*[^0-9]%d", &num))!= EOF)
			{
				C = num;
				numCols = C + 1;
				
				//maybe intitialize with 0 if things go bad
				int A[numCount][numCols];
				int used[numCount][numCols];
			
				changedp(i, j, numCols, numCount, V, O, used, A, outputFile);
				i = 0;
				j = 0;
				numCols = 0;
				for(i = 0; i < numCount; i++)
				{
					O[i] = 0;
				}

			}
			
		}

			fclose(fileAgain);
	

	return 0; 

}

void changedp(int i, int j, int numCols, int size, int *V, int *O, int used[numCount][numCols], int A[numCount][numCols], char *outputFile)
{
j = 0;
i = 0;
		//For creating file to output to
		FILE *fileToMake;

		fileToMake = fopen(outputFile, "a");
	
		if(fileToMake == NULL)
		{
			fprintf(stderr, "Can't open output file %s!\n", outputFile);
			exit(1);
		}

	for(j = 0; j < numCols ; j++) //fill first row (1 cent) with j value (ex it takes 8 1cent pennies to make amount 8)
	{
		A[i][j] = j*V[0];
		used[i][j] = 1; //for true 
		//printf("%d ", A[i][j]);
	}
	//printf("\n");

	for(j = 1; j < numCols; j++)
	{
		for(i = 1; i < size; i++)
		{
			if (V[i] == j)
			{
				A[i][j] = 1; //also do used[i][j] = 1 later 
				used[i][j] = 1; //for true 
			}

			else if(V[i] > j)
			{
				A[i][j] = A[i-1][j];
				used[i][j] = 0;//for false 
			}
			else //V[i] < j 
			{
				temp = j - V[i]; 
				A[i][j] = 1 + A[i][temp];
				used[i][j] = 1;//for true 
				
				if (A[i][j] > A[i-1][j])
				{
					(A[i][j] = A[i-1][j]);
					used[i][j] = 0;//for false 
				}
			}

		}
	}


	//printf("\n");

	
 		for(i = 0; i < size ; i++)
 		{
 			for(j = 0; j < numCols ; j++)
 			{
 				//printf("%d ", A[i][j]);
 			}
 			//printf("\n");
 	
 		}


 		for(i = 0; i < size ; i++)
 		{
 			for(j = 0; j < numCols ; j++)
 			{
 				//printf("%d ", used[i][j]);
 			}
 			//printf("\n");
 	
 		}

 		optimal_coins_set(size - 1 , numCols -1, V, used, O);

		fprintf(fileToMake,"[");
 		for(i = 0; i < size; i++)
 		{
 			fprintf(fileToMake,"%d", O[i]);
			
			if(i < size - 1)
			{
				fprintf(fileToMake,", ");
			}
 		}
		fprintf(fileToMake,"]\n");
		
		fclose(fileToMake);
}


void optimal_coins_set(int i, int j, int *V, int used[numCount][numCols], int *O)
{
	if(j == 0)
	{
		return;
	}
	if(used[i][j] == 1)//if top right element of used table is 1 (ie true)
	{
		//printf("i = %d\n", i);
		//printf("j = %d\n", j);
		//printf("Use a coin of denomination: %d\n\n", V[i]);
		O[i] = 1 + O[i];
		C = C - V[i];
		optimal_coins_set(i, C, V, used, O);
	}
	else 
	{
		optimal_coins_set(i - 1, j, V, used, O);
	}
		
}