#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the array
 * @left: Index of the leftmost element to print
 * @right: Index of the rightmost element to print
 * Return: always nothing
 */
void print_array(const int *array, size_t left, size_t right)
{
	size_t i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i != right)
			printf(", ");
	}
	printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches
 * for a value in a sorted array
 * @array: Pointer to the first element of the array
 * @left: Index of the leftmost element of the current subarray
 * @right: Index of the rightmost element of the current subarray
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = (left + right) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] != value)
			return (mid);
		else
			return (advanced_binary_recursive
					(array, left, mid, value));
	}
	else if (array[mid] < value)
		return (advanced_binary_recursive
				(array, mid + 1, right, value));
	else
		return (advanced_binary_recursive
			(array, left, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using recursion
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive
			(array, 0, size - 1, value));
}
