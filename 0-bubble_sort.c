#include "sort.h"

/**
 *bubble_sort - Arranges an array of integers in ascending order.
 *@array: array to be sorted
 *@size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t m, r;
	int n;

	if (size < 2)
		return;
	for (r = 0; r < size - 1; r++)
	{
		for (m = 0; m < size - r - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				n = array[m];
				array[m] = array[m + 1];
				array[m + 1] = n;
				print_array(array, size);
			}
		}
	}
}
