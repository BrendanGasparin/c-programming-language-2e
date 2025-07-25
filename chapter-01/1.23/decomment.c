/*
    decomment.c
    Date: Sunday 13th July 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Removes C-style comments from text input.
*/

// TODO: Handle nested comments

#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500 // Maximum length of an input line
#define FALSE 0 // False
#define TRUE 1 // True

int get_line(char s[], int lim);

int main()
{
    int forward_slash_detected = FALSE; // Whether a forward slash was just typed outside a comment.
    int asterisk_detected = FALSE;  // Whether an asterisk was just typed within a multiline comment.
    int in_comment = FALSE; // Whether we are in a single line comment.
    int in_ml_comment = FALSE;  // Whether we are in a multiline comment.
    int length; // Length of the current input string.
    char line[CHAR_BUFFER_SIZE];    // The current input string.
    int i;  // Counter.

    while ((length = get_line(line, CHAR_BUFFER_SIZE)) > 0) {
        for (i = 0; i < length; i++) {
            if (line[i] == '/' && i + 1 < length) {
                if (line[i + 1] == '/') {
                    in_comment = TRUE;
                    i++; // Skip next slash
                    continue;
                }
                else if (line[i + 1] == '*') {
                    in_ml_comment = TRUE;
                    i++;    // Skip asterisk
                    continue;
                }
                else {
                    putchar('/');
                    continue;
                }
            }

            // If line breaks during a single line comment, newline and end the comment.
            if (in_comment) {
                if (line[i] == '\n') {
                    putchar('\n');
                    in_comment = FALSE;
                }
                continue;
            }

            if (in_ml_comment && line[i] == '*' && i + 1 < length) {
                if (line[i + 1] == '/') {
                    in_ml_comment = FALSE;
                    i++;
                    continue;
                }
            }

            if (!in_comment && !in_ml_comment) {
                putchar(line[i]);
            }
        }
    }
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
