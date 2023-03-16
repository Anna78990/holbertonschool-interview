#include <math.h>
#include <stdio.h>


/**
* space_or_diese - check if it will be # or hole
* @r: row
* @c: column
* Return: char space if is a hole overwise the char #
*/
char space_or_diese(int x, int y)
{
	while (x && y)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (' ');
		x /= 3, y /= 3;
	}
	return ('#');
}

/**
* menger - draws a 2D Menger Sponge
* @level: the level of the Menger Sponge to draw
*/
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = (int)pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
			putchar(space_or_diese(x, y));
		putchar('\n');
	}
}
