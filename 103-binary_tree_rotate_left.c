#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  a left rotation
 * @tree: Pointerroot
 *
 * Return: Pointer  root
 *
 * FUNCTIONALITY *
 *
 * 1. Check if the tree is empty. If it is, return NULL.
 * 2. Store the right child of the tree in a temporary variable.
 *
 * 3. Check if the right child has a left child.
 * If it does, set the parent of the left child to the tree.
 *
 * 4. Set the right child of the tree to the left child of the right child.
 *
 * 5. Set the left child of the right child to the tree.
 * 6. Set the parent of the tree to the parent of the right child.
 * 7. Set the parent of the right child to the tree.
 *
 * 8. Check if the parent of the right child is not NULL and
 * if the left child of the parent is the tree.
 * If it is, set the left child of the parent to the right child.
 *
 * 9. Check if the parent of the right child is not NULL and
 * if the right child of the parent is the tree.
 * If it is, set the right child of the parent to the right child.
 *
 * 10. Return the right child
 *
 * Time Complexity: O(1)
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *chl, *parent = tree;

	if (!tree)
		return (NULL);

	chl = parent->right;
	if (!chl)
		return (tree);

	if (chl->left)
		chl->left->parent = parent;

	parent->right = chl->left;
	chl->left = parent;
	chl->parent = parent->parent;
	parent->parent = chl;

	if (chl->parent && chl->parent->left == parent)
		chl->parent->left = chl;
	else if (chl->parent)
		chl->parent->right = chl;

	return (chl);
}
