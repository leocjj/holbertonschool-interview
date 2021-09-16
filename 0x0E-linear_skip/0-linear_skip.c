#include "search.h"
/**
 * linear_skip - Funtion linear search in a skip list
 * @list: pointer to the head of the skip list to search in
 * @value: is the value to search for
 * Return: first node_ where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node_;

	if (list == NULL)
		return (NULL);

	node_ = list->express;

	printf("Value checked at index [%lu] = [%d]\n", node_->index, node_->n);

	while (node_ && node_->n < value)
	{
		list = node_;
		node_ = node_->express;
		if (node_ == NULL)
		{
			node_ = list;
			while (node_->next)
				node_ = node_->next;
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n", node_->index, node_->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", list->index,
		   node_->index);

	for (; list && node_->n >= list->n; list = list->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", list->index, list->n);

		if (list->n == value)
			return (list);
	}
	return (NULL);
}
