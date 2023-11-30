#include "binary_trees.h"

/**
 * isBST - Compare node in order to check if a given
 *
 * @tree: pointer to the root node of the tree to check
 * @min: min value
 * @max: max value
 *
 * Return: 1 if success, 0 otherwise
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, it’s a BST.
 * 2. If the tree is not empty, then:
 *  a. Check if the max value of the left subtree is smaller than the root.
 *  b. Check if the min value of the right subtree is greater than the root.
 *  c. Check if both left and right subtrees are BSTs.
 *
 * Time Complexity: O(n)
 */
int isBST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
		isBST(tree->left, min, tree->n - 1) &&
		isBST(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search tree
 *
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if success, 0 otherwise
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return true.
 * 2. Else, recursively check if the left and right subtrees are BSTs.
 *
 * 3. For every node, check if the node’s value is greater
 * than the min value and less than the max value.
 *
 * 4. Return true if all the above conditions hold.
 *
 * Time Complexity: O(n)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (isBST(tree, INT_MIN, INT_MAX));
}
