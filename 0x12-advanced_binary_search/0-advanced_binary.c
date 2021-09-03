#include <stdlib.h>
#include<stdio.h>
#include "search_algos.h"
/**
 * print_array - prints the array
 * @array: array to print
 * @i: min, and also iterator
 * @max: the maximum index in the array to print
 */
void print_array(int *array, int i, int max)
{
	while (i < max)
	{
		if (i < max - 1)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
		i++;
	}
}
/**
 * my_binary - helper function
 * @array: the array to binary search on
 * @min: the min index of array
 * @max: the max index of array
 * @value: the value to find
 * Return: - 1 on fail or index
 */
int my_binary(int *array, size_t min, size_t max, int value)
{

	if (max >= min)
	{
		int mid = min + (max - min) / 2;

		if (array[mid] == value)
		{
			print_array(array, min, max);
			return (mid);
		}
		print_array(array, min, max);
		if (array[mid] < value)
			return (my_binary(array, mid + 1, max, value));
		else
			return (my_binary(array, min, mid - 1, value));

	}
	return (-1);
}
/**
 * advanced_binary - helper function
 * @array: the array to binary search on
 * @size: the size of the array
 * @value: the value to find
 * Return: 1 on fail or index
 */
int advanced_binary(int *array, size_t size, int value)
{
	return (my_binary(array, 0, size, value));
}
