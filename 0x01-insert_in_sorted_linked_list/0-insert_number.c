#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - function adds a new node in a sorted listint_t list.
 * @head: address of a pointer to a structure of type list_t
 * @number: integer to add to node.
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current = *head;
	listint_t *temp_node = *head;

	if (head == NULL)
		return (NULL);

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);
    new->n = number;

	// Null list
    if (*head == NULL)
	{
        *head = new;
		return (new);
	}
	// Number at the begining of the list
	if (number <= current->n)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	// Look for the right position
	while (current != NULL)
	{
		// If right position is found
		if (number <= current->n)
		{
			new->next = current;
			temp_node->next = new;	
			return (new);
		}				
		temp_node = current;
		current = current->next;
	}
	// If right position isn't found, insert at the end of the list.
	new->next = NULL;
	temp_node->next = new;
    return (new);
}