#include "binary_trees.h"

/**
 * count_nodes - Counts ths inside a tree
 * @root:  node
 *
 * Return: Number of nodes
 *
 * FUNCTIONALITY *
 *
 * 1. If the root is NULL, return 0.
 * 2. Else, return 1 + count_nodes(root->left) + count_nodes(root->right).
 * 3. We will get the number of nodes.
 *
 * Time Complexity: O(n)
 */

int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - Checks if a tree is complete
 * @root: Pointer to tree's root
 * @index: Index of the node been evaluated
 * @n: number of trees nod
 *
 * Return: 1 if the tree is a heap, 0 otherwise
 *
 * FUNCTIONALITY *
 *
 * 1. If the root is NULL, return 0.
 * 2. If the index is greater than or equal to the number of nodes, return 0.
 * 3. If the root is a leaf node, return 1.
 * 4. If the root has a right child but no left child, return 0.
 *
 * 5. If the root has a left child but no right child,
 * check if the left child is a leaf node.
 * If yes, return 1. Else, recursively check if the left subtree is complete.
 *
 * 6. If the root has both left and right children,
 * recursively check if the left and right subtrees are complete.
 *
 * Time Complexity: O(n)
 */
int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (0);

	if (index >= n)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (is_complete(root->left, index * 2 + 1, n));

	return (is_complete(root->left, index * 2 + 1, n) &&
			is_complete(root->right, index * 2 + 2, n));
}

/**
 * binary_tree_is_complete - check for bt complete
 * @tree: Pointer to root
 *
 * Return: 1 if
 *
 * FUNCTIONALITY
 *
 * This function checks to see is the binary tree is complete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int nod;
	binary_tree_t *root;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nod = count_nodes(root);

	return (is_complete(root, 0, nod));
}
