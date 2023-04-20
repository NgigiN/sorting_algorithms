#include "sort.h"

/**
 * bubble_sort - this function sorts an array of
 * integers in ascending order using Bubble sort
 * algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Print the array after each time you swap tow elements
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j; 
	int temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
		if (array[j] > array[j + 1])
		{
			temp = array[j + 1];
			array[j + 1] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
		}
	}
}
