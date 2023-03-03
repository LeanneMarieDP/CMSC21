#include <stdio.h>

int main(void){
    // Declares i and j as integers
    int i, j;
    // Declares x and y as floating-point variables  
    float x,y;
    
    // Set the values of i j, x, and y 
    i = 10;
    j = 20;
    // The 'f' suffix explicitly declared x and y as float types
    x = 43.2892f;
    y = 5527.0f;
    
    // Print the values of i, j, x, and y using the printf function and conversion specifications 
    printf("i = %d, j = %d, x = %f, y = %f\n", i,j,x,y);
    // %d - used to print an integer value
    // %f - used to print a floating point value
    // \n - used to print a new line character
    }