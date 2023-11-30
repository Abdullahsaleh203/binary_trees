#include "binary_trees.h"

/**
 * avl_insert_full - Inserts a value
 *
 * @tree: pointer to the root
 * @parent: parent of node
 * @value: the value
 * Return: pointer to the new_node node
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, create a new node and return it.
 * 2. If the value already exists in the tree, return NULL.
 *
 * 3. If the value is less than the current node,
 * recursively call the function on the left child.
 *
 * 4. If the value is greater than the current node,
 * recursively call the function on the right child.
 *
 * Time Complexity: O(log(n)
 */
avl_t *avl_insert_full(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);
		if (parent->n > new_node->n)
			parent->left = new_node;
		else
			parent->right = new_node;
		return (new_node);
	}
	else if (value == tree->n)
		return (NULL);
	else if (value < tree->n)
		return (avl_insert_full(tree->left, tree, value));
	else
		return (avl_insert_full(tree->right, tree, value));
}

/**
 * val_balancer - rebalance an AVL tree if needed
 *
 * @root: pointer to the root of the tree
 * @tree: pointer to the node to be rebalanced
 * @value: inserted value
 * Return: 0
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, create a new node and return it.
 * 2. If the value is less than the current node,
 * recursively call the function on the left child.
 *
 * 3. If the value is greater than the current node,
 * recursively call the function on the right child.
 *
 * 4. If the value is equal to the current node,
 * return the current node.
 *
 * 5. If the value is not equal to the current node,
 * set the current node’s height.
 *
 * 6. If the current node’s balance is greater than 1 or less than -1,
 *  call the balance function.
 *
 * 7. If the balance is greater than 1,
 * and the value is less than the left child, rotate right.
 *
 * 8. If the balance is greater than 1,
 * and the value is greater than the left child,
 * rotate left on the left child, then rotate right.
 *
 * 9. If the balance is less than -1,
 * and the value is greater than the right child, rotate left.
 *
 * 10. If the balance is less than -1,
 * and the value is less than the right child,
 * rotate right on the right child, then rotate left.
 *
 * 11. Return the current node.
 *
 * Time Complexity: O(log(n)
 */
void val_balancer(avl_t **root, avl_t *tree, int value)
{
	int new_balance;

	new_balance = binary_tree_balance(tree);
	if (new_balance > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_balance < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}

/**
 * avl_insert - Insets the value in avl
 *
 * @tree: double pointer to root
 * @value: the value
 * Return: pointer to the new node
 *
 * FUNCTIONALITY *
 *
 * 1. If the tree is empty, create a new node and return it.
 *
 * 2. If the tree is not empty,
 * call avl_insert_full() to insert the new node.
 *
 * 3. If the new node is inserted successfully,
 * call val_balancer() to balance the tree.
 *
 * 4. Return the new node.
 *
 * Time Complexity: O(log(n)
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *predecessor;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}
	new_node = avl_insert_full(*tree, NULL, value);

	if (new_node == NULL)
		return (NULL);

	predecessor = new_node->parent;

	while (predecessor != NULL)
	{
		val_balancer(tree, predecessor, value);
		predecessor = predecessor->parent;
	}

	return (new_node);
}
