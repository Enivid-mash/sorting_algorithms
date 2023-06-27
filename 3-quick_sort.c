#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - Partitions the array and returns the pivot index
 *
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort
 *
 * @array: Array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
