#include <stdio.h>

#define COLUMN_WIDTH 4
#define CHAR_BUFFER_SIZE 2500
#define FALSE 0
#define TRUE 1

int get_line(char s[], int lim);
void entab(char s[]);

int main()
{
    char line[CHAR_BUFFER_SIZE];    // The line buffer
    int length;                     // Length of the line

    while (length = get_line(line, CHAR_BUFFER_SIZE) > 0)
        entab(line);

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

void entab(char s[]) {
    int blank_count = 0;
    int blanks_detected = FALSE;
    int char_count = 0;
    int spaces = 0;
    int tabs = 0;
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        // Current character is a tab
        if (s[i] == '\t') {
            if (char_count % COLUMN_WIDTH == 0)
                blank_count += 4;
            else if (char_count % COLUMN_WIDTH == 1)
                blank_count += 3;
            else if (char_count % COLUMN_WIDTH == 2)
                blank_count += 2;
            else
                blank_count += 1;
            blanks_detected = TRUE;
        }
        // Current character is a space
        else if (s[i] == ' ') {
            blank_count++;
            blanks_detected = TRUE;
        }
        // Blanks detected and current character is not whitespace
        else if (blanks_detected) {
            if (blank_count == 1) {
                printf(" ");
                blank_count--;
                char_count++;
            }
            else if (blank_count % COLUMN_WIDTH == 0) {
                printf("\t");
                blank_count -= 4;
                char_count += 4;
            }
            else if (blank_count % COLUMN_WIDTH == 1) {
                printf("\t");
                blank_count -= 3;
                char_count += 3;
            }
            else if (blank_count % COLUMN_WIDTH == 2) {
                printf("\t");
                blank_count -= 2;
                char_count += 2;
            }
            else {
                printf(" ");
                blank_count--;
                char_count++;
            }

            tabs = blank_count / COLUMN_WIDTH;
            spaces = blank_count % COLUMN_WIDTH;

            for (j = 0; j < tabs; j++) {
                putchar('\t');
                char_count += COLUMN_WIDTH;
            }
            for (j = 0; j < spaces; j++) {
                putchar(' ');
                char_count++;
            }
            blanks_detected = FALSE;
            blank_count = 0;
            putchar(s[i]);
            char_count++;
        }
        // No blanks detected and current character is not whitespace
        else {
            blanks_detected = FALSE;
            blank_count = 0;
            putchar(s[i]);
            char_count++;
        }
    }
}
