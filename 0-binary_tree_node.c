#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: a pointer to the new node, or NULL on failure
 *
 * FUNCTIONALITY
 *
 * 1. Allocate memory for a new binary tree node.
 * 2. If the allocation fails, return NULL.
 * 3. Set the value of the new node to the value passed in.
 * 4. Set the parent of the new node to the parent passed in.
 * 5. Set the left child of the new node to NULL.
 * 6. Set the right child of the new node to NULL.
 * 7. Return a pointer to the new node.
 *
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
