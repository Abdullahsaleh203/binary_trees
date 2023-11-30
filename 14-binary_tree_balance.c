#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: If tree is NULL, must return 0
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is NULL, return 0.
 * 2. Else, return the difference between the height of
 * the left subtree and the height of the right subtree.
 *
 * Time Complexity: O(n)
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
	}
	return (0);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: if the tree is NULL, must return 0
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is NULL, return 0.
 *
 * 2. If the tree is not NULL, then calculate the height
 * of the left subtree and right subtree.
 *
 * 3. Return the maximum of the left subtree
 * and right subtree.
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = (tree->left) ? 1 + binary_tree_height(tree->left) : 1;

		r = (tree->right) ? 1 + binary_tree_height(tree->right) : 1;
		return (l > r ? l : r);
	}
	return (0);
}
