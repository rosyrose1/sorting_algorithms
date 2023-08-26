#include "sort.h"

/**
 * rm_get_max - Retrieve the highest value from an array of integers.
 * @array: An array of integers.
 * @size: size of the array.
 *
 * Return: Maximum integer in the array.
 */
int rm_get_max(int *array, int size)
{
	int maxi, j;

	for (maxi = array[0], j = 1; j < size; j++)
	{
		if (array[j] > maxi)
			maxi = array[j];
	}

	return (maxi);
}

/**
 * counting_sort - Sorting an array of integers in ascending
 * order using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *Description: Displays the counting array once it has been configured.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, maxi, j;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxi = rm_get_max(array, size);
	count = malloc(sizeof(int) * (maxi + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (j = 0; j < (maxi + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (maxi + 1); j++)
		count[j] += count[j - 1];
	print_array(count, maxi + 1);

	for (j = 0; j < (int)size; j++)
	{
		sorted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = sorted[j];

	free(sorted);
	free(count);
}
