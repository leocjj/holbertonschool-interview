#include "slide_line.h"

/**
 * move_next_number - find next number and move it to position.
 * @line: points to an array of integers containing size elements.
 * @size: size of line array.
 * @position: position of the array.
 *
 * Return: 1 if a number was found and moved, 0 otherwise.
 */
int move_next_number(int *line, size_t size, size_t position)
{
	size_t i;

	for (i = position; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[position] = line[i];
			line[i] = 0;
			return (1);
		}
	}
	return (0);
}

/**
 * merge_elements - merge number in position j into position i.
 * @line: points to an array of integers containing size elements.
 * @size: size of line array.
 * @i: position of the array.
 * @j: position of the array.
 * Return: void.
 */
void merge_elements(int *line, size_t size, size_t i, size_t j)
{
	if (i >= size || j >= size)
		return;

	if (line[i] == line[j])
	{
		line[i] += line[j];
		line[j] = 0;
	}
}

/**
 * slide_line - slide & merge it to the left or to the right.
 * Merge identical numbers, if they are contiguous or separated by zeros.
 * @line: points to an array of integers containing size elements.
 * @size: size of line array.
 * @direction: only SLIDE_LEFT, SLIDE_RIGHT.
 *
 * Return: 1 upon success, or 0 upon failure.
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i = 1;

	if (line == NULL || size <= 0)
		return (0);
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (line[0] == 0)
		if (move_next_number(line, size, 0) == 0)
			return (1);

	while (i < size)
	{
		if (line[i] == 0)
			if (move_next_number(line, size, i) == 0)
			{
				return (1);
			}
			else
				 merge_elements(line, size, i - 1, i);
		else
			merge_elements(line, size, i - 1, i);
		if (line[i] == 0)
			if (move_next_number(line, size, i) == 0)
				return (1);
		i++;
	}
	return (1);
}
