#include "regex.h"
#include <stdio.h>

/**
 * regex_match - checks whether a given pattern matches a given string.
 * @str: the string to scan
 * @pattern: the regular expression
 * Return: 1 if the pattern matches the string, or 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	/* printf("str is %s, pattern is %s\n", str, pattern); */
	if (!*str)
		return (!*pattern || (*(pattern + 1) == '*' &&
			regex_match(str, pattern + 2)));
	if (*(pattern + 1) == '*')
		return ((*pattern == '.' || *str == *pattern)
		? (regex_match(str + 1, pattern) || regex_match(str, pattern + 2))
		: (regex_match(str, pattern + 2)));
	/**
	 * il continue de rentrer dans (regex_match(str + 1, pattern) avant qu'il
	 * tombe sur la lettre correspondant
	 */
	return ((*pattern == '.' || *pattern == *str) &&
		regex_match(str + 1, pattern + 1));
}
