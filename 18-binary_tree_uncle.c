#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *                     in a binary tree.
 * @node: A pointer to the node to find the uncle of.
 *
 * Return: If node is NULL or has no uncle, NULL.
 *         Otherwise, a pointer to the uncle node.
 *
 * FUNCTIONALITY
 *
 * 1. If the node is NULL, return NULL.
 *
 * 2. If the node’s parent is NULL, return NULL.
 *
 * 3. If the node’s grandparent is NULL, return NULL.
 *
 * 4. If the node’s parent is the left child of the grandparent,
 * return the grandparent’s right child.
 *
 * 5. Otherwise, return the grandparent’s left child.
 *
 * Time Complexity: O(1)
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL ||
		node->parent == NULL ||
		node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);
	return (node->parent->parent->left);
}
