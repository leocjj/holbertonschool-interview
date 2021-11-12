#include "sort.h"
/**
* radix_sort - sorts an array of integers in ascending order
* using the LSD Radix sort algorithm.
* @array: array of integers >= 0 to be sorted
* @size: number of elements in the array
* Return: Nothing
*/
void radix_sort(int *array, size_t size)
{
	int *buckets;
	int max_digits = 0, digit_actual_number, i;

	if (!array || size < 2)
		return;

	buckets = malloc(sizeof(int) * 10);

	if (!buckets)
		return;

	for (i = 0; i < 10; i++)
		buckets[i] = 0;

	for (i = 0; i < (int)size; i++)
	{
		digit_actual_number = number_of_digits(array[i]);
		if (digit_actual_number > max_digits)
			max_digits = digit_actual_number;
	}

	sort(array, buckets, (int)size, max_digits);
}
/**
 * number_of_digits - number of digits in a number
 * @n: number
 * Return: number of digits in a number
*/
int number_of_digits(int n)
{
	int digits = 0, result = n;

	do {
		result = result / 10;
		digits++;
	} while (result != 0);

	return (digits);
}
/**
 * digit_from_number - specific digit from a number
 * @n: number
 * @position: position
 * Return: digit of specific position
*/
int digit_from_number(int n, int position)
{
	int result;
	int power;

	power = power_recursion(10, position - 1);
	result = (n / power) % 10;

	return (result);
}
/**
 * power_recursion - power with recursion
 * @x: base
 * @y: exponent
 * Return: x to the power of y
 */
int power_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	else if (y < 0)
		return (-1);

	return (x * power_recursion(x, y - 1));
}
/**
 * sort - Sorting function
 * @array: array
 * @buckets: array of numbers from 0 to 9
 * @size: number of elements in the array
 * @max_digits: maximum number of digits in the array
 * Return: Nothing
*/
void sort(int *array, int *buckets, int size, int max_digits)
{
	int *sorted_array;
	int iteration, i, digit;

	sorted_array = malloc(sizeof(int) * size);

	if (!sorted_array)
	{
		free(buckets);
		return;
	}

	for (iteration = 1; iteration <= max_digits; iteration++)
	{
		for (i = 0; i < 10; i++)
			buckets[i] = 0;

		for (i = 0; i < size; i++)
		{
			digit = digit_from_number(array[i], iteration);
			buckets[digit] += 1;
		}

		for (i = 1; i < 10; i++)
			buckets[i] += buckets[i - 1];

		for (i = (size - 1); i >= 0; i--)
		{
			digit = digit_from_number(array[i], iteration);
			sorted_array[buckets[digit] - 1] = array[i];
			buckets[digit] -= 1;
		}

		for (i = 0; i < size; i++)
			array[i] = sorted_array[i];

		print_array(array, size);
	}
	free(buckets);
	free(sorted_array);
}
