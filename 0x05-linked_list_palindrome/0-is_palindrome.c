#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a listint_t list.
 * @head: address of a pointer to a structure of type listint_t
 * @data: integer to add to node.
 *
 * Return: pointer to structure of type listint_t.
 */
listint_t *add_node(listint_t **head, int data)
{
	listint_t *p;

	if (head == NULL)
		return (NULL);

	p = malloc(sizeof(listint_t));
	if (p == NULL)
		return (NULL);

	(*p).n = data;
	(*p).next = *head;
	*head = p;

	return (p);
}

/**
 * reverse_listint - function that reverses a listint_t linked list.
 * @head: address of a pointer to a structure of type listint_t
 *
 * Return: a pointer to the first node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}
	*head = prev;
	return (*head);
}

/**
 * is_palindrome - verify if list is palindrome
 * @head: address of a pointer to a structure of type listint_t
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *reve = *head, *temp = *head, *s = NULL, *todel;

	if (*head == NULL)
		return (1);

	while (temp && temp->next && temp->next->next)
	{
		s = add_node(&s, reve->n);
		reve = reve->next;
		temp = temp->next->next;
	}
	s = add_node(&s, reve->n);

	if (temp->next != NULL)
		reve = reve->next;

	while (s != NULL && reve != NULL)
	{
		if ((*s).n != (*reve).n)
			return (0);
		todel = s;
		s = (*s).next;
		free(todel);
		reve = (*reve).next;
	}
	return (1);
}
