/*
Project:	CS325 - Project 5
Section:	TSP
File:		rough_draft_algorithm.c
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
#include <math.h>

int bigCols = 4;

int tempQ;
//variables for file input and output names
char userInputFileName[50];
char outputFile[100];

int dummy;
int xDis;
int yDis;
int distance;
int totalDistance;

int tempCityID, tempXPos, tempYPos;

char ch[10];
int numCount;
int numFlag = 0;
int lastFlag = 0;

//int city_list[14][3] = {{0, 1, 1}, {1, 2, 3}, {2, 3, 6}, {3, 3, 9}, {4, 4, 4}, {5, 5, 8}, {6, 6, 10}, {7, 4, 13}, {8, 8, 11}, {9, 8, 8}, {10, 6, 6}, {11, 8, 5}, {12, 6, 3}, {13, 5, 1}};
//int ordered_x_array[14][4] = {{0, 1, 1, 0}, {1, 2, 3, 0}, {2, 3, 6, 0}, {3, 3, 9, 0}, {4, 4, 4, 0}, {7, 4, 13, 0}, {13, 5, 1, 0}, {5, 5, 8, 0}, {12, 6, 3, 0}, {10, 6, 6, 0}, {6, 6, 10, 0}, {11, 8, 5, 0}, {9, 8, 8, 0}, {8, 8, 11, 0}};
//int ordered_y_array[14][4] = {{0, 1, 1, 0},{13, 5, 1, 0}, {1, 2, 3, 0}, {12, 6, 3, 0}, {4, 4, 4, 0}, {11, 8, 5, 0}, {2, 3, 6, 0}, {10, 6, 6, 0}, {5, 5, 8, 0}, {9, 8, 8, 0}, {3, 3, 9, 0}, {6, 6, 10, 0}, {8, 8, 11, 0}, {7, 4, 13, 0}};


int num_cities;
int cities_left; 

int temp, i, j = 0;
int id;

int total_length;

int original_city;
 
int lpLength;
int lpNextCity;
int tour_count;

int final_pos_start;
int final_pos_end;


//void findPath(int *lpNextCity, int *lpLength, int ordered_x_array[][4], int ordered_y_array[][4], int id, int total_length, int city_list[][3], int num_cities, int *pos_id_x_ordered, int *pos_id_y_ordered, int cities_left);
void findPath(int *tour_count, int *tour, int *lpNextCity, int *lpLength, int **ordered_x_array, int **ordered_y_array, int id, int total_length, int **city_list, int num_cities, int *pos_id_x_ordered, int *pos_id_y_ordered, int cities_left);

int main(int argc, char *argv[])
{
	//input user defined file to open and create name for output file
	////////////////////////////////////////////////////////////
	char* addToFileName;
	addToFileName = ".tour";

	for (i=0; i<strlen(argv[1]); i++)
	{
		userInputFileName[i] = argv[1][i];
	}



	strcat(outputFile, userInputFileName);
	strcat(outputFile, addToFileName);

	printf("%s\n",userInputFileName);
	printf("%s\n",outputFile);
//done taking and storing the file name
///////////////////////////////////////////////////////////////////

//scan file to get cities and their x and y cords
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
					numCount++;
				}
			}
		}
			fclose(file);
	
	num_cities = numCount;
	original_city = id;



	
//arrays for storing city info
///////////////////////////////////////////////////////////////////////////////////
//int city_list[num_cities][3];
//int ordered_x_array[num_cities][4];
//int ordered_y_array[num_cities][4];



//city_list
int **city_list;
city_list = malloc(num_cities * sizeof(int *));
if(city_list == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < num_cities; i++)
	{
		city_list[i] = malloc(3 * sizeof(int));
		if(city_list[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}

//ordered_x_array
int **ordered_x_array;
ordered_x_array = malloc(num_cities * sizeof(int *));
if(ordered_x_array == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < num_cities; i++)
	{
		ordered_x_array[i] = malloc(4 * sizeof(int));
		if(ordered_x_array[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}

//ordered_y_array
int **ordered_y_array;
ordered_y_array = malloc(num_cities * sizeof(int *));
if(ordered_y_array == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < num_cities; i++)
	{
		ordered_y_array[i] = malloc(4 * sizeof(int));
		if(ordered_y_array[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//tour
int *tour;
tour = malloc(num_cities * sizeof(int *));
if(tour == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}


//zeroit(ordered_x_array, num_cities, bigCols);
//zeroit(ordered_y_array, num_cities, bigCols);

	
//done creating arrays for storing city info
////////////////////////////////////////////////////////////////////////////////////


//Scans input file to get city name, x cord and y cord
///////////////////////////////////////////////////
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

			for (i = 0; i < num_cities; i++)
			{
				fscanf(fileAgain,"%d%d%d", &city_list[i][0],&city_list[i][1],&city_list[i][2]);
			}
		}
		fclose(fileAgain);
		
//done
////////////////////////////////////////////////////////////

/*
for(i=0; i < num_cities; i++)
{
	printf("City Name: %d	X: %d	Y: %d\n",city_list[i][0],city_list[i][1],city_list[i][2]);
}
*/

//for filling arrays to be sorted
for(i=0; i < num_cities; i++)
{
	ordered_x_array[i][0] = city_list[i][0];
	ordered_x_array[i][1] = city_list[i][1];
	ordered_x_array[i][2] = city_list[i][2];
	ordered_x_array[i][3] = 0;
	
	ordered_y_array[i][0] = city_list[i][0];
	ordered_y_array[i][1] = city_list[i][1];
	ordered_y_array[i][2] = city_list[i][2];
	ordered_y_array[i][3] = 0;
}

//sorting for x using bubble sort 
for(i = num_cities-2; i>=0; i--)
{
	for(j = 0; j<=i; j++)
	{
		if(ordered_x_array[j][1] > ordered_x_array[j+1][1])
		{
			tempCityID = ordered_x_array[j][0];
			ordered_x_array[j][0] = ordered_x_array[j+1][0];
			ordered_x_array[j+1][0] = tempCityID;
			
			tempXPos = ordered_x_array[j][1];
			ordered_x_array[j][1] = ordered_x_array[j+1][1];
			ordered_x_array[j+1][1] = tempXPos;
			
			tempYPos = ordered_x_array[j][2];
			ordered_x_array[j][2] = ordered_x_array[j+1][2];
			ordered_x_array[j+1][2] = tempYPos;

			ordered_x_array[j][3] = 0; //maybe move this, but ensures that it marks 0 for not visited 
			
		}
	}
}	

//sorting for y 
for(i = num_cities-2; i>=0; i--)
{
	for(j = 0; j<=i; j++)
	{
		if(ordered_y_array[j][2] > ordered_y_array[j+1][2])
		{
			tempCityID = ordered_y_array[j][0];
			ordered_y_array[j][0] = ordered_y_array[j+1][0];
			ordered_y_array[j+1][0] = tempCityID;
			
			tempXPos = ordered_y_array[j][1];
			ordered_y_array[j][1] = ordered_y_array[j+1][1];
			ordered_y_array[j+1][1] = tempXPos;
			
			tempYPos = ordered_y_array[j][2];
			ordered_y_array[j][2] = ordered_y_array[j+1][2];
			ordered_y_array[j+1][2] = tempYPos;

			ordered_y_array[j][3] = 0;
			
		}
	}
}	


//int pos_id_x_ordered[num_cities]; 
//int pos_id_y_ordered[num_cities];


//pos_id_x_ordered
int *pos_id_x_ordered;
pos_id_x_ordered = malloc(num_cities * sizeof(int *));
if(pos_id_x_ordered == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}

//pos_id_y_ordered
int *pos_id_y_ordered;
pos_id_y_ordered = malloc(num_cities * sizeof(int *));
if(pos_id_y_ordered == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}


//for loop to mark the position where the id is in the oredered x array 
	for(i = 0; i < num_cities; i++)
	{
		temp = ordered_x_array[i][0];
		pos_id_x_ordered[temp] = i;
	}

//for loop to mark the position where the id is in the oredered y array 
	for(i = 0; i < num_cities; i++)
	{
		temp = ordered_y_array[i][0];
		pos_id_y_ordered[temp] = i;
	}

	id = 0;
	
/*
for(i=0; i < num_cities; i++)
{
	printf("City Name: %d	X: %d	Y: %d	Visited: %d\n",ordered_x_array[i][0],ordered_x_array[i][1],ordered_x_array[i][2],ordered_x_array[i][3]);
}

for(i=0; i < num_cities; i++)
{
	printf("City Name: %d	X: %d	Y: %d	Visited: %d\n",ordered_y_array[i][0],ordered_y_array[i][1],ordered_y_array[i][2],ordered_y_array[i][3]);
}
*/

//quadrent section
///////////////////////////////////////////////////////////////////////
//if num cities are odd, will need to set this up differently

int half_cities = num_cities/2;


int half_x_point;
int half_y_point;


half_x_point = ordered_x_array[half_cities][1];
half_y_point = ordered_y_array[half_cities][2];


printf("half x point: %d\n", half_x_point);
printf("half y point: %d\n", half_y_point);

int west_count = 0;
int east_count = 0;
int north_count = 0;
int south_count = 0;

for(i = 0; i < num_cities; i++)
{
	if(ordered_x_array[i][1] <= half_x_point)
	{
		west_count++;
	}
}

printf("west count: %d\n", west_count);


for(i = 0; i < num_cities; i++)
{
	if(ordered_y_array[i][2] <= half_y_point)
	{
		south_count++;
	}
}
printf("south count: %d\n", south_count);

east_count = num_cities - west_count;
north_count = num_cities - south_count;

printf("east count: %d\n", east_count);
printf("north count: %d\n", north_count);

int q1 = 0;
int q2 = 0;
int q3 = 0;
int q4 = 0;


for(i = 0; i < num_cities; i++)
{
	if(ordered_x_array[i][1] <= half_x_point)
	{
		if(ordered_x_array[i][2] <= half_y_point)
		{
			q1++;
			//printf("\nid should be q1: %d ", ordered_x_array[i][0]);

		}
		else
		{
			q2++;
			//printf("\nid should be q2: %d ", ordered_x_array[i][0]);
		}
	}
	else
	{
		if(ordered_x_array[i][2] <= half_y_point)
		{
			q4++;
			//printf("\nid should be q4: %d ", ordered_x_array[i][0]);
		}
		else
		{
			q3++;
			//printf("id should be q3: %d ", ordered_x_array[i][0]);
		}
	}
}


int qSum = 0;

qSum = q1+q2+q3+q4;

printf("q1: %d\n", q1);
printf("q2: %d\n", q2);
printf("q3: %d\n", q3);
printf("q4: %d\n", q4);
printf("total: %d\n", qSum);

//need to dynamically allocated these
//int quad1[q1][4];
//int quad2[q2][4];
//int quad3[q3][4];
//int quad4[q4][4];

//dynamically creating the quadrant arrays
///////////////////////////////////////////////////////////////////////////////////////
//quad1
int **quad1;
quad1 = malloc(q1 * sizeof(int *));
if(quad1 == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q1; i++)
	{
		quad1[i] = malloc(4 * sizeof(int));
		if(quad1[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad1_y_ordered
int **quad1_y_ordered;
quad1_y_ordered = malloc(q1 * sizeof(int *));
if(quad1_y_ordered == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q1; i++)
	{
		quad1_y_ordered[i] = malloc(4 * sizeof(int));
		if(quad1_y_ordered[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad2
int **quad2;
quad2 = malloc(q2 * sizeof(int *));
if(quad2 == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q2; i++)
	{
		quad2[i] = malloc(4 * sizeof(int));
		if(quad2[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad2_y_ordered
int **quad2_y_ordered;
quad2_y_ordered = malloc(q2 * sizeof(int *));
if(quad2_y_ordered == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q2; i++)
	{
		quad2_y_ordered[i] = malloc(4 * sizeof(int));
		if(quad2_y_ordered[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad3
int **quad3;
quad3 = malloc(q3 * sizeof(int *));
if(quad3 == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q3; i++)
	{
		quad3[i] = malloc(4 * sizeof(int));
		if(quad3[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad3_y_ordered
int **quad3_y_ordered;
quad3_y_ordered = malloc(q3 * sizeof(int *));
if(quad3_y_ordered == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q3; i++)
	{
		quad3_y_ordered[i] = malloc(4 * sizeof(int));
		if(quad3_y_ordered[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad4
int **quad4;
quad4 = malloc(q4 * sizeof(int *));
if(quad4 == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q4; i++)
	{
		quad4[i] = malloc(4 * sizeof(int));
		if(quad4[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
	
//quad4_y_ordered
int **quad4_y_ordered;
quad4_y_ordered = malloc(q4 * sizeof(int *));
if(quad4_y_ordered == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
for(i = 0; i < q4; i++)
	{
		quad4_y_ordered[i] = malloc(4 * sizeof(int));
		if(quad4_y_ordered[i] == NULL)
		{
			fprintf(stderr, "out of memory\n");
			exit(-1);
		}
	}
///////////////////////////////////////////////////////////////////////////////////////




int q1_spot = 0;
int q2_spot = 0;
int q3_spot = 0;
int q4_spot = 0;



for(i = 0; i < num_cities; i++)
{
	if(ordered_x_array[i][1] <= half_x_point)
	{
		if(ordered_x_array[i][2] <= half_y_point)
		{
			quad1[q1_spot][0] = ordered_x_array[i][0];
			quad1[q1_spot][1] = ordered_x_array[i][1];
			quad1[q1_spot][2] = ordered_x_array[i][2];
			quad1[q1_spot][3] = ordered_x_array[i][3];
			q1_spot++;
			//printf("Made it here. q1_spot: %d\n", q1_spot);
		}
		else
		{
			quad2[q2_spot][0] = ordered_x_array[i][0];
			quad2[q2_spot][1] = ordered_x_array[i][1];
			quad2[q2_spot][2] = ordered_x_array[i][2];
			quad2[q2_spot][3] = ordered_x_array[i][3];
			q2_spot++;
			//printf("Made it here. q2_spot: %d\n", q2_spot);
			
		}
	}
	else 
	{
		if(ordered_x_array[i][2] <= half_y_point)
		{
			quad4[q4_spot][0] = ordered_x_array[i][0];
			quad4[q4_spot][1] = ordered_x_array[i][1];
			quad4[q4_spot][2] = ordered_x_array[i][2];
			quad4[q4_spot][3] = ordered_x_array[i][3];
			q4_spot++;
			//printf("Made it here. q3_spot: %d\n", q3_spot);
			
		}
		else
		{
			quad3[q3_spot][0] = ordered_x_array[i][0];
			quad3[q3_spot][1] = ordered_x_array[i][1];
			quad3[q3_spot][2] = ordered_x_array[i][2];
			quad3[q3_spot][3] = ordered_x_array[i][3];
			q3_spot++;
			//printf("Made it here. q4_spot: %d\n", q4_spot);
			
		}
	}
}

//printf("q1_spot: %d\n", q1_spot);
//printf("q2_spot: %d\n", q2_spot);
//printf("q3_spot: %d\n", q3_spot);
//printf("q4_spot: %d\n", q4_spot);



//filling quadrant arrays for y order
//////////////////////////////////////////////////////////////////////////////
q1_spot = 0;
q2_spot = 0;
q3_spot = 0;
q4_spot = 0;

for(i = 0; i < num_cities; i++)
{
	for(j = 0; j < q1; j++)
	{
		if(ordered_y_array[i][0] == quad1[j][0])
		{
				quad1_y_ordered[q1_spot][0] = ordered_y_array[i][0];
				quad1_y_ordered[q1_spot][1] = ordered_y_array[i][1];
				quad1_y_ordered[q1_spot][2] = ordered_y_array[i][2];
				quad1_y_ordered[q1_spot][3] = ordered_y_array[i][3];
				q1_spot++;
				//printf("made it into q1\n");
		}
	}
	
	for(j = 0; j < q2; j++)
	{
		if(ordered_y_array[i][0] == quad2[j][0])
		{
				quad2_y_ordered[q2_spot][0] = ordered_y_array[i][0];
				quad2_y_ordered[q2_spot][1] = ordered_y_array[i][1];
				quad2_y_ordered[q2_spot][2] = ordered_y_array[i][2];
				quad2_y_ordered[q2_spot][3] = ordered_y_array[i][3];
				q2_spot++;	
				//printf("made it into q2\n");
		}
	}
	
	for(j = 0; j < q3; j++)	
	{
		if(ordered_y_array[i][0] == quad3[j][0])
		{
				quad3_y_ordered[q3_spot][0] = ordered_y_array[i][0];
				quad3_y_ordered[q3_spot][1] = ordered_y_array[i][1];
				quad3_y_ordered[q3_spot][2] = ordered_y_array[i][2];
				quad3_y_ordered[q3_spot][3] = ordered_y_array[i][3];
				q3_spot++;	
				//printf("made it into q3\n");
		}
	}
	
	for(j = 0; j < q4; j++)	
	{
		if(ordered_y_array[i][0] == quad4[j][0])
		{
				quad4_y_ordered[q4_spot][0] = ordered_y_array[i][0];
				quad4_y_ordered[q4_spot][1] = ordered_y_array[i][1];
				quad4_y_ordered[q4_spot][2] = ordered_y_array[i][2];
				quad4_y_ordered[q4_spot][3] = ordered_y_array[i][3];
				q4_spot++;	
				//printf("made it into q4\n");
		}
	}
	
}
//done filling quadrants
/////////////////////////////////////////////////////////////////////////////////////////////



/*
//section for getting the position of id for ordered x and y arrays in quadrants
////////////////////////////////////////////////////////////////////////////////////////////////
//pos_id_x_ordered_q1
int *pos_id_x_ordered_q1;
pos_id_x_ordered_q1 = malloc(q1 * sizeof(int *));
if(pos_id_x_ordered_q1 == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1); 
	}

//pos_id_y_ordered_q1
int *pos_id_y_ordered_q1;
pos_id_y_ordered_q1 = malloc(q1 * sizeof(int *));
if(pos_id_y_ordered_q1 == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}

q1_spot = 0;
int q1_city_id;
//for loop to mark the position where the id is in the ordered x array 
	for(i = 0; i < q1; i++)
	{
		q1_city_id = quad1[i][0];
		pos_id_x_ordered_q1[temp] = i;
		q1_spot++;
	}

//for loop to mark the position where the id is in the oedered y array 
	for(i = 0; i < q1; i++)
	{
		temp = quad1_y_ordered[i][0];
		pos_id_y_ordered_q1[temp] = i;
	}
	
	
printf("Quadrent 1 (pos_id_x_ordered_q1)\n");
for(i = 0; i < q1; i++)
{
	printf("%d ", pos_id_x_ordered_q1[i]);
}

printf("\n\nQuadrent 1 (pos_id_y_ordered_q1)\n");
for(i = 0; i < q1; i++)
{
	printf("%d ", pos_id_y_ordered_q1[i]);
}
	
//done
//////////////////////////////////////////////////////////////////////////////////////
*/
/*
//printing out quadrant sorting
//////////////////////////////////////////////////////////////////////////////
printf("Quadrent 1 (quad1 array)\n");
for(i = 0; i < q1; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad1[i][0],quad1[i][1],quad1[i][2]);
}

printf("\n\nQuadrent 1 (quad1 _y_ordered array)\n");
for(i = 0; i < q1; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad1_y_ordered[i][0],quad1_y_ordered[i][1],quad1_y_ordered[i][2]);
}


printf("\n\nQuadrent 2 (quad2 array)\n");
for(i = 0; i < q2; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad2[i][0],quad2[i][1],quad2[i][2]);
}

printf("\n\nQuadrent 2 (quad2 _y_ordered array)\n");
for(i = 0; i < q2; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad2_y_ordered[i][0],quad2_y_ordered[i][1],quad2_y_ordered[i][2]);
}
	

printf("\n\nQuadrent 3 (quad3 array)\n");
for(i = 0; i < q3; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad3[i][0],quad3[i][1],quad3[i][2]);
}

printf("\n\nQuadrent 3 (quad3 _y_ordered array)\n");
for(i = 0; i < q3; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad3_y_ordered[i][0],quad3_y_ordered[i][1],quad3_y_ordered[i][2]);
}


printf("\n\nQuadrent 4 (quad4 array)\n");
for(i = 0; i < q4; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad4[i][0],quad4[i][1],quad4[i][2]);
}

printf("\n\nQuadrent 4 (quad4 _y_ordered array)\n");
for(i = 0; i < q4; i++)
{
	printf("City ID: %d	X:%d	Y:%d\n", quad4_y_ordered[i][0],quad4_y_ordered[i][1],quad4_y_ordered[i][2]);
}
	
*/
	
	
	


/*
//example of iterating through with the function
	
	for(i = 0; i < num_cities; i++)
	{
	findPath(&lpNextCity, &lpLength, ordered_x_array, ordered_y_array, id, total_length, city_list, num_cities, pos_id_x_ordered, pos_id_y_ordered, cities_left);
	}
*/

//actually running the algorithm
////////////////////////////////////////////////////////////////////////////////////////////////////
tour_count = 1;

//for all quadrants
//q1
cities_left = q1;
lpNextCity = quad1[q1-1][0];
tour[0] = lpNextCity;
	findPath(&tour_count, tour, &lpNextCity, &lpLength, quad1, quad1_y_ordered, id, total_length, city_list, q1, pos_id_x_ordered, pos_id_y_ordered, cities_left);

	
//q2	
lpNextCity = quad2_y_ordered[0][0];
printf("First City in quadrant 2: %d\n", lpNextCity);	
tour[tour_count] = lpNextCity;
tour_count++;

cities_left = q2;


	findPath(&tour_count, tour, &lpNextCity, &lpLength, quad2, quad2_y_ordered, id, total_length, city_list, q2, pos_id_x_ordered, pos_id_y_ordered, cities_left);

//q3	
lpNextCity = quad3[0][0];
printf("First City in quadrant 3: %d\n", lpNextCity);	
tour[tour_count] = lpNextCity;
tour_count++;

cities_left = q3;


	findPath(&tour_count, tour, &lpNextCity, &lpLength, quad3, quad3_y_ordered, id, total_length, city_list, q3, pos_id_x_ordered, pos_id_y_ordered, cities_left);

//q4	
lpNextCity = quad4_y_ordered[q4-1][0];
printf("First City in quadrant 4: %d\n", lpNextCity);	
tour[tour_count] = lpNextCity;
tour_count++;

cities_left = q4;


	findPath(&tour_count, tour, &lpNextCity, &lpLength, quad4, quad4_y_ordered, id, total_length, city_list, q4, pos_id_x_ordered, pos_id_y_ordered, cities_left);


printf("\n\n\nTour\n\n");	
for(i = 0; i < num_cities; i++)
{
	printf("%d ", tour[i]);
}

printf("\n");	


//finding total length

int x1,x2,y1,y2;

distance = 0;
total_length = 0;

for(i = 0; i < num_cities - 1; i++)
{
	final_pos_start = tour[i];
	final_pos_end = tour[i+1];
	
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	total_length += lrint(sqrt(distance));
	
}

	final_pos_start = tour[num_cities - 1];
	final_pos_end = tour[0];
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	printf("\nLast Distance (going home): %d", (lrint(sqrt(distance))));
	
	total_length += lrint(sqrt(distance));
	
	printf("\n\n\nTotal Distance\n\n");
	printf("%d\n", total_length);


/*	
//this next section is for going home (it's old, don't use it)
///////////////////////////////////////////////////////////////////////////////////		
		
		id = lpNextCity;
		
		printf("Last City: %d\n", id);

		distance = (((city_list[id][1] - city_list[0][1])*(city_list[id][1] - city_list[0][1]))+((city_list[id][2] - city_list[0][2])*(city_list[id][2] - city_list[0][2])));

		lpLength += lrint(sqrt(distance));
		
		total_length = lpLength;
		
		printf("Total length: %d\n", total_length);
		
//////////////////////////////////////////////////////////////////////////////////////	
*/

	
/*
//lp edge swap test
///////////////////////////////////////////////////////////////

int tempSwap;
int swapLength;
int k;

int *tourSwap;
tourSwap = malloc(num_cities * sizeof(int *));
if(tourSwap == NULL)
	{
		fprintf(stderr, "out of memory\n");
		exit(-1);
	}
	
for(i = 0; i<num_cities; i++)
{

	tourSwap[i] = tour[i];
}

int rc;
for(rc = 0; rc < num_cities; rc++)
{

	for(j = rc; j<num_cities-1; j++)
	{

		//printf("this should happen a bunch\n");
		tempSwap = tourSwap[j];
		tourSwap[j] = tourSwap[j+1];
		tourSwap[j+1] = tempSwap;
		
		distance = 0;
		swapLength = 0;
		

			
			for(i = 0; i < num_cities - 1; i++)
			{
				final_pos_start = tourSwap[i];
				final_pos_end = tourSwap[i+1];
				
				x1 = city_list[final_pos_start][1];
				y1 = city_list[final_pos_start][2];
				x2 = city_list[final_pos_end][1];
				y2 = city_list[final_pos_end][2];
				
				distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
				swapLength += lrint(sqrt(distance));
				
				
			}

			final_pos_start = tourSwap[num_cities - 1];
			final_pos_end = tourSwap[0];
			x1 = city_list[final_pos_start][1];
			y1 = city_list[final_pos_start][2];
			x2 = city_list[final_pos_end][1];
			y2 = city_list[final_pos_end][2];
			distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
			//printf("\nLast Distance (going home): %d", (lrint(sqrt(distance))));
			
			swapLength += lrint(sqrt(distance));
			printf("swapLength: %d\n",swapLength);

			if(swapLength < total_length)
			{
				printf("Found a lower distance! New Lowest Length: %d\n\n", swapLength);
				
				for(k=0;k<num_cities;k++)
				{
					tour[i] = tourSwap[i];
				}
				//total_length = swapLength;
				//swapLength = 0;
				total_length = swapLength;
			}
			
			swapLength = 0;
		


	}
	
}


distance = 0;
total_length = 0;

for(i = 0; i < num_cities - 1; i++)
{
	final_pos_start = tour[i];
	final_pos_end = tour[i+1];
	
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	total_length += lrint(sqrt(distance));
	
}

	final_pos_start = tour[num_cities - 1];
	final_pos_end = tour[0];
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	//printf("\nLast Distance (going home): %d", (lrint(sqrt(distance))));
	
	total_length += lrint(sqrt(distance));
	
	//printf("\n\n\nTotal Distance\n\n");



	printf("%d\n", total_length);
	
	for(i = 0; i < num_cities; i++)
	{
		printf("%d\n", tour[i]);
	}


//end lp edge swap test
///////////////////////////////////////////////////////////////
*/
	
//let my people go!
/////////////////////////////////////////////////////////////////////

//free city_list	
	for(i = 0; i < num_cities; i++)
	{
		free(city_list[i]);
	}
	free(city_list);

//free ordered_x_array	
	for(i = 0; i < num_cities; i++)
	{
		free(ordered_x_array[i]);
	}
	free(ordered_x_array);
	
//free ordered_y_array	
	for(i = 0; i < num_cities; i++)
	{
		free(ordered_y_array[i]);
	}
	free(ordered_y_array);
	
//free quad1	
	for(i = 0; i < q1; i++)
	{
		free(quad1[i]);
	}
	free(quad1);

//free quad1_y_ordered	
	for(i = 0; i < q1; i++)
	{
		free(quad1_y_ordered[i]);
	}
	free(quad1_y_ordered);
	
//free quad2	
	for(i = 0; i < q2; i++)
	{
		free(quad2[i]);
	}
	free(quad2);
	
//free quad2_y_ordered	
	for(i = 0; i < q2; i++)
	{
		free(quad2_y_ordered[i]);
	}
	free(quad2_y_ordered);
	
//free quad3	
	for(i = 0; i < q3; i++)
	{
		free(quad3[i]);
	}
	free(quad3);

//free quad3_y_ordered	
	for(i = 0; i < q3; i++)
	{
		free(quad3_y_ordered[i]);
	}
	free(quad3_y_ordered);

//free quad4	
	for(i = 0; i < q4; i++)
	{
		free(quad4[i]);
	}
	free(quad4);

//free quad4_y_ordered	
	for(i = 0; i < q4; i++)
	{
		free(quad4_y_ordered[i]);
	}
	free(quad4_y_ordered);
	
//free tour
free(tour);		
	


//////////////////////////////////////////////////////////////////////
	

	return 0; 
}

//void findPath(int *lpNextCity, int *lpLength, int ordered_x_array[][4], int ordered_y_array[][4], int id, int total_length, int city_list[][3], int num_cities, int *pos_id_x_ordered, int *pos_id_y_ordered, int cities_left)

void findPath(int *tour_count, int *tour, int *lpNextCity, int *lpLength, int **ordered_x_array, int **ordered_y_array, int id, int total_length, int **city_list, int num_cities, int *pos_id_x_ordered, int *pos_id_y_ordered, int cities_left)
{
	cities_left--; //minus count of cities left 

	
	
	id = *lpNextCity;
	int start_city = id; 
	int distance; 
	
	int local_tour_count;
	local_tour_count = *tour_count;
//tour[local_tour_count] = id;

	int x, y, x_lower, x_higher, y_lower, y_higher, chosen_x_yVal, chosen_y_xVal, chosen_x, chosen_y;
	int d1, d2, final_x_d, final_y_d;
	int x_lower_y_val, x_higher_y_val;
	int y_lower_x_val, y_higher_x_val; 

	x = city_list[id][1];//starting point x axis 
	y = city_list[id][2];//starting point y axis 
	
//finds position in arry of city id for ordered x array 
	int pos_x; 
	//pos_x = pos_id_x_ordered[id]; 
	for(i = 0; i < num_cities; i++)
	{
		if(ordered_x_array[i][0] == id)
		{
			pos_x = i;
		}
	}
	
//finds position in arry of city id for ordered y array 
	int pos_y; 
	//pos_y = pos_id_y_ordered[id]; 
		for(i = 0; i < num_cities; i++)
	{
		if(ordered_y_array[i][0] == id)
		{
			pos_y = i;
		}
	}

//the id that's passed in gets marked as 1, aka visited, for the ordered arrays 4th column (ie 3), indicating 1 for visited, 0 for not 
	ordered_x_array[pos_x][3] = 1; 
	ordered_y_array[pos_y][3] = 1;

int pos_x_lower =  pos_x;
int pos_x_higher = pos_x; 
int pos_y_lower = pos_y; 
int pos_y_higher = pos_y;

int x_id_lower = id;
int x_id_higher = id;
int y_id_lower = id;
int y_id_higher = id;

int chosen_x_city_id;
int chosen_y_city_id;

////////////////section below itterates through ordered x array to find a higher and lower x city to visit next (to compare to y)

//if the position is the first in the array 
if(pos_x == 0)
{
	x_id_lower = NULL; 

	///////for loop looking for higher x 
	for(i = pos_x+1; i < num_cities; i++)
	{
		if(ordered_x_array[i][3] == 0) //if the higher x city hasn't been vitied 
		{
				x_id_higher = ordered_x_array[i][0]; //that is the closest, non visited, higher x id 
				pos_x_higher = i;
				break;
		
		}
		else if(ordered_x_array[i][3] == 1) //the higher x city has been visited 
		{
			
			x_id_higher = NULL; //there isn't a higher city to visit so we mark it NULL 
		}
		else
		{
			printf("visited flag: %d\n", ordered_x_array[i][3]);
			printf("something went suppppppeeeerrr wrong for finding a x higher\n");
		}
	}
}

//else if the position is the last in the array 
else if (pos_x == num_cities - 1)
{
	x_id_higher = NULL; //if position is in last in array, no x id higher exists 

	///////for loop looking for lower x 
	for(i = pos_x-1; i >= 0; i--)
	{
		if(ordered_x_array[i][3] == 0) //if the lower x city hasn't been vitied 
		{
				x_id_lower = ordered_x_array[i][0]; //that is the closest, non visited, lower x id
				pos_x_lower = i;
				break;

		}
		else if(ordered_x_array[i][3] == 1) //the lower x city has been visited 
		{
			x_id_lower = NULL; //there isn't a lower city to visit so we mark it NULL 
		}
		else
		{
			printf("something went suppppppeeeerrr wrong for finding a x lower\n");
		}
	}
}

//else the position is somehwere in the array and we want to find the next highest and lowest 
else 
{
	///////for loop looking for lower x 
	for(i = pos_x-1; i >= 0; i--)
	{
		if(ordered_x_array[i][3] == 0) //if the lower x city hasn't been vitied 
		{
				x_id_lower = ordered_x_array[i][0]; //that is the closest, non visited, lower x id 
				pos_x_lower = i;
				break;
		}
		else //the lower x city has been visited 
		{
			x_id_lower = NULL; //there isn't a lower city to visit so we mark it NULL 
		}
	}

	///////for loop looking for higher x 
	for(i = pos_x+1; i < num_cities; i++)
	{
		if(ordered_x_array[i][3] == 0) //if the higher x city hasn't been vitied 
		{
				x_id_higher = ordered_x_array[i][0]; //that is the closest, non visited, higher x id 
				pos_x_higher = i;
				break;

		}
		else //the higher x city has been visited 
		{
			x_id_higher = NULL; //there isn't a higher city to visit so we mark it NULL 
		}
	}

}

	if(x_id_lower == NULL) //if there's not a lower x, we need to choose the higher one 
	{
		chosen_x_city_id = x_id_higher;
		
	}
	else if(x_id_higher == NULL) //if there's not a higher x, we need to choose the lower one 
	{
		chosen_x_city_id = x_id_lower;
	}
	else //there is a higher and a lower x, so compute lower distance 
	{
		x_lower = ordered_x_array[pos_x_lower][1];
		x_higher = ordered_x_array[pos_x_higher][1];

		if((abs(x - x_lower)) < (abs(x - x_higher)))//if lower x has smaller difference 
		{
			chosen_x_city_id = x_id_lower;
		}
		else if ((abs(x - x_higher)) < (abs(x - x_lower)))//if higher x has smaller difference 
		{
			chosen_x_city_id = x_id_higher;
		}
		else //is they are same difference b/w higher and lower x and x , so we need to compute difference of points (aka using their y value)
		{
			x_lower_y_val = ordered_x_array[pos_x_lower][2];
			x_higher_y_val = ordered_x_array[pos_x_higher][2];

			d1 = (((x_lower -x)*(x_lower-x))+((x_lower_y_val - y)*(x_lower_y_val -y)));
			d2 = (((x_higher -x)*(x_higher-x))+((x_higher_y_val - y)*(x_higher_y_val -y)));

			if(d1 < d2) //if x lower's distance is less 
			{
				chosen_x_city_id = x_id_lower;
				pos_x = pos_x_lower;
			}
			else if(d2 < d1)
			{
				chosen_x_city_id = x_id_higher;
				pos_x = pos_x_higher;
			}
			else //else distances are the same 
			{
				chosen_x_city_id = x_id_higher; //NOTE: might want to change 
				pos_x = pos_x_higher;
			}
		}

	}

///////////////////end of section that itterates through ordered x array to find a higher and lower x city to visit next (to compare to y)
///////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////section below itterates through ordered y array to find a higher and lower y city to visit next (to compare to x)

//if the position is the first in the array 
if(pos_y == 0)
{
	y_id_lower = NULL; 

	///////for loop looking for higher y
	for(i = pos_y+1; i < num_cities; i++)
	{
		if(ordered_y_array[i][3] == 0) //if the higher y city hasn't been vitied 
		{
				y_id_higher = ordered_y_array[i][0]; //that is the closest, non visited, higher y id 
				pos_y_higher = i;
				break;		
		}
		else //the higher y city has been visited 
		{
			y_id_higher = NULL; //there isn't a higher city to visit so we mark it NULL 
		}
	}
}

//else if the position is the last in the array 
else if (pos_y == num_cities - 1)
{
	y_id_higher = NULL; //if position is in last in array, no y id higher exists 

	///////for loop looking for lower y 
	for(i = pos_y-1; i >= 0; i--)
	{
		if(ordered_y_array[i][3] == 0) //if the lower y city hasn't been vitied 
		{
				y_id_lower = ordered_y_array[i][0]; //that is the closest, non visited, lower y id
				pos_y_lower = i;
				break;		
		}
		else //the lower y city has been visited 
		{
			y_id_lower = NULL; //there isn't a lower city to visit so we mark it NULL 
		}
	}
}

//else the position is somehwere in the array and we want to find the next highest and lowest 
else 
{
	///////for loop looking for lower y
	for(i = pos_y-1; i >= 0; i--)
	{
		if(ordered_y_array[i][3] == 0) //if the lower y city hasn't been vitied 
		{

				y_id_lower = ordered_y_array[i][0]; //that is the closest, non visited, lower y id 
				pos_y_lower = i;
				break;
			
			
		}
		else //the lower y city has been visited 
		{
			y_id_lower = NULL; //there isn't a lower city to visit so we mark it NULL 
		}
	}

	///////for loop looking for higher y 
	for(i = pos_y+1; i < num_cities; i++)
	{
		if(ordered_y_array[i][3] == 0) //if the higher x city hasn't been vitied 
		{
				y_id_higher = ordered_y_array[i][0]; //that is the closest, non visited, higher y id
				pos_y_higher = i;
				break;
			
		}
		else //the higher y city has been visited 
		{
			y_id_higher = NULL; //there isn't a higher city to visit so we mark it NULL 
		}
	}

}




	if(y_id_lower == NULL) //if there's not a lower y, we need to choose the higher one 
	{
		chosen_y_city_id = y_id_higher;
	}
	else if(y_id_higher == NULL) //if there's not a higher y, we need to choose the higher one 
	{
		chosen_y_city_id = y_id_lower;
	}
	else
	{
		y_lower = ordered_y_array[pos_y_lower][2];
		y_higher = ordered_y_array[pos_y_higher][2];
	
		if((abs(y - y_lower)) < (abs(y - y_higher)))//if lower y has smaller difference 
		{
			chosen_y_city_id = y_id_lower;
		}
		else if ((abs(y - y_higher)) < (abs(y - y_lower)))//if higher y has smaller difference 
		{
			chosen_y_city_id = y_id_higher;
		}
		else
		{
			y_lower_x_val = ordered_y_array[pos_y_lower][1];
			y_higher_x_val = ordered_y_array[pos_y_higher][1];

			d1 = (((y_lower - y)*(y_lower-y))+((y_lower_x_val - x)*(y_lower_x_val -x)));
			d2 = (((y_higher -y)*(y_higher-y))+((y_higher_x_val - x)*(y_higher_x_val -x)));

			if(d1 < d2) //if y lower's distance is less 
			{
				chosen_y_city_id = y_id_lower;
				pos_y = pos_y_lower;
			}
			else if(d2 < d1)
			{
				chosen_y_city_id = y_id_higher;
				pos_y = pos_y_higher;
			}
			else //else distances are the same 
			{
				chosen_y_city_id = y_id_higher; //NOTE: might want to change 
				pos_y = pos_y_higher;
			}
		}

	}

	//printf("chosen x city id: %d\n", chosen_x_city_id);
//	printf("chosen y city id: %d\n", chosen_y_city_id);

//compute lower distance between the chosen x y and city 
			d1 = (((city_list[chosen_x_city_id][1] - x)*(city_list[chosen_x_city_id][1] - x))+((city_list[chosen_x_city_id][2] - y)*(city_list[chosen_x_city_id][2] - y)));
			
			d2 = (((city_list[chosen_y_city_id][1] - x)*(city_list[chosen_y_city_id][1] - x))+((city_list[chosen_y_city_id][2] - y)*(city_list[chosen_y_city_id][2] - y)));

			if(d1 < d2) //if y lower's distance is less 
			{
				id = chosen_x_city_id;
				/*
				//printf("x city chosen: %d\n", id);
				if(ordered_x_array[pos_x][3] == 0)
				{
					id = chosen_x_city_id;
				}
				else
				{
					printf("something went wrong\n");
				}*/
			}
			else if(d2 < d1)
			{
				id = chosen_y_city_id;
				/*
				//printf("y city chosen: %d\n", id);
				if(ordered_y_array[pos_y][3] == 0)
				{
					id = chosen_y_city_id;
				}
				else
				{
					printf("something went wrong\n");
				}*/
			}
			else //else distances are the same 
			{
			//	printf("distances are the same\n");
				if(ordered_x_array[pos_x][3] == 0)
				{
					id = chosen_x_city_id;
				}
				else if (ordered_y_array[pos_y][3] == 0)
				{
					id = chosen_y_city_id;	
				}
				else 
				{
					id = chosen_x_city_id;
				}
				
			}

///////////////////end of section that itterates through ordered x array to find a higher and lower x city to visit next (to compare to y)
///////////////////////////////////////////////////////////////////////////////////////////////////////

printf("\nNext city to visit: %d\n\n", id);
//printf("Number of cities left: %d\n", cities_left);

	distance = (((city_list[start_city][1] - city_list[id][1])*(city_list[start_city][1] - city_list[id][1]))+((city_list[start_city][2] - city_list[id][2])*(city_list[start_city][2] - city_list[id][2])));

	//printf("Distance to add to total: %d\n", distance);

	total_length += lrint(sqrt(distance));

	//printf("Current Total length: %d\n", total_length);

	//*lpLength += total_length;
	*lpNextCity = id;
	
	printf("Current Total length: %d\n", total_length);
	
	printf("Tour Count: %d\n", local_tour_count);
	
	tour[local_tour_count] = id;
	*tour_count = *tour_count + 1;

if(cities_left - 1 > 0)
	{
		findPath(tour_count, tour, lpNextCity, lpLength, ordered_x_array, ordered_y_array, id, total_length, city_list, num_cities, pos_id_x_ordered, pos_id_y_ordered, cities_left);
	}

/*	
else 
	{
	//printf("Total length after function runs: %d\n", total_length);

		distance = (((city_list[id][1] - city_list[0][1])*(city_list[id][1] - city_list[0][1]))+((city_list[id][2] - city_list[0][2])*(city_list[id][2] - city_list[0][2])));

		total_length += lrint(sqrt(distance));
		*lpLength = total_length;
		printf("Total length: %d\n", total_length);
		
		
	}

	*/

}

