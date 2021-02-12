#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heap_t - measures the size of a heap
 * @root: is to the root node of the Heap.
 *
 * Return: size of a heap
 */
int measure(const heap_t *root)
{
	int size_left = 0, size_right = 0;

	if (root == NULL)
		return (0);

	size_left = measure(root->left);
	size_right = measure(root->right);
	return (size_left + size_right + 1);
}

/**
 * ith_node - return the ith node of a heap
 * @root: is to the root node of the Heap.
 *
 * Return: return the ith node of a heap
 */
heap_t *ith_node(heap_t *root, const int i)
{
    int  b = i; 

    /* Sanity check: If no tree, always return NULL. */
    if (!root || i < 1)
        return (NULL);
    /* If i is 1, we return the root. */
    if (i == 1)
        return root;
    /* Set b to the value of the most significant binary digit
       set in b. This is a known trick. */
    while (b & (b - 1))
        b &= b - 1;        
    /* We ignore that highest binary digit. */
    b >>= 1;
    /* Walk down the tree as directed by b. */
    while (b) {
        if (i & b) {
            if (root->right)
                root = root->right;
            else
                return (NULL); /* Not a complete tree, or outside the tree. */
        } else {
            if (root->left)
                root = root->left;
            else
                return (NULL); /* Not a complete tree, or outside the tree. */
        }
        b >>= 1;
    }
    return (root);
}

/**
 * order_node - max order of the ith node of a heap
 * @root: is to the root node of the Heap.
 *
 * Return: return the ith node of a heap
 */
int *order_node(heap_t **root)
{
	heap_t *head;
	head = *root;
	int temp;

	printf("Inserted: %d\n", head->n);
	while (head->parent)
	{
		if (head->n > head->parent->n)
		{
			temp = head->n;
			head->n = head->parent->n;
			head->parent->n = temp;
			head = head->parent;
		}
		else
			break;
	}
	
	return (0);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap.
 * @root: is a double pointer to the root node of the Heap.
 * @value: is the value to store in the node to be inserted.s
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *temp;
	int size, m;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	if  (*root == NULL)
	{
		new_node->parent = *root;
		*root = new_node;
		return (new_node);
	}

	size = measure(*root);
	if (size % 2 == 1)
		m = (size + 1) / 2;
	else
		m = size / 2;

	temp = ith_node(*root, m);
	new_node->parent = temp;
	if (temp->left == NULL)
		temp->left = new_node;
	else
		temp->right = new_node;

	order_node(&new_node);
	return (new_node);
}
