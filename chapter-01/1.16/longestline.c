/*
    longestline.c
    Authors: Brian W. Kernighan and Dennis M. Ritchie
    Source: The C Programming Language 2nd Edition (book)
    Prints the longest line of its input.
*/

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;    /* current line length */
    int max;    /* maximum length seen so far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    // TODO: This gets a length of the string for "Robin lays an egg."
    // But one less for the string "The Batmobile broke its wheel,"
    // It also prints the newline for the latter but not the former
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("%i: %s", max - 1, longest);
    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
