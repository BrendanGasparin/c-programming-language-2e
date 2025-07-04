/*
    cels2fahr.c
    Date: Friday 20th June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Print Celsius to Fahrenheit table
    for celsius = 0, 20, ..., 300
*/

#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;

    // Print table
    printf("***************************\n");
    printf("Celsius to Fahrenheit Table\n");
    printf("***************************\n");
    while (celsius <= upper) {
        fahr = celsius * 9.0 / 5.0 + 32.0;
        printf("%7.0f %13.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
