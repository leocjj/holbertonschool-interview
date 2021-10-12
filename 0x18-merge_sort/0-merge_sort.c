#include "sort.h"
/**
* merge_sort - sorts array of integers in ascending order using the
* Merge Sort algorithm: Top-down.
* @array: to be sorted.
* @size: elements in the array.
* Return: nothing.
*/
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size <= 1)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	recursion(array, size, temp);
	free(temp);
}
/**
 * recursion - Merge Sort using recursion.
 * @array: to be sorted.
 * @size: elements in the array.
 * @temp: array to hold information during merge.
 * Return: nothing.
 */
void recursion(int *array, size_t size, int *temp)
{
	int mid;

	if (size <= 1)
		return;
	mid = size / 2;
	recursion(array, mid, temp);
	recursion(array + mid, size - mid, temp);
	merge_worker(array, size, mid, temp);
}
/**
 * merge_worker - merge two arrays.
 * @array: to merge.
 * @size: elements in the array to merge.
 * @mid: Middle index.
 * @temp: array to hold information during merge.
 * Return: nothing.
 */
void merge_worker(int *array, int size, int mid, int *temp)
{
	int left = 0;
	int right = mid;
	int index;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	for (index = 0; index < size; index++)
	{

		if (right == size)
		{
			temp[index] = array[left];
			left++;
		}
		else if (left == mid)
		{
			temp[index] = array[right];
			right++;
		}
		else if (array[right] < array[left])
		{
			temp[index] = array[right];
			right++;
		}
		else
		{
			temp[index] = array[left];
			left++;
		}
	}
	for (index = 0; index < size; index++)
	{
		array[index] = temp[index];
	}
	printf("[Done]: ");
	print_array(temp, size);
}
