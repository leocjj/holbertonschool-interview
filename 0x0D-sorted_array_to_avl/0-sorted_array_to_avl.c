#include "binary_trees.h"
/**
 * sorted_array_to_avl - create binary tree
 * @array: The array to convert
 * @size: Size of the array
 * Return: header
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *header = NULL;

	if (array == NULL)
		return (NULL);

	if (nodes_binary(array, 0, (int)size - 1, &header) == NULL)
		return (NULL);
	return (header);
}
/**
 * nodes_binary - create binary tree
 * @array: The array to convert
 * @p1: initial position
 * @p2: final position
 * @header: node to create
 * Return: header
 */
avl_t *nodes_binary(int *array, int p1, int p2, avl_t **header)
{
	avl_t *node = NULL, *left = NULL, *right = NULL;
	int mid;

	if (p1 > p2)
		return (NULL);

	mid = (p2 + p1) / 2;

	nodes_binary(array, p1, mid - 1, &left);
	nodes_binary(array, mid + 1, p2, &right);

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->n = array[mid];
	node->parent = NULL;
	node->left = left;
	node->right = right;

	if (left != NULL)
		left->parent = node;

	if (right != NULL)
		right->parent = node;

	*header = node;
	return (node);
}
