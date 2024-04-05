#include <stdio.h>


/**
 * wildcmp -  compares two strings and returns 1 ('*' stands for wildcard)
 * @s1: compared string
 * @s2: string to compare(it can contain '*')
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	/* le cas *s1 pointe '\0' */
	if (!*s1)
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		/* si on enleve return au-dessus il retourne 0 dans le cas */
		/* ou il y a plusieur * dans s2. */
		/*printf("s1 = %c s2 = %c\n", *s1, *s2);*/
		return (!*s2);
	}
	if (*s2 == '*')
	{
		/*printf("s1 = %c s2 = %c (*s2 == '*')\n", *s1, *s2);*/
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
	}
	if (*s1 != *s2)
	{
		/*printf("s1 = %c s2 = %c (*s1 != *s2)\n", *s1, *s2);*/
		/*printf("Im in (*s1 != *s2)\n");*/
		return (0);
	}
	/* Le cas qu'il n'y a aucun probleme.*/
	return (wildcmp(s1 + 1, s2 + 1));
}
