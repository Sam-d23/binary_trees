#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks whether a node is a leaf of a binary tree.
 * @node: points to the node being checked.
 *
 * Return: 1 (Success)
 *         0 (failure)
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
