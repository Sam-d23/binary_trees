#include "binary_trees.h"

/**
 * bst_search - Function to search for a value in a binary search tree.
 * @tree: pointer to the root node of the BST being searched.
 * @value: value being searched for in the BST.
 *
 * Return: NULL (failure)
 *         else, pointer to the node containing the value.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree != NULL)
	{
		if (tree->n == value)
			return ((bst_t *)tree);
		if (tree->n > value)
			return (bst_search(tree->left, value));
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
