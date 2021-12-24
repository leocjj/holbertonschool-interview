#include "substring.h"
/**
* find_substring - finds all the possible substrings containing
* a list of words, within a given string.
* @s: string to scan.
* @words: array of words all substrings must be
* a concatenation arrangement of.
* @nb_words: number of elements in the array 'words'
* @n: holds the address at which to store the number of elements
* in the returned array.
* Return: an allocated array, storing each index in 's',
* at which a substring was found.
* If no solution is found, NULL can be returned.
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *result, str_len = 0, word_len = 0, i;
	*n = 0;

	if (!words || !(*words) || nb_words == 0)
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
		str_len++;

	for (i = 0; words[0][i] != '\0'; i++)
		word_len++;

	result = malloc(sizeof(int) * str_len);

	if (!result)
		return (NULL);

	for (i = 0; *(s + i) != '\0'; i++)
	{
		if (full_match(s + i, words, nb_words, word_len))
		{
			result[*n] = i;
			*n = *n + 1;
		}
	}

	if (*n == 0)
	{
		free(result);
		return (NULL);
	}

	return (result);
}
/**
* full_match - finds if a substring match occurs at a single location
* @s: string
* @words: array of words
* @nb_words: number of words in 'words'
* @word_len: the length of each word
* Return: 1 if match of a substring made of 'words' exists, 0 otherwise
*/
int full_match(char const *s, char const **words, int nb_words, int word_len)
{
	int *done, done_len = 0, found = 0, match = 1, j, k, l, not_l;

	done = malloc(sizeof(int) * nb_words);

	for (j = 0; j < nb_words; j++)
		done[j] = -1;

	for (k = 0; k < nb_words; k++)
	{
		found = 0;
		for (l = 0; l < nb_words; l++)
		{
			not_l = not_in(done, done_len, l);
			if (not_l && str_match((s + (k * word_len)), words[l]))
			{
				done[done_len] = l;
				done_len++;
				found = 1;
				break;
			}
		}
		if (found == 0)
		{
			match = 0;
			break;
		}
	}
	free(done);
	return (match);
}
/**
* not_in - checks if 'l' in 'arr'
* @arr: array of integers
* @len: length of arr
* @l: the value to check for
* Return: 1 if 'l' not in 'arr', 0 otherwise
*/
int not_in(int *arr, int len, int l)
{
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (arr[i] == l)
			return (0);
	}
	return (1);
}
/**
* str_match - match word as a substring of str
* @str: string
* @words: array of words
* Return: 1 if 'words' is a substring of str, 0 otherwise
*/
int str_match(char const *str, char const *words)
{
	int i = 0;

	for (i = 0; *(words + i) != '\0'; i++)
	{
		if (*(str + i) != *(words + i))
			return (0);
	}
	return (1);
}
