#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Perform sift down operation on the heap
 * @array: Pointer to the array
 * @size: Size of the array
 * @start: Start index of the subtree
 * @end: End index of the subtree
 * Return: Nothing
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;

	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			int tmp = array[root];

			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, size);
			root = swap;
		}
		else
			break;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		int tmp = array[0];

		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
