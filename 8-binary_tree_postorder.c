#include "binary_trees.h"

/**
 * binary_tree_postorder - a binary tree is traversed using post-order traversal.
 * @tree: points to the root node of the tree being traverse.
 * @func: points to a function to be called for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
