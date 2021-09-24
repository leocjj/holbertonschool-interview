#include "holberton.h"
/**
 * _strlen - length of a string..
 * @s: parameter
 * Description: returns the length of a string.
 * Return: int.
 */
int _strlen(char *s)
{
	int len = 0;

	for ( ; *s != '\0' ; s++)
		len = len + 1;
	return (len);
}
/**
 * _isdigit - is digit
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _isdigit(int c)
{
	int i;

	if ((c >= 48 && c <= 57))
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	return (i);
}
/**
 * print_ans - print answer array in reverse
 * @a: array with answer to print
 * @i: position from to print
 * Return: nothing
 */
void print_ans(int *a, int i)
{
	for (; i >= 0; i--)
	{
		_putchar(a[i] + '0');
	}
	_putchar('\n');
}
/**
 * validation - validate arguments
 * @argc : argc contains the number of arguments passed to the program
 * @argv : A vector is a one-dimensional array
 * Return: exit with code 98 if error, otherwise 0
 */
int validation(int argc, char *argv[])
{
	int i, arg;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		exit(98);
	}
	for (i = 1 ; i < argc ; i++)
	{
		for (arg = 0 ; argv[i][arg] != '\0' ; arg++)
		{
			if (_isdigit(argv[i][arg]))
			{ ; }
			else
			{
				write(1, "Error\n", 6);
				exit(98);
			}
		}
	}
	return (0);
}
/**
 * main - entry point
 * @argc : argc contains the number of arguments passed to the program
 * @argv : A vector is a one-dimensional array
 * Return: exit with code 98 if error, otherwise 0
 */
int main(int argc, char *argv[])
{
	int a[10000], b[10000], ans[10000] = {0};
	int i, j, tmp, l1, l2;
	char *s1, *s2;

	validation(argc, argv);

	if (*(argv[1]) == '0' || *(argv[2]) == '0')
	{
		_putchar('0');
		_putchar('\n');
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	l1 = _strlen(s1), l2 = _strlen(s2);

	for (i = l1 - 1, j = 0; i >= 0; i--, j++)
	{ a[j] = s1[i] - '0'; }
	for (i = l2 - 1, j = 0; i >= 0; i--, j++)
	{ b[j] = s2[i] - '0'; }
	for (i = 0; i < l2; i++)
	{
		for (j = 0; j < l1; j++)
		{
			ans[i + j] += b[i] * a[j];
		}
	}
	for (i = 0; i < l1 + l2; i++)
	{
		tmp = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + tmp;
	}
	for (i = l1 + l2; i >= 0; i--)
	{
		if (ans[i] > 0)
			break;
	}
	print_ans(ans, i);
	return (0);
}
