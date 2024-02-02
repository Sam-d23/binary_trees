#include "binary_trees.h"

/**
 * binary_tree_height - the height of a binary tree is measured
 * @tree: points to root node of the tree
 *
 * Return: the height (success),  0 (failure)
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left >= right)
		return (1 + left);
	return (1 + right);
}

/**
 * binary_tree_level - runs a function on a unique level of a binary tree
 * @tree: points to the root
 * @l: tree level to perform a function on
 * @func: function being performed
 *
 * Return: NULL
 */
void binary_tree_level(const binary_tree_t *tree, size_t l, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (l == 1)
		func(tree->n);
	else if (l > 1)
	{
		binary_tree_level(tree->left, l - 1, func);
		binary_tree_level(tree->right, l - 1, func);
	}
}

/**
 * binary_tree_levelorder - level-order traversal on a binary tree
 * @tree: points to the root node of the tree being traversed
 * @func: points to a function to call for every node.
 * Return: NULL
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height; i++)
		binary_tree_level(tree, i, func);
}
