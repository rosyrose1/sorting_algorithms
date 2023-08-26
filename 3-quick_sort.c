#include "sort.h"

/**
 * sswap - swap two integers
 * @c: an integer
 * @d: an integer
 *mimi and rosy's
 * Return: Nothing returns to void
 */
void sswap(int *c, int *d)
{
	int tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}
/**
 * partition - Partition an array and using a pivot
 * @array: an array
 * @low: an integer
 * @high: an integer
 * @size: size of array (size_t)
 * Return: index of pivote (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			i++;
			if (i != y)
			{
				sswap(&array[i], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (i);
}
/**
 * lomuto_qsort - Sorting Recursively an Array
 * @array: Array to be sorted
 * @low: lowest value of the array
 * @high: highest value of the array
 * @size: array size
 * Return: nothing
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int y;

	if (low < high)
	{
		y = partition(array, low, high, size);
		lomuto_qsort(array, low, y - 1, size);
		lomuto_qsort(array, y + 1, high, size);
	}
}
/**
 * quick_sort - Quick Sort Algorithme using lomuto partition
 * @array: Array to sort
 * @size: Size of The Array
 * Return: Sorted Array (void)
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
