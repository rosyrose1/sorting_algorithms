#include "sort.h"

void rosy_merge_subarry(int *subarry, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursion(int *subarry, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * rosy_merge_subarry - Arranging a subarray of integers.
 * @subarry: A subarray of an integer array that requires sorting.
 * @buff: buffer to store the sorted subarray.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: back index of the array.
 * Return: Nothing.
 */
void rosy_merge_subarry(int *subarry, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t e, f, g = 0;

	printf("Merging...\n[left]: ");
	print_array(subarry + front, mid - front);

	printf("[right]: ");
	print_array(subarry + mid, back - mid);

	for (e = front, f = mid; e < mid && f < back; g++)
		buff[g] = (subarry[e] < subarry[f]) ? subarry[e++] : subarry[f++];
	for (; e < mid; e++)
		buff[g++] = subarry[e];
	for (; f < back; f++)
		buff[g++] = subarry[f];
	for (e = front, g = 0; e < back; e++)
		subarry[e] = buff[g++];

	printf("[Done]: ");
	print_array(subarry + front, back - front);
}

/**
 * merge_sort_recursion - Apply the merge sort algorithm through recursion.
 * @subarry: A subarray of an integer array that requires sorting.
 * @buff: buffer to store the sorted result.
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */
void merge_sort_recursion(int *subarry, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursion(subarry, buff, front, mid);
		merge_sort_recursion(subarry, buff, mid, back);
		rosy_merge_subarry(subarry, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 *
 * Description: Apply the top-down merge sort algorithm.
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursion(array, buff, 0, size);

	free(buff);
}
