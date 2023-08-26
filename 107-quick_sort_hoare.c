#include "sort.h"

/**
 * s_swap - swaps 2 integer values
 * @array: the integer for sorting
 * @size: size of array
 * @c: address of first value
 * @d: address of second value
 * mimi and rosy's
 * Return: nothing
 */
void s_swap(int *array, size_t size, int *c, int *d)
{
	if (*c != *d)
	{
		*c = *c + *d;
		*d = *c - *d;
		*c = *c - *d;
	}
	print_array((const int *)array, size);
}

/**
 * hoare_division - divides the array
 * @array: The array of integers for sorting.
 * @size:  size of array
 * @lo: low index of the sort range
 * @high: high index of the sort range
 *
 * Return: void
 */
size_t hoare_division(int *array, ssize_t size, ssize_t lo, ssize_t high)
{
	ssize_t p = lo - 1, j = high + 1;
	int pivot = array[high];

	while (p < size)
	{
		while (array[++p] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (p < j)
			s_swap(array, size, &array[p], &array[j]);
		else if (p >= j)
			break;
	}
	return (p);
}

/**
 * rm_quicksort - quicksorts via hoare division scheme
 * @array: the array integers for sorting
 * @size: size of array
 * @lo: low index of the sort range
 * @high: high index of the sort range
 *
 * Return: nothing
 */
void rm_quicksort(int *array, size_t size, ssize_t lo, ssize_t high)
{
	if (lo < high)
	{
		size_t p = hoare_division(array, size, lo, high);

		rm_quicksort(array, size, lo, p - 1);
		rm_quicksort(array, size, p, high);
	}
}

/**
 * quick_sort_hoare - calls quicksort
 * @array: the integer for sorting
 * @size: size of array
 * Return: nothing
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	rm_quicksort(array, size, 0, size - 1);
}
