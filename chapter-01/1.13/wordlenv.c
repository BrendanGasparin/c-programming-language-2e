/*
    wordlenv.c
    Date: Monday 23rd June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Reads the input and then prints a vertical histogram
    of the occurence of words of particular lengths.
*/

#include <stdio.h>

#define MAX_WORD_LENGTH 45  // Maximum length of a word
#define MAX_DIGIT       9   // Maximum value of a single digit

int main()
{
    int c;                      // Character buffer
    int char_count = 0;         // Character count for current word
    int highest_count;          // The highest number of characters counted so far
    int highest_occurences;     // The greatest number of occurences of a particular word length

    // Declare and initialise count array
    int count[MAX_WORD_LENGTH];
    for (int i = 0; i < MAX_WORD_LENGTH; i++)
        count[i] = 0;


    // Move through text file, remembering the number of words of each length
    while ((c = getchar()) != EOF) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '\'' || c == '-')
            char_count++;
        if (c == ' ' || c == '\t' || c == '\n') {
            count[char_count - 1]++;
            if (char_count > highest_count)
                highest_count = char_count;
            char_count = 0;
        }
    }

    // Get the highest number of occurences of any word length
    highest_occurences = 0;
    for (int i = 0; i < highest_count; i++)
        if (count[i] > highest_occurences)
            highest_occurences = count[i];

    // Output the header
    printf("\n*********************\n");
    printf("WORD LENGTH HISTOGRAM\n");
    printf("*********************\n\n");
    // Output the vertical histogram
    for (int row = highest_occurences; row > 0; row--) {
        for (int col = 0; col < highest_count; col++) {
            if (count[col] >= row)
                printf("#  ");
            else
                printf("   ");
        }
        putchar('\n');
    }
    // Output the key
    for (int col = 0; col < highest_count - 1; col++)
        printf("---");
    printf("--");
    putchar('\n');
    for (int col = 0; col < highest_count; col++) {
        printf("%i ", col + 1);
        if (col < MAX_DIGIT)
            putchar(' ');
    }
    printf("\n\n");
}
