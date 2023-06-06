/* Check Planet Names */

#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[]) {
    // Array of known planet names
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    int i, j;

    // Iterate through command-line arguments
    for (i = 1; i < argc; i++) {
        // Check if each argument matches a known planet name
        for (j = 0; j < NUM_PLANETS; j++) {
            if (strcmp(argv[i], planets[j]) == 0) {
                // If a match is found, print the planet name and its position
                printf("%s is recognized as planet %d\n", argv[i], j + 1);
                break;
            }
        }

        // If no match is found, print that the argument is not a recognized planet
        if (j == NUM_PLANETS) {
            printf("%s is not recognized as a planet\n", argv[i]);
        }
    }

    return 0;
}
