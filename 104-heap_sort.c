#include "sort.h"

#define HEAP_PARENT_INDEX(node_index) (((node_index) - 1) / 2)
#define HEAP_LCHILD_INDEX(node_index) (((node_index) * 2) + 1)
#define HEAP_RCHILD_INDEX(node_index) (((node_index) * 2) + 2)

/**
 * mrswap - swap elements and prints an array
 * @array: pointer to the array
 * @size: size of the array
 * @a: index element to swap
 * @b: index element to swap
 */
static void mrswap(int *array, size_t size, size_t a, size_t b)
{
	array[a] ^= array[b];
	array[b] ^= array[a];
	array[a] ^= array[b];
	print_array(array, size);
}

/**
 * heap_sift_down -Restore a max-heap structure rooted
 * at the parent of valid max-heaps.
 * @array: pointer to the array
 * @size: size of the array
 * @start: index of the root of the heap to restore
 * @end: index of the last heap element
 */
static void heap_sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t swap = root;
	size_t lchild = 0;
	size_t rchild = 0;

	while (HEAP_LCHILD_INDEX(root) <= end)
	{
		lchild = HEAP_LCHILD_INDEX(root);
		rchild = HEAP_RCHILD_INDEX(root);
		if (array[swap] < array[lchild])
			swap = lchild;
		if (rchild <= end && array[swap] < array[rchild])
			swap = rchild;
		if (swap == root)
			return;
		mrswap(array, size, root, swap);
		root = swap;
	}
}

/**
 * rheapy - build a max-heap
 * @array: pointer to array
 * @size: size of array
 */
static void rheapy(int *array, size_t size)
{
	size_t end = size - 1;
	size_t start = HEAP_PARENT_INDEX(end);

	while (start < end)
		heap_sift_down(array, size, start--, end);
}

/**
 * heap_sort - sort an array in ascending order
 * @array: pointer to the array
 * @size: size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	if (array && size)
	{
		rheapy(array, size);
		while (end > 0)
		{
			mrswap(array, size, 0, end--);
			heap_sift_down(array, size, 0, end);
		}
	}
}
