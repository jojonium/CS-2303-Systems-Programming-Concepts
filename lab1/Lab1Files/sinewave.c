// FILE:  sinewave.c
// WRITTEN BY: Michael Main(main@colorado.edu), Aug 29, 1995
// MODIFIED BY:  Glynis Hamel to include new-style C++ headers 10/26/00
// MODIFIED BY:  Glynis Hamel to convert from C++ to C 11/01/05
// A demonstration program showing how the intarray toolkit is used.

#include <stdio.h>
#include <math.h>      // Provides sin function
#include <stdlib.h>    // Provides EXIT_SUCCESS
#include "intarray.h"  // Provides histogram function

int main() 
{
    int i;     // for loop control variable
    int a[64]; // Array that contains values of a sin wave

    for (i = 0; i <= 63; i++)
        a[i] = (int) ( (40.0/4.1) * sin(i/10.0) );

    printf ("\nThe function (40/4.1) * sin(x/10), ");
    printf ("for x ranging from 0 to 63:\n\n");
    histogram(a, 64);

    return 0;
}

