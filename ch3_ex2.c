/* Prints int and float values in various formats*/

#include <stdio.h>

int main(void){
    // Declares i as an integer
    int i;
    // Declares x as a floating-point variable
    float x;

    // Assign values to i and x
    i = 40;
    // The 'f' suffix explicitly declared x as a float type
    x = 839.21f;

    // Print the value of i in various formats
    // %d prints an integer
    // %5d prints an integer in a 5-character-wide field. Only three spaces were added since i needed two characters
    // %-5d prints an integer left-justified in a 5-character-wide field. The spaces were added afterward since i doesn't require five characters
    // %5.3d prints an integer in a 5-character-wide field with 3 digits after the decimal point. A zero was added since i is only two digits long.
    printf("|%d|%5d|%-5d|%5.3d|\n", i,i,i,i);

    // Print the value of x in various formats
    // %10.3f prints a float in a 10-character-wide field with 3 digits after the decimal point
    // %10.3e prints a float in scientific notation in a 10-character-wide field with 3 digits after the decimal point
    // %-10g prints a float left-justified in a 10-character-wide field
    printf("|%10.3f|%10.3e|%-10g|\n",x,x,x);

    return 0;
    }