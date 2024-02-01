#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks whether a node is a root of a binary tree.
 * @node: pointer to the node being checked.
 *
 * Return: 1 (Success)
 *         0 (failure)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}

