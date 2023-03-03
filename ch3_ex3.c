/* Adds two fractions */

#include <stdio.h>

int main(void){

     // Declare variables for two fractions, their numerators and denominators, and the result
    int num1, denom1, num2, denom2, result_num, result_denom;

    // Prompt the user to enter the first fraction
    printf("Enter first fraction: ");
    // Read the numerator and denominator of the first fraction from the user input, using "%d/%d" as the format string
    // %d prints indicates that the input should be interpreted as a decimal integer
    // The & operator before each variable name is used to obtain the address of the variable
    // This was done so that the scanf function can store the input value at the correct memory location
    scanf("%d/%d", &num1, &denom1);

    // Prompt the user to enter the second fraction in the same format
    printf("Enter second fraction: ");
    
    // Read the numerator and denominator of the second fraction from the user input, using "%d/%d" as the format string
    scanf("%d/%d", &num2, &denom2);

    // Calculate the sum of the two fractions
    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;

    // Print the result of the sum of the two fractions
    printf("The sum is %d/%d\n", result_num, result_denom);
    
    return 0;
    }