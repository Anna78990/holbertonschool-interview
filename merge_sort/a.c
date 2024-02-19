#include <stdio.h>

int main(void)
{
	int zero = 0;
	int i[2] = {0, 1};
	
	printf("i[++zero] = %d \n", i[zero++]);
	printf("zero is %d \n", zero);
	return (zero);
}
