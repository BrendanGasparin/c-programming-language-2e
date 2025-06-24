/*
    fahrtocels.c
    Date: Tuesday 24th June 2025
    Author: Brendan Gasparin <brendan.gasparin@gmail.com>
    Prints a table of Fahrenheit values of 0 to 300 in increments
    of 20, and their corresponding Celsius values.
*/

#include <stdio.h>

float fahrtocels(float f);

int main(void)
{
    float fahr, cels;       // Faherenheit, Celsius
    int lower = 0;          // Lower bound
    int upper = 300;        // Upper bound
    int step = 20;          // Step to increment

    // Print a heading
    printf("\n##############");
    printf("\n FAHR     CELS");
    printf("\n##############\n");
    // Print the table
    for (fahr = lower; fahr <= upper; fahr += step)
    {
        cels = fahrtocels(fahr);
        printf("%5.1f\t%6.1f\n", fahr, cels);
    }
    printf("\n");

    return 0;
}

// Applies the Celsius conversion formula to parameter f, returning the result
float fahrtocels(float f) {
    return (5.0/9.0) * (f - 32.0);
}
