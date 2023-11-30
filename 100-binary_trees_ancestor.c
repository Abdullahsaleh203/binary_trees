#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowes
 * @first: Pointer
 * @second: Pointer
 *
 * Return: Pointer
 *
 * FUNCTIONALITY *
 *
 * 1. It’s iterating over the first node’s ancestors.
 * 2. For each ancestor, it’s iterating over the second node’s ancestors.
 *
 * 3. If the ancestor of the first node is the same as the ancestor of the
 * second node, then we’ve found the lowest common ancestor.
 *
 * 4. If we don’t find a common ancestor, then we return NULL.
 *
 * Time Complexity: O(n^2)
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	const binary_tree_t *f_anc, *s_anc;

	for (f_anc = first; f_anc; f_anc = f_anc->parent)
		for (s_anc = second; s_anc; s_anc = s_anc->parent)
			if (f_anc == s_anc)
				return ((binary_tree_t *)f_anc);
	return (NULL);
}
