#include "sort.h"
#include <stdbool.h>
int partitions(int *array, int low, int high, size_t size);
/**
 * quick_sort_helper - helps sort the array by taking
 * low and high parameters making using partitions function
 * easier
 * @array: pointer to the first element of the array
 * @low: first index of the sub-array
 * @high: highest index of the sub-array
 * @size: size of the big array
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partitions(array, low, high, size);

		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, high, size);
	}
}
/**
 * all_elements_equal - checks if all elements are equal
 * @array: pointer to first element of array
 * @size: size of array
 * Return: true if equal false if not
 */
bool all_elements_equal(int *array, size_t size)
{
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] != array[0])
			return false;
	}
	return true;
}
/**
 * quick_sort - sorts an array of integers in
 * ascending order using quick sort
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * implement the Lomuto partitions scheme
 * The pivot should always be the last element of the
 * partition should being sorted
 * Print the array every time you swap two elements
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	if (all_elements_equal(array, size))
	{
		return;
	}
	else
	{
		quick_sort_helper(array, 0, size - 1, size);
	}
}

/**
 * partitions - partitions an array using the Lomuto scheme
 *
 * @array: pointer to the first element of the array
 * @low: index of the low end of the array
 * @high: index of the high end of
 * the partition
 * @size: size of the array
 *
 * Return: the index of the pivot element after partitioning
 * The array is printed every time the elements are swapped
 */

int partitions(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{

		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
