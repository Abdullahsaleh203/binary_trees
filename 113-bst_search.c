#include "binary_trees.h"

/**
 * bst_search - ches for a value in a Binary Search Tree
 *
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty or the value is found, return the tree.
 * 2. If the value is less than the current node, search the left subtree.
 * 3. If the value is greater than the current node, search the right subtree.
 *
 * Time Complexity: O(h)
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((binary_tree_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	return (bst_search(tree->right, value));
}
