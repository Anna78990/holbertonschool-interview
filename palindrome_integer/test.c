#include <stdio.h>


int main(void)
{
	int a = 1;
	int b = 100;

	do
	{
		printf("%d \n", b);
		a *= 10;
	}
	while(b /= 10);

	printf("%d \n", a / 10);
	
	return (1);
}
