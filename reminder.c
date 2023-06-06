/* Prints a one-month reminder list */

#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50 /* maximum number of reminders*/ 
#define MSG_LEN 60  /* max length of reminder message */ 

int read_line(char str[], int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN + 3]; 
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;
    
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n"); // Print error message if reminder limit reached
            break; // Exit loop
        }
        
        printf("Enter day and reminder: ");
        scanf("%2d", &day); // Read the day from user input
    
        if (day == 0)
            break; // Exit loop if day is 0
            
        sprintf(day_str, "%2d", day); // Convert day to a formatted string
        
        read_line(msg_str, MSG_LEN); // Read the reminder message from user input
        
        // Find the correct position to insert the reminder based on day
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
                
        // Shift reminders to make space for the new reminder
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);
            
        // Store the day and reminder in the reminders array
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        
        num_remind++; // Increment the number of reminders
    }
    
    printf("\nDay Reminder\n");
    
    // Print all the reminders stored in the reminders array
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
        
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    
    // Read characters until a newline or end of input is encountered
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
            
    str[i] = '\0'; // Add null terminator to mark the end of the string
    return i; // Return the length of the string
}
