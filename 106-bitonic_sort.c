#include "sort.h"

/**
 * sswap - swaps 2 int values
 * @c: an address of first value
 * @d: an address of second value
 *
 * Return: nothing
 */
void sswap(int *c, int *d)
{
	if (*c != *d)
	{
		*c = *c + *d;
		*d = *c - *d;
		*c = *c - *d;
	}
}

/**
 * bitonic_analyze - compares bitonically
 * @up: true if UP sorting
 * @array: array pointer
 * @start: start index
 * @end: stop index
 */
void bitonic_analyze(int up, int *array, size_t start, size_t end)
{
	size_t half = (end - start + 1) / 2, i;

	for (i = start; i < start + half; i++)
		if ((array[i] > array[i + half]) == up)
			sswap(&array[i], &array[i + half]);
}

/**
 * rosy_bitonic_merge - merges bitonically
 * @up: true if UP sorting
 * @array: array pointer
 * @start: start index
 * @end: stop index
 */
void rosy_bitonic_merge(int up, int *array, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	bitonic_analyze(up, array, start, end);
	rosy_bitonic_merge(up, array, start, mid);
	rosy_bitonic_merge(up, array, mid + 1, end);
}

/**
 *b_bitonic_sort - Performs a bitonic sort through recursive methods.
 * @up: true if UP sorting
 * @array:array pointer
 * @size: length of the array
 * @start: start index
 * @end: stop index
 */
void b_bitonic_sort(int up, int *array, size_t size, size_t start, size_t end)
{
	size_t mid = (start + end) / 2;

	if (end - start < 1)
		return;
	printf("Merging [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
	b_bitonic_sort(1, array, size, start, mid);
	b_bitonic_sort(0, array, size, mid + 1, end);
	rosy_bitonic_merge(up, array, start, end);
	printf("Result [%lu/%lu] (%s):\n", end - start + 1, size,
		up ? "UP" : "DOWN");
	print_array(array + start, end - start + 1);
}

/**
 * bitonic_sort - sorts bitonically
 * @array: array pointer
 * @size: length of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	b_bitonic_sort(1, array, size, 0, size - 1);
}
