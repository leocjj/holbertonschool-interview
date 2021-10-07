#include "lists.h"
/**
* loop_start - finds where the loop starts.
* @head: pointer at head of the singly linked list
* @pointer_2x: pointer where pointer_2x met pointer_1x
* Return: The address of the node where the loop starts
*/
listint_t *loop_start(listint_t *head, listint_t *pointer_2x)
{
	while (head != pointer_2x)
	{
		pointer_2x = pointer_2x->next;
		head = head->next;
	}
	return (pointer_2x);
}
/**
* find_listint_loop - finds if a singly linked list has a loop,
* and the start of that loop.
* @head: head of the linked list.
* Return: The address of the node where the loop starts,
* or NULL if there is no loop.
*/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *pointer_1x, *pointer_2x;

	if (!head)
		return (NULL);

	pointer_1x = head;
	pointer_2x = head;

	while (pointer_2x != NULL && pointer_1x != NULL && pointer_2x->next)
	{
		pointer_1x = pointer_1x->next;
		pointer_2x = pointer_2x->next->next;
		if (pointer_2x == pointer_1x)
			return (loop_start(head, pointer_2x));
	}
	return (NULL);
}
