#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the array to print
 * @size: size of array
 * Return: always nothing
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 * advanced_binary_recursive - Recursively searches
 * for a value in a sorted array
 * @array: Pointer to the array
 * @sep_array: Pointer to the separated array
 * @size: size of sep_array
 * @value: Value to search for
 *
 * Return: Index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, int *sep_array,
		size_t size, int value)
{
	size_t mid;

	mid = (size - 1) / 2;
	if (size < 1)
		return (-1);
	print_array(sep_array, size);

	if (!mid && sep_array[0] >= value)
	{
		if (sep_array[0] == value)
			return (sep_array - array);
		else
			return (-1);
	}
	else if (sep_array[mid] >= value)
		return (advanced_binary_recursive
					(array, sep_array, mid + 1, value));
	else
		return (advanced_binary_recursive(array, sep_array + mid + 1,
					size - mid - 1, value));
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
			(array, array, size, value));
}
