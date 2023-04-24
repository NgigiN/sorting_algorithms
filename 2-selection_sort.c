#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the selection sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Print the array after each time two elements are swapped
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
}
}
