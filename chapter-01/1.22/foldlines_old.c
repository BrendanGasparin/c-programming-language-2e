#include <stdio.h>

#define CHAR_BUFFER_SIZE 2500
#define COLUMN_CUTOFF 20
#define COLUMN_WIDTH 4
#define FALSE 0
#define TRUE 0

void foldline(char s[], int index);
int get_line(char s[], int lim);

int main()
{
    char line[CHAR_BUFFER_SIZE];    // The line buffer

    while (get_line(line, CHAR_BUFFER_SIZE) > 0)
        foldline(line, 0);

    return 0;
}

// Recursive function that folds a line every COLUMN_CUTOFF number of COLUMN_WIDTHs
void foldline(char s[], int index)
{
    int nonblank_detected;
    int col = 0;
    int space = 0;
    int i = index, j;

    // SEGFAULT PLUS NOT COUNTING EXTRA SPACES FOR TAB COLUMNS - RESTART?
    while (s[i] != '\0') {
        if (s[i] == ' ' || s[i] == '\t') { 
            nonblank_detected = FALSE;

            for (j = i + 1; s[j] != '\0' && (j + 1) % (COLUMN_CUTOFF * COLUMN_WIDTH) != 0; j++) {
                if (s[j] != ' ' && s[j] != '\t') {
                    nonblank_detected = TRUE;
                    break;
                }
            }

            if (!nonblank_detected)
                putchar(s[i]);
        }
        if ((i + 1) % (COLUMN_CUTOFF * COLUMN_WIDTH) == 0) {
            putchar('\n');
            foldline(s, i);
        }

        if ((i + 1) % (COLUMN_CUTOFF * COLUMN_WIDTH) != 0 && s[i] != ' ' && s[i] != '\t')
            putchar(s[i]);
        i++;
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

