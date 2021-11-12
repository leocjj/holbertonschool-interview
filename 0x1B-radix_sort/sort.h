#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Given functions */
void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);

/* Auxiliary functions */
int number_of_digits(int n);
int digit_from_number(int n, int position);
int power_recursion(int x, int y);
void sort(int *array, int *buckets, int size, int max_digits);

#endif
