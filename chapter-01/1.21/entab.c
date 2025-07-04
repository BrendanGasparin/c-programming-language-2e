#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500
#define COLUMN_WIDTH 4
#define FALSE 0
#define TRUE 1

void entab(char s[]);
int get_line(char s[], int lim);

int main()
{
    char line[CHAR_BUFFER_SIZE];    // The line buffer

    while (get_line(line, CHAR_BUFFER_SIZE) > 0)
        entab(line);

    return 0;
}

void entab(char s[]) {
    int space = 0;  // Total running space
    int col = 0;    // Tracks current column
    int i =0;       // Counters

    while (s[i] != '\0') {
        if (s[i] == ' ') {
            space++;
        }
        else if (s[i] == '\t') {
            // Work out spaces til next tab stop
            // First, flush any accumulated space
            while (space > 0) {
                int space_to_next_col = COLUMN_WIDTH - col % COLUMN_WIDTH;
                if (space >= space_to_next_col) {
                    putchar('\t');
                    col += space_to_next_col;
                    space -= space_to_next_col;
                }
                else {
                    putchar(' ');
                    col++;
                    space--;
                }
            }

            space = 0;
            putchar('\t');
            col += COLUMN_WIDTH - col % COLUMN_WIDTH;
        }
        // If there is accumulated space and the current character is non-space:
        else if (space > 0) {
            while (space > 0) {

                int space_to_next_col = COLUMN_WIDTH - col % COLUMN_WIDTH;
                if (space >= space_to_next_col) {
                    putchar('\t');
                    col += space_to_next_col;
                    space -= space_to_next_col;
                }
                else {
                    putchar(' ');
                    col++;
                    space--;
                }
            }

            space = 0;

            // Print the non-space character:
            putchar(s[i]);
            if (s[i] == '\n')
                col = 0;
            else
                col++;
        }
        // If there is no accumulated space and the current character is non-space:
        else {
            putchar(s[i]);
            if (s[i] == '\n')
                col = 0;
            else
                col++;
        }
        i++;
    }

    // Handle any trailing whitespace at the end of input
    while (space > 0) {
        int space_to_next_col = COLUMN_WIDTH - col % COLUMN_WIDTH;
        if (space >= space_to_next_col) {
            putchar('\t');
            col += space_to_next_col;
            space -= space_to_next_col;
        }
        else {
            putchar(' ');
            col++;
            space--;
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
