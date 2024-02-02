#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - the minimum value of a binary search tree is returned.
 * @root: points to the root node of the BST being searched.
 *
 * Return: The minimum tree's value.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - a node from a binary search tree is deleted.
 * @root: points to the BST's root node.
 * @node: points to the node to be deleted from the BST.
 *
 * Return: pointer to the emergent root node after deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - a node is removed from a binary search tree recursively.
 * @root: points to the root node of the BST from which a node is removed.
 * @node: points to the initial node in the BST.
 * @value: value to be removed from the BST.
 *
 * Return: pointer to the current root node after deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - a node is removed from a binary search tree.
 * @root: points to the root node of the BST from which a node is to be removed.
 * @value: value to be removed in the BST.
 *
 * Return: pointer to the current root node after deletion.
 *
 * Description: when the node being deleted has two children, it
 *              is replaced by its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
