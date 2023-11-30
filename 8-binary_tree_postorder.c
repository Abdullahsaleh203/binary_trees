#include "binary_trees.h"

/**
 * binary_tree_postorder - Goes through a binary tree using
 * post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * FUNCTIONALITY
 *
 * 1. If the tree is not empty and the function pointer is not NULL, then
 * 2. Traverse the left subtree
 * 3. Traverse the right subtree
 * 4. Call the function pointer on the current node
 *
 * Time Complexity: O(n)
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
