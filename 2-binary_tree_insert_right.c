#include "binary_trees.h"

/**
 * binary_tree_insert_right - A node is inserted as the right-child
 *                            of another in a binary tree.
 * @parent: A pointer to the node to which the right-child is inserted.
 * @value: The value to be stored in the new node.
 *
 * Return: NULL (failure).
 *         a pointer to the new node (Success).
 *
 * Description: If parent already has a right-child, the new node
 *              replaces it and the previous right-child is set as
 *              the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
