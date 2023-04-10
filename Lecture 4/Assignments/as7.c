#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define NUM_VERTICES 8
#define ROAD_NETWORKS_SIZE NUM_VERTICES
  
#define CHARGING_STATION_C 'c'
#define CHARGING_STATION_D 'd'
  
/*  2D array that represents the road network.
 Each row and column represents a vertex, and the values indicate whether there is a road between the vertices.
 The values in the third and fourth rows represent the charging stations.*/ 
int road_networks[ROAD_NETWORKS_SIZE][ROAD_NETWORKS_SIZE] = { 
{1, 1, 0, 0, 0, 1, 0, 0},	// a
{1, 1, 1, 0, 0, 0, 0, 0},	// b
{0, 1, 1, 0, 1, 1, 0, 0},	// c [charging station]
{0, 0, 0, 1, 1, 0, 0, 0},	// d [charging station]
{0, 0, 1, 1, 1, 0, 0, 0},	// e
{1, 0, 1, 0, 0, 1, 0, 0},	// f
{1, 0, 0, 1, 0, 0, 1, 0},	// g
{0, 0, 0, 0, 0, 1, 0, 1}	// h
};


 
// array that maps the index of a vertex in the road network matrix to its character representation.
char charging_stations[NUM_VERTICES] =
  { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };

 
int
main ()
{
  
    // Display adjacency matrix
    printf ("Road Network:\n");
  
printf ("     %c   %c  [%c] [%c]  %c   %c   %c   %c\n",
	   charging_stations[0], charging_stations[1], CHARGING_STATION_C,
	   CHARGING_STATION_D, charging_stations[4], charging_stations[5],
	   charging_stations[6], charging_stations[7]);
  
for (int i = 0; i < ROAD_NETWORKS_SIZE; i++)
    {
      
if (i == 2 || i == 3)
	{
	  
printf ("[%c] ", charging_stations[i]);	// print vertex character with brackets on the left of 'c' and 'd'
	}
      else
	{
	  
printf (" %c  ", charging_stations[i]);	// print vertex character
	}
      
for (int j = 0; j < ROAD_NETWORKS_SIZE; j++)
	{
	  
if ((j == 2 || j == 3) || (i == 2 || i == 3))
	    {
	      
printf ("[%d] ", road_networks[i][j]);	// print adjacency matrix value with brackets
	    }
	  else
	    {
	      
printf (" %d  ", road_networks[i][j]);	// print adjacency matrix value
	    }
	
}
      
printf ("\n");
    
}
  
 
printf ("\n");
  
 
// Prompt user for input
printf("Which point are you located? 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G, 7 - H\n\n");
int point_index;
scanf("%d", &point_index);


// Find nearest charging station for the selected point
char point = charging_stations[point_index];
int nearest_index = -1;
int shortest_distance = INT_MAX;

printf("At point: %c \n", point);

// iterate through each charging station and find the closest one to the current point
for (int j = 0; j < ROAD_NETWORKS_SIZE; j++) {
    if ((charging_stations[j] == CHARGING_STATION_C || charging_stations[j] == CHARGING_STATION_D)) { // check if the current vertex is a charging station
        int distance = abs(j - point_index); // calculate distance between charging station and current point
        if (distance < shortest_distance) {
            nearest_index = j;
            shortest_distance = distance;
        }
    }
}

// print result for selected point
if (nearest_index == -1) {
    printf("No nearest charging station found for point %c\n", point);
} else {
    char nearest = charging_stations[nearest_index];
    printf("point: %c arrived to charging station \n", nearest);
}

 
return 0;

}


 
