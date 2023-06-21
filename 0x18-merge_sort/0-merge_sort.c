#include <stdio.h>
#include <stdlib.h>

/**
 * print_array_loop - print array by using loop
 * @start: start of array
 * @end: end of array
 * @array: array to print
 */
void print_array_loop(size_t start, size_t end, int *array)
{
	for (; start <= end; start++)
	{
		printf("%d", array[start]);
		if (start != end)
			printf(", ");
	}
}

/**
 * merge_sort_rec - merge sort recursively
 * @array: array to sort
 * @begin: start of array
 * @end: end of array
 * @work: array to swap
*/
void merge_sort_rec(int *array, size_t begin, size_t end, int *work)
{

	size_t k, i, j, mid;

	if (begin >= end)
		return;
	if ((begin + end) % 2 == 0)
		mid = ((begin + end) / 2) - 1;
	else
		mid = ((begin + end) / 2);
	merge_sort_rec(array, begin, mid, work);
	merge_sort_rec(array, mid + 1, end, work);
	printf("Merging...\n[left]: ");
	print_array_loop(begin, mid, array);
	printf("\n[right]: ");
	print_array_loop(mid + 1, end, array);
	printf("\n");
	for (i = begin; i <= mid; ++i)
		work[i] = array[i];
	for (i = mid + 1, j = end; i <= end; ++i, --j)
		work[i] = array[j];
	i = begin, j = end;
	for (k = begin; k <= end; ++k)
	{
		if (work[i] <= work[j])
			array[k] = work[i++];
		else
			array[k] = work[j--];
	}
	printf("[Done]: ");
	print_array_loop(begin, end, array);
	printf("\n");
}

/**
 * merge_sort - merge sort by top-down
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *work = malloc(sizeof(int) * size);

	merge_sort_rec(array, 0, size - 1, work);

	free(work);
}
