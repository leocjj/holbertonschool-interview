#include "palindrome.h"

/**
 * power - function that calculates base power of exp.
 * @base: base for power.
 * @exp: exponent for power.
 *
 * Return: base power of exp.
 */
unsigned long power(unsigned long base, unsigned long exp)
{
	unsigned long result = 1;

	while (exp--)
		result *= base;
	return (result);
}

/**
 * is_palindrome - checks whether or not a given unsigned int is a palindrome.
 * @n: the number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long max = ULONG_MAX, n_digits = 1, num;

	if (n == 0)
		return (1);

	for (; max / 10 > 0; max /= 10)
		n_digits++;
	num = power(10, n_digits - 1);
	for (; n / num == 0; num /= 10)
		n_digits--;

	if (n_digits <= 1)
		return (1);

	for (; n_digits > 1 && n != 0; n_digits -= 2)
	{
		if ((n / power(10, n_digits - 1)) != (n % 10))
			return (0);
		/* Remove left digit */
		n %= power(10, n_digits - 1);
		/* Remove right digit */
		n /= 10;
	}

	return (1);
}
