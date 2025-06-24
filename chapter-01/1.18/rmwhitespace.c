/*
    rmwhitespace.c
    Date: Wednesday 25th June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Takes the input and prints it to the output, removing blank lines 
    and trailing spaces and tabs.
*/

#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500
#define TRUE 1
#define FALSE 1

int get_line(char s[], int lim);
void print_stripped(char s[], int max);

int main()
{
    char line[CHAR_BUFFER_SIZE];

    while ((get_line(line, CHAR_BUFFER_SIZE)) > 0)
    {
        print_stripped(line, CHAR_BUFFER_SIZE);
    }

    return 0;
}

// getline: read a line into s, return length
int get_line(char s[], int lim)
{
    int c, i, limit;

    for (i = 0, limit = lim - 1; i < limit && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

// Strip trailing space and newlines and print to output
void print_stripped(char s[], int max)
{
    int i;
    int dead_space = 0;
    int dead_space_detected = FALSE;

    if (s[0] == '\n')
        return;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ' || s[i] == '\t') {
            dead_space++;
            dead_space_detected = TRUE;
        }
        else if (s[i] == '\n')
            s[i] == '\0';
        else {
            dead_space_detected = FALSE;
            dead_space = 0;
        }
    }
        
    if (dead_space_detected)
        s[i - dead_space - 1] = '\0';

    printf("%s\n", s);

    return;
}
