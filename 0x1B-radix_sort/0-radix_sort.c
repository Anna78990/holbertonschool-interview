#include "sort.h"

/**
 * get_max - Returns the maximum element from an array
 * @array: The array
 * @size: Number of elements in @array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * count_sort - Performs counting sort on an array based on a significant digit
 * @arr: The array
 * @n: Number of elements in array
 * @exp: The significant digit to consider
 */
void count_sort(int arr[], int n, int exp)
{
	int *output;
	int i, count[10] = {0};

	output = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}


/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              LSD (Least Significant Digit) radix sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (array == NULL || size < 2)
	{
		return;
	}
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp);
		print_array(array, size);
	}
}
