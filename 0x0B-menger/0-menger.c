#include <math.h>
#include <stdio.h>

/**
 * menger - print menger sponge
 *
 * @level: level of menger sponge
 *
 * Return: nothing
 */
void menger(int level)
{
	int x, y, empty_y, crater, end, ptr_crt_y;
	empty_y, empty_x = 3;
	
	if (level == 1)
	{
		printf("#");
		return;
	}
	end = pow(3, level);
	crater = pow(3, level - 1);
	ptr_ctr_y = crater + 1;
	for (y = 1; y <= end; y++)
	{
		if ((y - 1) == crator)
			ptr_crt_y = 0;
		if (((y - 4) == 0) || ((y - 4) % 9 == 0))
			empty_y = 0;
		for (x = 1; x <= end; x++)
		{
			if ((ptr_crt_y <= crater) && (x == crater +1))
			{
				while (x <= (crater * 2))
				{
					printf(" ");
					x++;
				}
			}
			if (((y - 2) == 0) || ((y - 2) % 3 == 0))
			{
				
			}
		}
		printf("\n");
		ptr_ctr++;
		empty++;
	}
	
}
