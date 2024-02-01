#include "binary_trees.h"

/**
 * binary_tree_insert_left - a node is inserted as a left-child of
 *                           of another in a binary tree.
 * @parent: pointer to the node to which left-child is inserted.
 * @value: value to be stored in the new node.
 *
 * Return: NULL (failure).
 *         a pointer to the new node (Success).
 *
 * Description: If parent has a left-child, the new node
 *              replaces it and the old left-child becomes
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
