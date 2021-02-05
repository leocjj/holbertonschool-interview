#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: address of a pointer to a structure of type listint_t
 * @idx: index of the list where the new node should be added. Index starts: 0
 * @n: data for inserted node
 *
 * Return: the address of the new node, or NULL if it failed. If it is not
 * possible to add the new node at index idx, do not add and return NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 1;
	listint_t *temp_node = *head, *new_node;

	if (head == NULL)
		return (NULL);

	while (i < idx)
	{
		if (temp_node != NULL)
			temp_node = temp_node->next;
		else
			return (NULL);
		i++;
	}

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else if (temp_node)
	{
		new_node->next = temp_node->next;
		temp_node->next = new_node;
	}
	return (new_node);
}

/**
 * add_nodeint - function adds a new node at the beginning of a listint_t list.
 * @head: address of a pointer to a structure of type list_t
 * @n: integer to add to node.
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *p;

	if (head == NULL)
		return (NULL);

	p = malloc(sizeof(listint_t));
	if (p == NULL)
		return (NULL);

	(*p).n = n;
	(*p).next = *head;
	*head = p;

	return (p);
}

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

    if (*head == NULL)
        *head = new;
    else
    {
		if (number <= current->n)
			return add_nodeint(head, number);
		if (current->next == NULL && number > current->n)
			return insert_nodeint_at_index(&current, 1, number);
		
        while (current != NULL)
		{
			if (number <= current->n)
			{
				new->next = current;
				temp_node->next = new;	
				return (new);
			}				
			temp_node = current;
			current = current->next;
		}
		new->next = NULL;
		temp_node->next = new;
    }

    return (new);
}