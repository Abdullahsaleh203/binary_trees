#include "binary_trees.h"
/**
 * min_finder - Finds the minimum root
 * @root: pointer to the tree
 * Return: the min number
 *
 * FUNCTIONALITY *
 *
 * 1. If the root is NULL, return NULL.
 *
 * 2. If the root is not NULL, then recursively call
 * the min_finder function on the left subtree.
 *
 * 3. If the left subtree is NULL, then return the root.
 *
 * Time Complexity: O(h)
 */
bst_t *min_finder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 *
 * FUNCTIONALITY *
 *
 * 1. If the root is NULL, return NULL.
 * 2. If the value is less than the root,
 * recursively call bst_remove on the left subtree.
 *
 * 3. If the value is greater than the root,
 * recursively call bst_remove on the right subtree.
 *
 * 4. If the value is equal to the root,
 * we have found the node to remove.
 *
 * 5. If the node to remove has no children,
 * free the node and return NULL.
 *
 * 6. If the node to remove has only one child,
 * free the node and return the child.
 *
 * 7. If the node to remove has two children,
 * find the minimum value in the right subtree.
 * Replace the root with the minimum value.
 * Recursively call bst_remove on the right subtree
 * with the minimum value.
 *
 * Time Complexity: O(h)
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = min_finder(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
