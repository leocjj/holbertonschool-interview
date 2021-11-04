#include "list.h"
/**
* add_node_end - add a new node to the end of a double circular linked list.
* @list: list to modify.
* @str: string to copy into the new node.
* Return: address of the new node, or NULL on failure.
*/
List *add_node_end(List **list, char *str)
{
	List *node = NULL;

	node = create_node(str);
	if (!node)
		return (NULL);

	if (!(*list))
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		node->next = (*list);
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
	return (node);
}
/**
* add_node_begin - Add a new node to the beginning of a
* double circular linked list.
* @list: the list to modify
* @str: the string to copy into the new node
* Return: Address of the new node, or NULL on failure
*/
List *add_node_begin(List **list, char *str)
{
	List *node = NULL;

	node = create_node(str);
	if (!node)
		return (NULL);

	if (!(*list))
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		node->next = (*list);
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
		*list = node;
	}

	return (node);
}
/**
 * create_node - creates a new node
 * @str: string to copy in the new node
 * Return: address of the new node, NULL on failure
 */
List *create_node(char *str)
{
	List *node = NULL;

	node = malloc(sizeof(List));
	if (!node)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->prev = NULL;

	return (node);
}
