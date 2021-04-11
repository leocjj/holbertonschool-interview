#include "menger.h"

/**
 * power - function that calculates base power of exp.
 * @base: base for power.
 * @exp: exponent for power.
 *
 * Return: base power of exp.
 */
unsigned long power(unsigned long base, int exp)
{
	unsigned long result = 1;

	while (exp--)
		result *= base;
	return (result);
}

/**
 * isFilled - function that evalueate menger condition.
 * @i: y coordinate of the menger square.
 * @j: x coordinate of the menger square
 * @level: level of menger square to print.
 *
 * Return: 1 if coordinate must be filled, 0 if not.
 */
int isFilled(unsigned long i, unsigned long j, int level)
{
	unsigned long le = power(3, level);

	if (level == 0)
		return (1);
	if ((i >= le / 3) && (i < 2 * le / 3) && (j >= le / 3) && (j < 2 * le / 3))
		return (0);
	else
		return (isFilled(i % (le / 3), j % (le / 3), level - 1));
}

/**
 * menger - iterates over each coordinate of the menger square.
 * @level: level of menger square to print.
 *
 * Return: void.
 */
void menger(int level)
{
	unsigned long i, j;
	unsigned long len = power(3, level);

	if (level == 0)
		printf("#\n");
	else
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{
				if (isFilled(i, j, level))
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
