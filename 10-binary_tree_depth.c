#include "binary_trees.h"

/**
 * binary_tree_depth - the depth of a node in a binary tree is measured.
 * @tree: points to the node whose depth is to be measured.
 *
 * Return: If tree is NULL,0, else the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

