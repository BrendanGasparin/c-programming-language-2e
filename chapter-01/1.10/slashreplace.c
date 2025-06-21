/*
    slashreplace.c
    Date: Sunday 22nd June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Reads the input and outputs it, changing tabs to '\t',
    backspaces to '\b', and backslashes to '\\'.
*/

#include <stdio.h>

int main()
{
    int c;  // Character input

    // Read character input and output appropriate character
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }
}
