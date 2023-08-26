#include "sort.h"

/**
 * locate_min - Locating the minimum value from the current index in the array.
 * @array: The Array to be Scout
 * @index: Starting Index of The Scout
 * @size: The Array Size
 * Return: (int) index of min if found or
 * same given index if index is the min
 */

int locate_min(int *array, int index, size_t size)
{
	int min, idx_min;
	int c;

	min = array[index];
	idx_min = index;
	for (c = index; c < (int)size; c++)
	{
		if (array[c] < min)
		{
			min = array[c];
			idx_min = c;
		}
	}
	if (idx_min == index)
		return (-1);
	return (idx_min);
}

/**
 * selection_sort - Application of selection Sort Algrithme
 * @array: Array to sort type int *
 * @size: Size of The Given Array
 *
 * Return: (Void) Sorted Array
 */
void selection_sort(int *array, size_t size)
{
	int c;
	int min, tmp;

	for (c = 0; c < (int)size; c++)
	{
		min = locate_min(array, c, size);
		if (min != -1)
		{
			tmp = array[c];
			array[c] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
