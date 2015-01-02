/*
Project:	CS325 - Project 5
Section:	TSP
File:		tsp_final.c
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
#include <signal.h>

#  define INT_MAX   2147483647

//functions for signal handling
void my_sig_handler(int signum) {
	printf("\nReceived SIGTERM interrupt signal!\n");
	exit(1);
}
void sigintHandler(int sig)
{
printf("\nSIGINT has been caught, terminating the program\n");
exit(1);
}

//for finding hemispheres
int half_x_point; 
int half_y_point;

//place to put cities into in tour array
int tourPlace = 0;

//distance variables
int tempDis;
int distance;
int totalDistance;

//variables for file input and output names
char userInputFileName[50];
char outputFile[100];

//temp variables
int tempCityID, tempXPos, tempYPos;

//used for scanning in the file
char ch[10];
int numCount;

//count of how many cities there are 
int num_cities;
int cities_left; 

//counting variables and place for storing temp
int temp, i, j = 0;

//id of city
int id;

//variable used for calculating total length of tour
int total_length;

//global for knowing what the next city to visit and test for
int lpNextCity;

//variables for counting
int tour_count;
int quad_count;

//variables for cities whose distances are being calculated
int final_pos_start;
int final_pos_end;


//function declaration
void bruteFunc(int *quad_count, int *tour_count, int *tour, int **city_list, int final_pos_start, int tempDis, int num_cities);

int main(int argc, char *argv[])
{

	// When receive signal SIGTERM from watch.py then call my_sig_handler
	signal(SIGTERM, my_sig_handler);
	signal(SIGINT, sigintHandler);

int x1,x2,y1,y2;
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

//done scanning to get the number of cities
////////////////////////////////////////////////////////////////


	
//arrays for storing city info
///////////////////////////////////////////////////////////////////////////////////
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
		
//done scanning in all the cities
////////////////////////////////////////////////////////////



//filling tour, just to make sure it exists
/////////////////////////////////////////////////////////////////////////
for(i=0;i<num_cities;i++)
{
	tour[i]=i;
}
//For creating file to output to (THIS IS REAL)
/////////////////////////////////////////////////////////////////////////////////
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

	//going home distance
	final_pos_start = tour[num_cities - 1];
	final_pos_end = tour[0];
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	
	total_length += lrint(sqrt(distance));
	
		
		FILE *fileToMake;

		fileToMake = fopen(outputFile, "w");
	
		if(fileToMake == NULL)
		{
			fprintf(stderr, "Can't open output file %s!\n", outputFile);
			exit(1);
		}

		fprintf(fileToMake,"%d\n", total_length);
	
		for(i = 0; i < num_cities; i++)
		{
			fprintf(fileToMake,"%d\n", tour[i]);
		}

		fclose(fileToMake);
	distance = 0;
total_length = 0;
//done doing real output
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////




//for filling arrays to be sorted
//////////////////////////////////////////////////////////////////////
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
	
//done filling and sorting
////////////////////////////////////////////////////////////////////////////////////


//figuring out where quadrants should be split up
///////////////////////////////////////////////////////////////////////
int half_cities = num_cities/2;

half_x_point = ordered_x_array[half_cities][1];
half_y_point = ordered_y_array[half_cities][2];

//done spliting quadrants
////////////////////////////////////////////////////////////////////////

//figuring out how many cities in each quadrant
////////////////////////////////////////////////////////////////////////
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
		}
		else
		{
			q2++;
		}
	}
	else
	{
		if(ordered_x_array[i][2] <= half_y_point)
		{
			q4++;
		}
		else
		{
			q3++;
		}
	}
}


int qSum = 0;

qSum = q1+q2+q3+q4;
//done counting for quadrants
///////////////////////////////////////////////////////////////////////////


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

//end creating quadrant arrays
///////////////////////////////////////////////////////////////////////////////////////



//filling quadrant arrays for x ordering
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
		}
		else
		{
			quad2[q2_spot][0] = ordered_x_array[i][0];
			quad2[q2_spot][1] = ordered_x_array[i][1];
			quad2[q2_spot][2] = ordered_x_array[i][2];
			quad2[q2_spot][3] = ordered_x_array[i][3];
			q2_spot++;	
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
		}
		else
		{
			quad3[q3_spot][0] = ordered_x_array[i][0];
			quad3[q3_spot][1] = ordered_x_array[i][1];
			quad3[q3_spot][2] = ordered_x_array[i][2];
			quad3[q3_spot][3] = ordered_x_array[i][3];
			q3_spot++;	
		}
	}
}
//done filling x ordered quadrant array
//////////////////////////////////////////////////////////////////////////////
/*
//getting some tempDis to input into function. Need to start with something
//take the distance from the first city to the second city, then square it. This gives us a large value
////////////////////////////////////////////////////////////////////////////////////////////////


	final_pos_start = city_list[0][0];
	final_pos_end = city_list[1][0];
	
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	total_length += lrint(sqrt(distance));
	tempDis = total_length * total_length;
	tempCityID = city_list[1][0];
//done getting tempDis
/////////////////////////////////////////////////////////////////////////////////////////////////
*/

tempDis = INT_MAX;
//actually running the algorithm
//need to call function for each quadrant
////////////////////////////////////////////////////////////////////////////////////////////////////
tour_count = 1;


//q1
lpNextCity = quad1[q1-1][0];
quad1[q1-1][3] = 1;
tour[0] = lpNextCity;
final_pos_start = lpNextCity;

if(q1>1)
{
	bruteFunc(&quad_count, &tour_count, tour, quad1, final_pos_start, tempDis, q1);
}
else
{
	tour_count++;
}	


//q2	
lpNextCity = quad2[0][0];
final_pos_start = lpNextCity;
tour[tour_count-1] = lpNextCity;
quad2[0][3] = 1;
cities_left = q2;
quad_count = 0;


if(q2>1)
{
	bruteFunc(&quad_count, &tour_count, tour, quad2, final_pos_start, tempDis, q2);
}
else
{
	tour_count++;
}
	
	
//q3	
lpNextCity = quad3[0][0];
final_pos_start = lpNextCity;
tour[tour_count-1] = lpNextCity;
quad3[0][3] = 1;
cities_left = q3;
quad_count = 0;

if(q3>1)
{
	bruteFunc(&quad_count, &tour_count, tour, quad3, final_pos_start, tempDis, q3);
}
else
{
	tour_count++;
}

	
//q4	
lpNextCity = quad4[0][0];
final_pos_start = lpNextCity;	
tour[tour_count-1] = lpNextCity;
quad4[0][3] = 1;
cities_left = q4;
quad_count = 0;


if(q4>1)
{
	bruteFunc(&quad_count, &tour_count, tour, quad4, final_pos_start, tempDis, q4);
}
else
{
	tour_count++;
}

//done running the functions. we now have values in tour array
////////////////////////////////////////////////////////////////////////////////////////////////////

//from the tour, getting the total distance
///////////////////////////////////////////////////////////////////////////////
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

	//going home distance
	final_pos_start = tour[num_cities - 1];
	final_pos_end = tour[0];
	x1 = city_list[final_pos_start][1];
	y1 = city_list[final_pos_start][2];
	x2 = city_list[final_pos_end][1];
	y2 = city_list[final_pos_end][2];
	distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
	
	total_length += lrint(sqrt(distance));
	
//done getting total distance
//////////////////////////////////////////////////////////////////////////////////////////////////////

//For creating file to output to (THIS IS REAL)
/////////////////////////////////////////////////////////////////////////////////
		//FILE *fileToMake;

		fileToMake = fopen(outputFile, "w");
	
		if(fileToMake == NULL)
		{
			fprintf(stderr, "Can't open output file %s!\n", outputFile);
			exit(1);
		}

		fprintf(fileToMake,"%d\n", total_length);
	
		for(i = 0; i < num_cities; i++)
		{
			fprintf(fileToMake,"%d\n", tour[i]);
		}

		fclose(fileToMake);
//done doing real output
//////////////////////////////////////////////////////////////////////////////////

	
//let my people go! (freeing malloced arrays)
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

//free quad2	
	for(i = 0; i < q2; i++)
	{
		free(quad2[i]);
	}
	free(quad2);
	
//free quad3	
	for(i = 0; i < q3; i++)
	{
		free(quad3[i]);
	}
	free(quad3);
	
//free quad4	
	for(i = 0; i < q4; i++)
	{
		free(quad4[i]);
	}
	free(quad4);


//free tour
free(tour);		
	

//done freeing arrays
//////////////////////////////////////////////////////////////////////
		
	return 0; 
}

void bruteFunc(int *quad_count, int *tour_count, int *tour, int **city_list, int final_pos_start, int tempDis, int num_cities)
{ 

//for how many cities in the quadrant
int local_tour_count;
local_tour_count = *quad_count;

int closestCity;
int i;

int local_tour_place;
local_tour_place = final_pos_start;

int x1,x2,y1,y2;
int final_pos_end;

//finding the start city in the array
for(i = 0; i<num_cities; i++)
{
	if(local_tour_place == city_list[i][0])
	{
		final_pos_start = i;
	}
}

//iterating through all cities that have not been visited
//calculating their distance
//determining the closest
///////////////////////////////////////////////////////////////////////////
for(i = 0; i < num_cities; i++)
{
	if(city_list[i][3] == 0)
		{
			final_pos_end = i;
				
			x1 = city_list[final_pos_start][1];
			y1 = city_list[final_pos_start][2];
			x2 = city_list[final_pos_end][1];
			y2 = city_list[final_pos_end][2];
				
			distance = ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1));
			total_length = lrint(sqrt(distance));

			if(total_length < tempDis)
			{
				tempDis = total_length;
				tempCityID = city_list[i][0];	
			}
		}
}

//done going through cities
/////////////////////////////////////////////////////////////////////////	

//finding the position of the next closest city in the quadrant array
for(i = 0; i < num_cities; i++)
{
	if(city_list[i][0] == tempCityID)
	{
		closestCity = i;
	}
}

	tempDis = INT_MAX;
	int tour_placer;
	tour_placer = *tour_count;

	tour[tour_placer] = tempCityID;

	city_list[closestCity][3] = 1;
	

	local_tour_place++;
	local_tour_count++;

	*tour_count = *tour_count+1;
	*quad_count = *quad_count+1;

	final_pos_start = city_list[closestCity][0];

	if(local_tour_count< num_cities)
	{
	bruteFunc(quad_count, tour_count, tour, city_list, final_pos_start, tempDis, num_cities);
	}
	

}


