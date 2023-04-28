#include "sort.h"

/**
 * merge - joins the two different arrays
 *
 * @array: big array
 * @left: left half of the array
 * @left_size: size of the left half of the array
 * @right: right half of the array
 * @right_size: size of the right half of the array
 *
 * Return: Nothing
 */

void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]");
	print_array(right, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, left_size + right_size);
}
/**
 * merge_sort - sorts an array of integers in ascendign order
 *
 * @array: pointer to the first element of the array
 * @size: size of the array
 *
 * Return: void
 *
 * Utilizes top-down algorithm
 * sorts left array before right array
 */

void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid, a;
	if (size < 2)
		return;

	mid = size / 2;
	left = (int *)malloc(mid * sizeof(int));
	right = (int *)malloc((size - mid) * sizeof(int));

	if (left == NULL || right == NULL)
		printf("malloc error");

	for (a = 0; a < mid; a++)
	{
		left[a] = array[a];
	}
	for (a = mid; a < size; a++)
	{
		right[a - mid] = array[a];
	}

	merge_sort(left, mid);
	merge_sort(right, (size - mid));
	merge(array, left, mid, right, (size - mid));

	free(left);
	free(right);
}
