#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *
 * @array: the array to sort
 * @size: size of the array to sort
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	size_t flag = 1;
	int temp;


	for (i = 0; i < (size - 1) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
	}
}
