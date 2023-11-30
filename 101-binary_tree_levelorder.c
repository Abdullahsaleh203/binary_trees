#include "binary_trees.h"

/**
 * binary_tree_height_aux -  a tree
 * @tree: Pointer to
 * Return: Trees
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 * 2. If the tree is not empty,
 * then height = 1 + max of left height and right heights.
 *
 * 3. Use the recursive helper function to get the
 * height of left and right subtrees of the current node recursively.
 *
 * 4. Get the max of left height and right height and
 * add 1 to it for the current node.
 *
 * 5. Return the height.
 *
 * Time Complexity: O(n)
 */
size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);
	if (tree->left)
		hleft = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_aux(tree->right);

	if (hleft > hright)
		return (hleft);
	return (hright);
}

/**
 * print_level_order - print each
 * @tree: pointer to thse
 * @level: level of the tree
 * @func: pointer to a  node
 * Return: void
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return.
 * 2. If the level is 1, print the node.
 * 3. If the level is greater than 1, recursively
 * call the function for the left and right subtrees.
 *
 * Time Complexity: O(n)
 */

void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - function that goes through a
 * binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Return: void
 *
 * FUNCTIONALITY *
 *
 * 1. First, we calculate the height of the tree.
 * 2. Then, we iterate through the tree from level 1 to height.
 * 3. For each level, we call print_level_order() function.
 *
 * 4. In print_level_order() function, we first check if the
 * current node is NULL. If yes, then we return.
 *
 * 5. If the current node is not NULL, then we check if the
 * current level is 1. If yes, then we print the data of the
 * current node.
 *
 * 6. If the current level is greater than 1,
 * then we recursively call print_level_order() for left and
 * right children of the current node.
 *
 * 7. The recursion ends when the current level is 1.
 *
 * Time Complexity: O(n)
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0;
	int len = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_aux(tree) + 1;

	while (len <= height)
	{
		print_level_order(tree, len, func);
		len++;
	}
}
