#include "sort.h"
/**
 * swap - swaps pointers
 * @a: pointer to swap
 * @b: pointer to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * heapify - heapifies the array
 * @arr: array to heapify
 * @n: size of the array
 * @i: index to check
 * @size: size again but in size_t format
 */
void heapify(int arr[], int n, int i, size_t size)
{
    int biggest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[biggest])
        biggest = left;

    if (right < n && arr[right] > arr[biggest])
        biggest = right;

    if (biggest != i)
    {
        swap(&arr[i], &arr[biggest]);
        print_array(arr, size);
        heapify(arr, n, biggest, size);
    }
}
/**
 * heap_sort - sorts the heap
 * @array: array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;

    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i, size);
    }

    for (i = size - 1; i >= 0; i--)
    {
        swap(&array[0], &array[i]);
        if (i > 0)
            print_array(array, size);
        heapify(array, i, 0, size);
    }
}
