#include <stdlib.h>
#include "lists.h"
/**
 * check_cycle - function that checks if a singly linked list has a cycle in it
 * @list: pointer to a structure of type listint_t
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle Requirements.
 */
int check_cycle(listint_t *list)
{
	listint_t *step1, *step2;

	if (list == NULL || list->next == NULL)
		return (0);

	step1 = list;
	step2 = list->next;

	while (step2->next != NULL)
	{
		if (step1 == step2)
			return (1);
		if (step2->next->next != NULL)
		{
			step1 = step1->next;
			step2 = step2->next->next;
		}
		else
			return (0);
	}
	return (0);
}
