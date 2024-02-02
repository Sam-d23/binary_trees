#include "binary_trees.h"

/**
 * binary_tree_postorder -  postorder traversal on a binary tree
 * @tree: points to the root node of the tree being traversed
 * @func: points to a function call for every node.
 * Return: NULL
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
