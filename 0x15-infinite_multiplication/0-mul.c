#include <stdlib.h>
#include "mul.h"


/**
 * print_err - print "Error"
 *
 * Return: always nothing
 */
void print_err(void)
{
	int i;
	char *err = "Error";

	for (i = 0; i < 5; i++)
		_putchar(err[i]);
	_putchar('\n');
}


/**
 * counter - count length char, if it find a not number char, it fail
 *
 * @array: string to check
 *
 * Return: length on succeed, error code upon failure
 */
int counter(char *array)
{
	int i;

	for (i = 0; array[i]; i++)
	{
		if (array[i] > 57 || array[i] < 48)
		{
			print_err();
			exit(98);
		}
	}
	return (i);
}

/**
 * update_indexes - update the other indexes
 *
 * @added: the number to be added
 * @idx: idx to update
 * @total: array containing calculation results
 *
 * Return: always nothing
 */

void update_indexes(int added, int idx, int *total)
{
	int v;

	v = total[idx] + added;

	if (v > 9)
	{
		total[idx] = v % 10;
		update_indexes(v / 10, idx + 1, total);
	}
	else
		total[idx] = v;
}


/**
 * rec_print - print the array recursively
 *
 * @i: index to print
 * @total: array containing calculation results
 * @br: check switch to ignore the zeros,
 *	in the case the result which start '0'
 *
 * Return: always nothing
 */
void rec_print(int i, int *total, int br)
{
	if (total[i] != 0)
		br++;
	if (br > 0)
		_putchar(total[i] + '0');
	if (i > 0)
		rec_print(i - 1, total, br);
}

/**
 * main - multiplies two positive numbers
 *
 * @argc: Arguments counter
 * @argv: Arguments vector
 *
 * Return: EXIT_SUCCESS upon success, error code upon failure
 */
int main(int argc, char **argv)
{
	int i, j, z, culc, idx, fidx, sidx, index;
	int *fst, *sec, *total;

	if (argc != 3)
		return(0);
	i = counter(argv[1]);
	j = counter(argv[2]);

	fst = (int *)malloc(i * sizeof(int));
	sec = (int *)malloc(j * sizeof(int));
	total = (int *)malloc((i + j + 1) * sizeof(int));

	for (z = 0; z < i; z++)
		fst[z] = argv[1][z] - 48;
	for (z = 0; z < j; z++)
		sec[z] = argv[2][z] - 48;

	idx = 0;
	for (fidx = i - 1; fidx >= 0; fidx--)
	{
		index = idx;
		for (sidx = j - 1; sidx >= 0; sidx--)
		{
			culc = fst[fidx] * sec[sidx];
			update_indexes(culc, index, total);
			index++;
		}
		idx++;
	}
	rec_print(i + j, total, 0);
	_putchar('\n');
	free(fst);
	free(sec);
	free(total);
	return (EXIT_SUCCESS);
}
