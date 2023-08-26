#include "sort.h"

/**
 * shell_sort - Utilizing the Knuth sequence for the shell sort algorithm.
 * @array: an Array to be Sorted
 * @size: the size of the array
 * Return: Sorted Array (void)
 */
void shell_sort(int *array, size_t size)
{
	int n = 1, c, d;
	int tmp;

	if (!array || !size || size < 2)
		return;
	while (n < (int)size / 3)
		n = n * 3 + 1;
	while (n > 0)
	{
		for (c = n; c < (int)size; c++)
		{
			tmp = array[c];
			d = c;
			while (d > (n - 1) && array[d - n] >= tmp)
			{
				array[d] = array[d - n];
				d -= n;
			}
			array[d] = tmp;
		}
		n = n / 3;
		print_array(array, size);
	}
}
