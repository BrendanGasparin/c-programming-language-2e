/*
    blankcounter.c
    Date: Saturday 21st June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Reads the input until the end of files.
    Outputs the number of blank spaces, tabs, and newlines
*/

#include <stdio.h>

int main()
{
    int c;              // Character input
    int blanks = 0;     // Number of blank spaces
    int tabs = 0;       // Number of tabs
    int newlines = 0;   // Number of newlines

    // Count blanks, tabs, and newlines
    while((c = getchar()) != EOF) {
        if (c == ' ')
            blanks++;
        if (c == '\t')
            tabs++;
        if (c == '\n')
            newlines++;
    }

    // Output counts
    printf("Blanks: %i\n", blanks);
    printf("Tabs: %i\n", tabs);
    printf("Newlines: %i\n", newlines);
}