#include "binary_trees.h"
/**
* binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
* @tree: pointer to the root node of the tree to check
* Return: 1 if tree is a valid AVL Tree, and 0 otherwise
* If tree is NULL, return 0
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);

	return (is_valid_avl(tree, INT_MIN, INT_MAX, &height));
}
/**
* is_valid_avl - validate tree
* @tree: pointer to the root node of the tree to check
* @min: minimum value
* @max: maximum value
* @height: height
* Return: 1 if valid, 0 otherwise
*/
int is_valid_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int height1 = 0, height2 = 0;

	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	if (is_valid_avl(tree->left, min, tree->n, &height1) == 0)
		return (0);

	else if (is_valid_avl(tree->right, tree->n, max, &height2) == 0)
		return (0);

	*height = ((height1 > height2) ? height1 : height2) + 1;

	if ((height1 - height2 > 1) || (height2 - height1 > 1))
		return (0);

	return (1);
}
