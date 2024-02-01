#include "binary_trees.h"
#include "limits.h"

/**
 * is_bst_helper - Function to check if a binary
 * tree is a valid binary search tree.
 * @tree: pointer to the root node of the tree to be checked.
 * @lo: value of the smallest visited node.
 * @hi: value of the largest visited node.
 *
 * Return: 1 (Success), 0 (failure).
 */
int is_bst_helper(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_helper(tree->left, lo, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - function to check if a binary tree
 * is a valid binary search tree.
 * @tree: points to the root node of the tree to be checked.
 *
 * Return: 1 (when the tree is a valid BST), else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
