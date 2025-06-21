/*
    wordperline.c
    Date: Sunday 22nd June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Takes the standard input and prints one word per line to output.
*/

#include <stdio.h>

#define FALSE   0   // False
#define TRUE    1   // True

int main()
{
    int c;
    int last_was_space = TRUE;

    // For each character in the input
    while ((c = getchar()) != EOF) {
        // Print a newline if space, tab, or newline is found
        // But only if a newline was not just outputted
        if (c == ' ' || c == '\t' || c == '\n') {
            if (last_was_space == FALSE) {
                putchar('\n');
                last_was_space = TRUE;
            }
        }
        // Otherwise print the character
        else if (c != '.' && c != '!' && c != '?' && c != ':' && c != ';' && c != '\'' && c != '\"' && c != ',') {
            putchar(c);
            last_was_space = FALSE;
        }
    }
}
