/*
Project:	CS325 - Project 3
Section:	Change Greedy
File:		changegreedy.c
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
#include <memory.h>

char ch[10];
int numCount;
int numFlag = 0;
int lastFlag = 0;

int C; 
int i = 0;
void changegreedy(int *O, int *V, int C, int numCount, char *outputFile);
int num;

//variables for file input and output names
char userInputFileName[50];
char outputFile[100];


int main(int argc, char *argv[])
{

char* addToFileName;
addToFileName = "_change.txt";


for (i=0; i<strlen(argv[1])-4; i++)
	{
	userInputFileName[i] = argv[1][i];
	}

//printf("%s\n",userInputFileName);

strcat(outputFile, userInputFileName);
strcat(outputFile, addToFileName);

//printf("%s\n",outputFile);

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

			/*
			printf("Number array is : [");
			for (i = 0; i < numCount; i++)
			{
				   printf("%d", V[i]);
				   if ( i < numCount - 1)
				   {
						printf(", ");
				   }
			}
			printf("]\n");

		*/
//While loop to itterate through all lines of input			
/////////////////////////////////////////////////////////////		
			while((fscanf(fileAgain, "%*[^0-9]%d", &num))!= EOF)
			{
				C = num;
				changegreedy(O, V, C, numCount - 1, outputFile);	
			}
			
		}

			fclose(fileAgain);

return 0;
}


void changegreedy(int *O, int *V, int C, int numCount, char *outputFile)
{

//printf("Amount to give change: %d\n", C);

		//For creating file to output to
		FILE *fileToMake;

		fileToMake = fopen(outputFile, "a");
	
		if(fileToMake == NULL)
		{
			fprintf(stderr, "Can't open output file %s!\n", outputFile);
			exit(1);
		}

	for(i = numCount; i >= 0; i--)
		{
			while(V[i] <= C)
			{
				C = C - V[i]; 
				O[i]+= 1; 
				
			}
		}

		fprintf(fileToMake,"[");
		for(i = 0; i <= numCount; i++)
		{
			fprintf(fileToMake,"%d", O[i]);

			if(i < numCount)
			{
				fprintf(fileToMake,", ");
			}
		}

		fprintf(fileToMake,"]\n");

		for(i = 0; i <= numCount; i++)
		{
			O[i] = 0;
		}
			fclose(fileToMake);

}



