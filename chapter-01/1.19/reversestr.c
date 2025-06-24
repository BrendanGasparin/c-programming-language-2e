/*
    reversestr.c
    Date: Wednesday 25th June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Takes strings as input, reverses them, and outputs them.
*/

#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500   // Maximum length of an input line
#define TRUE 1  // True
#define FALSE 0 // False

int get_line(char s[], int lim);
void reverse_string(char s[]);

int main()
{
    char line[CHAR_BUFFER_SIZE];
    while (get_line(line, CHAR_BUFFER_SIZE) > 0) {
        reverse_string(line);
        printf("%s\n", line);
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

// Reverses the string paramater str
void reverse_string(char str[]) {
    int length;
    int i = 0;
    int j;
    int newline_detected = FALSE;
    
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
        {
            newline_detected = TRUE;
            length = i;
            str[i] = '\0';
            break;
        }
        else
            length = i + 1;
    }

    i = 0;
    j = length - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    i = length;
    if (newline_detected) {
        str[i] == '\n';
        i++;
    }
    str[i] = '\0';
}
