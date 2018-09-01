// FILE: intarray.cxx
// WRITTEN BY: Michael Main(main@colorado.edu), Aug 29, 1995)
// MODIFIED BY:  Glynis Hamel to include new-style C++ headers
// MODIFIED BY:  Glynis Hamel to convert from C++ to C 11/01/05
// IMPLEMENTS: Toolkit of integer array functions (see intarray.h)

#include <stdio.h> 
#include <assert.h>     // Provides assert
#include "intarray.h"

int index_of_maximum(const int array[], int size) 
// Library facilties used: assert.h
{
    int i;      // An array index
    int answer; // Index of the largest element in array[0]..array[size-1]

    assert(size > 0);
    answer = 0;
    for (i = 1; i < size;  i++)
        if (array[i] > array[answer]) answer = i;
    return answer;
}

int index_of_minimum(const int array[], int size) 
// Library facilities used: assert.h
{
    int i;      // An array index
    int answer; // Index of the smallest element in array[0]..array[size-1]
  
    assert(size > 0);
    answer = 0;
    for (i = 1; i < size; i++)
        if (array[i] < array[answer]) answer = i;
    return answer;
}

static void swap_ints(int *a, int *b) 
// Postcondition: The values of a and b have been interchanged.
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int array[], int size) 
// Library facilities used: assert.h, stdio.h
{
    int i;         // An index of an array element
    int big_index; // The index of the biggest array element

    assert(size >= 0);
    for (i = size; i > 1; i--)
    {
        big_index = index_of_maximum(array, i);
        swap_ints(&array[i-1], &array[big_index]);
    }
}

static void print_row(const int array[], int size, int limit)
// Precondition: array is an array of at least size integers
// Postcondition: One line of output has been printed to stdout,
// with one character for each of array[0] through array[size-1].
// Each character is a blank (if the array location is < limit) or
// a star (if the array location is >= limit). 
// Library facilities used: stdio.h
{
    int i; // loop control variable

    //out.width(7);
    printf ("%7d", limit);
    printf (" |");
    for(i = 0; i < size; i++)
        if (array[i] >= limit) printf ("*");
        else printf (" ");
    printf ("\n");;
}

static void print_neg_row(const int array[], int size, int limit) 
// Library facilities used: stdio.h
{
    int i;
    // out.width(7);
    printf ("%7d", limit);
    printf (" |");
    for (i = 0; i < size; i++)
        if (array[i] <= limit) printf ("*");
        else printf (" ");
    printf ("\n");;
}

void histogram(const int array[], int size)
// Library facilities used: assert.h, stdio.h
{
    int i, big_value, wee_value;
    assert(size > 0);
    assert(size <= 70);
    big_value = array[index_of_maximum(array, size)];
    for (i = big_value; i > 0; i--)
        print_row(array, size, i);
    printf ("        |");
    for (i = 0; i < size; i++)
        if ((i%10) == 0) printf ("+");
        else printf ("-");
    printf ("\n");;
    wee_value = array[index_of_minimum(array, size)];
    for (i = -1; i >= wee_value; i--)
        print_neg_row(array, size, i);
}

