#include "sort.h"

void bb_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
		}
	}
	bb_sort(array, size - 1);
}
