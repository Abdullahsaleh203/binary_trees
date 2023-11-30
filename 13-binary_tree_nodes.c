#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is NULL, return 0.
 * 2. If the tree is not NULL, check if the tree has a left or right child.
 * If it does, add 1 to the nodes variable.
 *
 * 3. Recursively call the function on the left and right child of the tree.
 * 4. Return the nodes variable.
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
