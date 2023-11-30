#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 *
 * FUNCTIONALITY *
 *
 * 1. It creates a new binary search tree.
 * 2. It inserts the first element of the array into the binary search tree.
 * 3. It inserts the second element of the array into the binary search tree.
 * 4. It inserts the third element of the array into the binary search tree.
 * 5. It inserts the fourth element of the array into the binary search tree.
 * 6. It returns the binary search tree.
 *
 * Time Complexity: O(n^2)
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t length;
	bst_t *tree = NULL;

	for (length = 0; length < size; length++)
		bst_insert(&tree, array[length]);

	return (tree);
}
