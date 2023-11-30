#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 *
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, create a new node and return it.
 * 2. If the tree is not empty, create a new node and insert it into the tree.
 * 3. If the value is already in the tree, return NULL.
 * 4. If the value is less than the current node, go left.
 * 5. If the value is greater than the current node, go right.
 * 6. If there is no left or right child, insert the new node.
 * 7. Return the new node.
 *
 * Time Complexity: O(log(n)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *tree_2;

	if (tree == NULL || *tree == NULL)
	{
		new = binary_tree_node(NULL, value);
		*tree = new;
		return (new);
	}

	tree_2 = *tree;

	while (tree_2 != NULL)
	{
		if (tree_2->n == value)
			return (NULL);
		if (tree_2->n > value)
		{
			if (tree_2->left == NULL)
			{
				tree_2->left = binary_tree_node(tree_2, value);
				return (tree_2->left);
			}
			tree_2 = tree_2->left;
		}
		if (tree_2->n < value)
		{
			if (tree_2->right == NULL)
			{
				tree_2->right = binary_tree_node(tree_2, value);
				return (tree_2->right);
			}
			tree_2 = tree_2->right;
		}
	}
	return (NULL);
}
