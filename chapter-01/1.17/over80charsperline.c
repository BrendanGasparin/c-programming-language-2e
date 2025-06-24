/*
    over80charsperline.c
    Date: Tuesday 24th June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Reads the input and outputs line number and line length for all lines with a length
    greater than 80 characters.
*/

#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500   // Size of character buffer
#define THRESHOLD 80            // Threshold at which to detect lines

int get_line(char c[], int max_size);

int main()
{
    int line_length;
    int line_number = 0;
    char line[CHAR_BUFFER_SIZE];

    while ((line_length = get_line(line, CHAR_BUFFER_SIZE)) > 0) {
        line_number++;
        if (line_length > THRESHOLD)
            printf("%i: %i: %s\n", line_number, line_length, line);
    }
    
    /* for (line_number = 1; line_length = get_line(line, CHAR_BUFFER_SIZE) > 0; line_number++)
        if (line_length > THRESHOLD)
            printf("%li: %li: %s\n", line_number, line_length, line); */
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i, limit;

    for (i = 0, limit = lim - 1; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    s[i] = '\0';

    return i;
}
