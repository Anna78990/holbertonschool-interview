/**
 * get_index - finds first index number
 * @n: number to check
 *
 * Return: beginning index
 **/
unsigned long get_index(unsigned long n)
{
	unsigned long num = 1;

	do
		num *= 10;

	while (n /= 10);
	return (num / 10);
}

/**
 * is_palindrome - checks if it is palindrome
 * @n: number to check
 *
 * Return: 1 if it is palindrome, otherwise 0
 **/
int is_palindrome(unsigned long n)
{
	unsigned long b, e;

	for (b = get_index(n), e = 1; b > e; b /= 10, e *= 10)
		if (n / b % 10 != n / e % 10)
			return (0);
	return (1);
}
