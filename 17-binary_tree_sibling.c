#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a
 *                       node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: If node is NULL or there is no sibling - NULL.
 *         Otherwise - a pointer to the sibling.
 *
 * FUNCTIONALITY *
 *
 * 1. If the node is NULL or the parent is NULL, return NULL.
 *
 * 2. If the node is the left child of the parent,
 * return the right child of the parent.
 *
 * 3. If the node is the right child of the parent,
 * return the left child of the parent.
 *
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}
