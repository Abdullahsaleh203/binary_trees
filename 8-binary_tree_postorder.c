#include "binary_trees.h"

/**
 * binary_tree_postorder - post-order traversal function
 * @tree: pointer to the root node
 * @func: pointer to function to call for each node
 * Description: 8. Post-order traversal
 * Return: nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	/* base case */
	if ((tree == NULL) || (func == NULL))
	{
		;
	}

	/* recursively traverse on the left subtree and then the right */
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
