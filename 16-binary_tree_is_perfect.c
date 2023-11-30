#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
						 size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if a node is a leaf of a binary tree.
 * @node: A pointer to the node to check.
 *
 * Return: If the node is a leaf, 1, otherwise, 0.
 *
 * FUNCTIONALITY *
 *
 * 1. It’s checking if the node is NULL. If it is, it returns 0.
 *
 * 2. If the node is not NULL, it checks if the node is a leaf.
 * If it is, it returns 1.
 *
 * 3. If the node is not a leaf, it returns 0.
 *
 */

unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - Returns the depth of a given
 *         node in a binary tree.
 * @tree: A pointer to the node to measure the depth of.
 *
 * Return: The depth of node.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is NULL, return 0.
 * 2. If the tree is not NULL, return 1 + the depth of the parent.
 *
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - Returns a leaf of a binary tree.
 * @tree: A pointer to the root node of the tree to find a leaf in.
 *
 * Return: A pointer to the first encountered leaf.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is a leaf, return the tree.
 *
 * 2. If the tree is not a leaf, return the left subtree if it exists,
 * otherwise return the right subtree.
 *
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - Checks if a binary tree is perfect recursively.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: If the tree is perfect, 1, otherwise 0.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is a leaf, return 1 if the current level is
 * the same as the leaf depth, otherwise return 0.
 *
 * 2. If the tree is not a leaf, but one of its children is missing, return 0.
 * 3. Otherwise, recursively check the left and right subtrees.
 *
 */
int is_perfect_recursive(const binary_tree_t *tree,
						 size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
			is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, return 0.
 *
 * 2. If the tree is not empty, call the recursive function
 * is_perfect_recursive() with the tree, the depth of the tree, and 0.
 *
 * 3. The recursive function is_perfect_recursive() will return 1
 * if the tree is perfect, and 0 otherwise.
 *
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
