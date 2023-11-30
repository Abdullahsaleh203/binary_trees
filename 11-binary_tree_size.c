#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: If the tree is NULL, must return 0
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. If the tree is not empty, add 1 to the size of the
 * left subtree and the right subtree.
 *
 * 3. Return the size of the tree.
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += binary_tree_size(tree->left);
		size += binary_tree_size(tree->right);
	}
	return (size);
}
