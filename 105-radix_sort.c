#include "sort.h"

/**
 * acquire_digit - acquires a digit from a number
 * @number: integer
 * @digit: digit position to get
 * mimi and rosy's
 * Return: digit value at given position
**/
int acquire_digit(long number, int digit)
{
	long a = 0L, pow = 1L, ret;

	for (a = 0; a < digit; a++)
		pow *= 10L;
	ret = ((number / pow) % 10);
	return (ret);
}

/**
 * mradix_pass - arranges by radix
 * @array: integer array to sort
 * @size: size of array
 * @digit: current digit to check
 * @new_array: target array of same size
 *
 * Return: nothing.
 */
int mradix_pass(int *array, ssize_t size, int digit, int *new_array)
{
	ssize_t a;
	int buckets[10] = {0};

	for (a = 0; a < size; a++)
		buckets[acquire_digit(array[a], digit)]++;
	for (a = 1; a <= 9; a++)
		buckets[a] += buckets[a - 1];
	for (a = size - 1; a > -1; a--)
		new_array[buckets[acquire_digit(array[a], digit)]-- - 1] = array[a];
	return (1);
}

/**
 * radix_sort - sorts by radix
 * @size: the size of the array
 * @array: the integer array to sort
 *
 * Return: the gap size
 */
void radix_sort(int *array, size_t size)
{
	int *old_array, *new_array, *temp_ptr, *ptr, maxi = 0;
	size_t a, sd = 1;

	if (!array || size < 2)
		return;

	for (a = 0; a < size; a++)
		if (array[a] > maxi)
			maxi = array[a];
	while (maxi /= 10)
		sd++;
	old_array = array;
	new_array = ptr = malloc(sizeof(int) * size);
	if (!new_array)
		return;
	for (a = 0; a < sd; a++)
	{
		mradix_pass(old_array, (ssize_t)size, a, new_array);
		temp_ptr = old_array;
		old_array = new_array;
		new_array = temp_ptr;
		print_array(old_array, size);
	}
	for (a = 0; a < size; a++)
		array[a] = old_array[a];
	free(ptr);
}
