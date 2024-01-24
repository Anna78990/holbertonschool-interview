#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _print - prints a string of chars, ignoring the first 0s
 * @str: pointer to the string to print
 */
void _print(char *str)
{
	while (*str == '0')
		str++;
	if (!*str)
		_putchar('0');
	while (*str)
		_putchar(*str++);
	_putchar('\n');
}

/**
 * _len - mesure the length of a string
 * @str: pointer to the string
 * Return: length of the given string
 */
int _len(char *str)
{
	int len;

	for (len = 0; *str; str++)
		len++;

	return (len);
}

/**
 * _multiply - rewrite the first digit of the result on carried and
 *	       return the last digit
 * @fst: first char
 * @sec: second char
 * @carried: pointer to the carried value
 * Return: last digit of the result
 */
char _multiply(char fst, char sec, int *carried)
{
	int first = fst - '0', second = sec - '0', result;

	if (first > 10 || second > 10)
	{
		_print("Error");
		exit(98);
	}
	result = *carried + (first * second);
	*carried = result / 10;

	return ('0' + (result % 10));
}

/**
 * main - entry point
 * @ac: number of args
 * @av: array of args
 * Return: 0 on success, or 98
 */
int main(int ac, char *av[])
{
	char *fst, *sec, *result, *end, *current, product;
	char *cur_fst, *cur_sec;
	int len1, len2, carried, temp, first;

	if (ac != 3)
	{
		_print("Error");
		exit(98);
	}
	fst = av[1];
	sec = av[2];
	len1 = _len(fst);
	len2 = _len(sec);
	result = malloc(sizeof(char) + len1 + len2 + 1);
	end = result + len1 + len2;
	*end = '\0';

	for (cur_sec = sec + len2 - 1; cur_sec >= sec; cur_sec--)
	{
		current = end + (cur_sec - sec - len2 + 1) - 1;
		carried = 0;
		for (cur_fst = fst + len1 - 1; cur_fst >= fst; cur_fst--)
		{
			product = _multiply(*cur_fst, *cur_sec, &carried);
			temp = (product - '0') + (first ? 0 : *current - '0');
			carried += temp / 10;
			*current = (temp % 10) + '0';
			current--;
		}
		first = 0;
		*current = carried + '0';
	}
	_print(current);
	free(result);
	return (0);
}
