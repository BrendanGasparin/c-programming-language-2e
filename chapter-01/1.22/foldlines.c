/*
    foldlines.c
    Date: Saturday 12th July 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Folds lines of input so that no line is over 80 characters long
    and no line ends with trailing whitespace.
*/

#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500
#define COLUMN_WIDTH 4
#define FALSE 0
#define TRUE 1

void foldline(char s[], int start, int num_cols);
int get_line(char s[], int lim);

int main()
{
    char line[CHAR_BUFFER_SIZE];    // The line buffer.

    // While there is input, fold lines.
    while (get_line(line, CHAR_BUFFER_SIZE) > 0)
        foldline(line, 0, 20);

    return 0;
}

void foldline(char s[], int start, int num_cols)
{
    int count = 0;  // Character count (with 1-4 characters for each tab).
    int nextfold;   // Space until the next fold.
    int space_til_fold; // Space until the next fold.
    int characters_til_fold;    // Characters until the next fold.
    int char_detected;  // Whether or not non-whitespace is detected before the fold.
    int c;      // Current character.
    int i, j;   // Counters.

    for (i = 0; s[i] != '\0'; i++) {
        // If we are at the fold, put in a newline
        if (count % (num_cols * COLUMN_WIDTH) == 0 && count != 0) {
            putchar('\n');
        }
        // If there is nothing but whitespace until the end of the fold, put in a newline:
        if (s[i] == ' ' || s[i] == '\t') {
            char_detected = FALSE;
            nextfold = ((i /(num_cols * COLUMN_WIDTH)) * (num_cols * COLUMN_WIDTH)) + (num_cols * COLUMN_WIDTH);
            space_til_fold = 0;

            for (j = i; s[j] != '\0' && j < nextfold; j++) {
                if (s[j] != ' ' && s[j] != '\t' && s[j] != '\n') {
                    char_detected = TRUE;
                    break;
                }
                if (s[j] == ' ') {
                    space_til_fold++;
                    characters_til_fold++;
                }
                else if (s[j] == '\t') {
                    space_til_fold += COLUMN_WIDTH - ((count + space_til_fold) % COLUMN_WIDTH);
                    characters_til_fold++;
                }
            }
            if (!char_detected) {
                count += space_til_fold;
                j += characters_til_fold;
                putchar('\n');
                count = 0;
                break;
            }
            // Handle spaces and tabs
            else if (s[i] == ' ') {
                putchar(s[i]);
                count++;
            }
            else if (s[i] == '\t') {
                putchar(s[i]);
                count += COLUMN_WIDTH - count % COLUMN_WIDTH;
            }
        }
        // Output non-whitespace character
        else {
            putchar(s[i]);
            count++;
            if (s[i] == '\n')
                count = 0;
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
