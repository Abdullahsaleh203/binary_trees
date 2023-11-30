#include "binary_trees.h"

/**
 * btl - auxiliary level
 *
 * @tree: pointer to root
 * Return: integer with level
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 *
 * 2. If the tree is a leaf node, return 1.
 *
 * 3. If the tree is not a leaf node, recursively
 * calculate the height of the left and right subtrees.
 *
 * 4. Return the maximum of the two heights plus 1.
 *
 * Time Complexity: O(n)
 */
int btl(const binary_tree_t *tree)
{
	int h_left, h_right;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	h_left = btl(tree->left);
	h_right = btl(tree->right);
	if (h_left > h_right)
		return (h_left + 1);
	else
		return (h_right + 1);
}

/**
 * bt_balance - factor calculate
 *
 * @tree: pointer to root
 * Return: integer with factor
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. Otherwise, return the difference between the left and right subtrees.
 * 3. The btl function is a helper function that
 * returns the height of the tree.
 *
 * Time Complexity: O(n)
 */
int bt_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (btl(tree->left) - btl(tree->right));
}

/**
 * bavl - Check level
 *
 * @tree: pointer to root
 * @min: min value
 * @max: max value
 * Return: 1 if is AVL, 0 otherwise
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, it’s a valid AVL tree.
 *
 * 2. If the tree’s value is greater than the max or less than the min,
 * it’s not a valid AVL tree.
 *
 * 3. If the tree’s balance is greater than 1 or less than -1,
 * it’s not a valid AVL tree.
 *
 * 4. If the tree’s left subtree is a valid AVL tree and the tree’s
 * right subtree is a valid AVL tree, then the tree is a valid AVL tree.
 *
 * Time Complexity: O(n)
 */
int bavl(const binary_tree_t *tree, int min, int max)
{
	int balance_left, balance_right, balance;

	if (tree == NULL)
		return (1);
	if (tree->n > max || tree->n < min)
		return (0);
	balance = bt_balance(tree);
	if (balance < -1 || balance > 1)
		return (0);
	balance_left = bavl(tree->left, min, tree->n - 1);
	balance_right = bavl(tree->right, tree->n + 1, max);
	if (balance_left == 1 && balance_right == 1)
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 *
 * FUNCTIONALITY
 *
 * 1. If the tree is empty, return 0.
 *
 * 2. Else, call the bavl function.
 *
 * 3. The bavl function takes the tree,
 * the minimum value and the maximum value as arguments.
 *
 * 4. If the tree is NULL, return 1.
 *
 * 5. Else, if the tree’s value is less than the
 * minimum value or greater than the maximum value, return 0.
 *
 * 6. Else, recursively call the bavl function for
 * the left and right subtrees.
 *
 * 7. If the left subtree is not an AVL tree, return 0.
 *
 * 8. Else, if the right subtree is not an AVL tree, return 0.
 *
 * 9. Else, return 1.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (bavl(tree, INT_MIN, INT_MAX));
}
