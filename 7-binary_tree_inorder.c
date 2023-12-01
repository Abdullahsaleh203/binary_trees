#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal
 * @func: pointer to a function to call for each node.
 * @tree: pointer to the root node of the tree to traverse
 *
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!func || !tree)
		return;

	binary_tree_inorder(tree->right, func);
	func(tree->n);
	binary_tree_inorder(tree->left, func);
}
