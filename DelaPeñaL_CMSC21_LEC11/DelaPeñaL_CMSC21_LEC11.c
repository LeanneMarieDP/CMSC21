#include <stdio.h>
#include <stdbool.h> // for boolean data types
#include <ctype.h> /*toupper, isalpha*/

// Function that scans the user input and update the occurrences array
void scan_word(int* occurrences){
    // Pointers were used to directly modify the array elements by passing the memory address
    // of the first element of the arrays `occurrences1` and `occurrences2` to the functions.
    // Doing so, the functions can directly modify the elements of the arrays without the need for returning and assigning values.
    char c;

    while ((c =getchar()) !='\n'){ //the function reads the characters until a newline character
        if(isalpha(c)){ // Checks if the character is alphabetic
            occurrences[toupper(c) - 'A']++; // convert a character to its uppercase equivalents
        }
    }
}

// Function that checks if occurrences1 and occurrences2 are anagrams
bool is_anagram(const int* occurrences1, const int* occurrences2){
    for(int i = 0; i < 26; i++){ //iterates each letter
        // If the count of a particular letter is different in the two words,
        if(occurrences1[i] != occurrences2[i]){
            return 0; // they are not anagrams
        }

    }
    //otherwise, they are are anagrams
    return 1;
}

int main(void) {
    int occurrences1[26] = {0}; // array that will store the letter occurrences in the first inputted word
    int occurrences2[26] = {0}; // array that will store the letter occurrences in the second inputted word

    //ask user for two words 
    printf("Enter first word: ");
    //scan_word function was called to update the array
    scan_word(occurrences1);

    printf("Enter second word: ");
    //scan_word function was called to update the array
    scan_word(occurrences2);

    //is_anagram function was called to compare the two arrays
    if(is_anagram(occurrences1, occurrences2)){
        printf("The words are anagrams. \n");
    }else{
        printf("The words are not anagrams. \n");
    }
    return 0;
}

