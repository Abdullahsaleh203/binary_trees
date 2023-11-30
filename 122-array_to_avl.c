#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: Pointer to root
 *
 * FUNCTIONALITY *
 *
 * 1. It’s creating a new AVL tree node with the
 * value of the first element of the array.
 *
 * 2. It’s inserting the new node into the AVL tree.
 *
 * 3. It’s looping through the rest of the
 * array and inserting each element into the AVL tree.
 *
 * 4. It’s returning the root of the AVL tree.
 *
 * Time Complexity: O(n)
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (!array || size == 0)
		return (NULL);

	root = avl_insert(&root, array[0]);
	for (i = 1; i < size; i++)
		avl_insert(&root, array[i]);

	return (root);
}
