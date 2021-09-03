#include "search_algos.h"
/**
* advanced_binary - searches for a value in a sorted array of integers.
* @array: pointer to the first element of the array to search in
* @size: number of elements in array
* @value: value to search for
* Return: index where value is located.
* If value is not present in array or if array is NULL, return -1
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, middle, index = 0;
	int tmp;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
	if (i == size - 1)
		printf("%d\n", array[i]);
	else
		printf("%d, ", array[i]);
	}

	if (size == 1 && array[0] != value)
		return (-1);
	middle = (size - 1) / 2;
	if (array[middle] == value)
	{
		if (array[middle - 1] < value)
			return (middle);
	}
	if (array[middle] < value)
	{
		index += middle + 1;
		array += middle + 1;
		if (size % 2 != 0)
			middle--;
	}
	middle++;
	tmp = advanced_binary(array, middle, value);
	if (tmp != -1)
		return (tmp + index);
	return (-1);
}
