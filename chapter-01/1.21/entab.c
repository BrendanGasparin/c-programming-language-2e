#include <stdio.h>

#define COLUMN_SIZE 4
#define CHAR_BUFFER_SIZE 2500

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
    return;
}
