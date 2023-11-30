#include "binary_trees.h"

/**
 * is_full_recursive - Checks if a binary tree is full recursively.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is not full, 0.
 *         Otherwise, 1.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 1.
 * 2. If the tree is not empty, check if the left
 * and right subtrees are full.
 *
 * 3. If the left and right subtrees are full,
 * check if the left and right subtrees are empty.
 *
 * 4. If the left and right subtrees are empty, return 1.
 * 5. If the left and right subtrees are not empty, return 0.
 *
 * Time Complexity: O(n)
 */

int is_full_recursive(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left == NULL && tree->right != NULL) ||
			(tree->left != NULL && tree->right == NULL) ||
			is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to
 * check.
 *
 * Return: If tree is NULL or is not full - 0.
 *         Otherwise - 1.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. If the tree is not empty, call the recursive function is_full_recursive()
 * to check if the tree is full.
 *
 * 3. The recursive function is_full_recursive() returns 1
 * if the tree is full, otherwise returns 0.
 *
 * 4. The tree is full if:
 * (a). The tree is a leaf node.
 * (b). The left subtree is full.
 * (c). The right subtree is full.
 * (d). The left and right subtrees have the same number of nodes.
 *
 * Time Complexity: O(n)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_full_recursive(tree));
}
