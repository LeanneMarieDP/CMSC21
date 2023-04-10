#include <stdio.h>

int main(void){

    int days, week;

    printf("One-month Calendar \n");

    // Asks user for the number of days
    // If an input less than 28 or greater than 31 is entered, the programs asks the user again
    do{
        printf("Enter number of days in month: ");
        scanf("%d", &days);

    }while(days < 28 || days > 31 );

    // Asks user for the number of days
    // If an input less than 0 or greater than 7 is entered, the programs asks the user again
    
    do{
        printf("Enter the starting day of the week (1 = Sun, 7 = Sat): ");
        scanf("%d", &week);
    }while(week < 1 || week > 7);

    printf("\n");

    // print a newline before the spaces
    printf("\n");

    // subtract 1 from week to adjust for the first day of the month
    for( int i = 1; i<=week-1; i++){
        printf("   ");
    }

    // loop for prianting the days of the month
    for( int i = 1; i <= days; i ++){
        printf("%3d", i);

        if((i + week - 1) % 7 == 0 ){
            printf("\n");
        }
    }

    return 0;
}
