/*
    wordlenh.c
    Date: Sunday 22nd June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Reads the input and then prints a horizontal histogram
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

    // Output the horizontal histogram
    for (int i = 0; i < highest_count; i++) {
        printf("%i ", i + 1);
        if (i < MAX_DIGIT)
            putchar(' ');
        printf("| ");
        for (int j = 0; j < count[i]; j++)
            printf("#");
        printf("\n");
    }
}