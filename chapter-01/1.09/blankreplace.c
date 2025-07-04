#include <stdio.h>

#define LAST_NOT_BLANK   0
#define LAST_IS_BLANK    1

int main()
{
    int c;
    int blank_detected = LAST_NOT_BLANK;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t')
        {
            if (!blank_detected)
                putchar(' ');

            blank_detected = LAST_IS_BLANK;
        }
        else
        {
            blank_detected = LAST_NOT_BLANK;
            putchar(c);
        }
    }
}