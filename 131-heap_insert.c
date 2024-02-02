#include "binary_trees.h"

/**
 * heap_insert - a value is inserted in Max Binary Heap
 * @root: double pointer pointing to root node
 * of the Heap where to insert the value
 * @value: value to be stored in the inserted node
 *
 * Return:  pointer to  created node (success)
 *         NULL (failure)
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, leaves, sub, bit, level, tmp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;
	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;
	/*
	 * Traverse tree and empties slot based on the binary
	 * representation of the number of leaves.
	 * If a complete tree has 12 nodes, there are 5 leaves on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 matches
	 * right, 0 to left.
	 *  first empty node is 101 == RLR, *root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - the size of a binary tree is measured
 * @tree: tree whose size is to be measured
 *
 * Return:  tree size
 *         0 when tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

