/*
    detab.c
    Date: Thursday 3rd July 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Converts tabs from the input into an appropriate number of spaces
    in the output.
*/

#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500
#define TRUE 1
#define FALSE 0

void detab(char s[]);
int get_line(char s[], int lim);

int main()
{
    char line[CHAR_BUFFER_SIZE];    // The line buffer

    while (get_line(line, CHAR_BUFFER_SIZE) > 0)
        detab(line);

    return 0;
}

// getline: read a line into s, return length
int get_line(char s[], int lim)
{
    int c, i;
    int limit;

    for (i = 0, limit = lim - 1; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

// Prints the input, converting tabs into the sppropriate number of space characters
void detab(char s[])
{
    int char_count = 0;
    int n;  // Number of spaces to print
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\t') {
            if (char_count % 4 == 0)
                n = 4;
            else if (char_count % 4 == 1)
                n = 3;
            else if (char_count % 4 == 2)
                n = 2;
            else
                n = 1;

            for (j = 0; j < n; j++)
            {
                putchar(' ');
                char_count++;
            }
        }
        else
        {
            putchar(s[i]);
            char_count++;
        }
    }
}
