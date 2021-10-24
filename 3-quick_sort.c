#include "sort.h"

/**
 * part - partitions an array at given pivot
 * @array: array of integers
 * @start: starting index.
 * @end: ending index.
 * @size: size of array
 *
 * Return: pivot Index.
 */
int part(int *array, int start, int end, size_t size)
{
	int i, pIndex = start, pivot = array[end], temp = 0;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			temp = array[i];
			array[i] = array[pIndex];
			array[pIndex] = temp;
			pIndex++;
			print_array(array, size);
		}
	}
	temp = array[pIndex];
	array[pIndex] = array[end];
	array[end] = temp;

	return (pIndex);
}

/**
 * quicksort_r - recursively calls part to sort an array of integers.
 * @array: array of integers
 * @start: start index
 * @end: end index
 * @size: size of array
 */
void quicksort_r(int *array, int start, int end, size_t size)
{
	int  pIndex = 0;

	if (start < end)
	{
		pIndex = part(array, start, end, size);
		quicksort_r(array, start, pIndex - 1, size);
		quicksort_r(array, pIndex + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * quick sort algorithm.
 *
 * @array: an array of integers.
 * @size: size of array.
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort_r(array, 0, (int)size - 1, size);
}
