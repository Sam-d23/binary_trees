#include "binary_trees.h"

/**
 * bal - balance factor of a AVL is measured
 * @tree: tree to be traversed
 * Return: The balanced factor
 */
void bal(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - gets the min node in the right subtree
 * @node: tree to be checked
 * Return: the min tree value
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}
/**
 *remove_type - removes a node depending on its children
 *@root: node to be removed
 *Return: 0 (failure),  other value (success)
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}
/**
 * bst_remove - a node from a BST tree is removed
 * @root: tree's root
 * @value: node containing this value to be removed
 * Return: the modified tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - a node from a AVL tree is remoed
 * @root: tree's root
 * @value: node containing this value to be removed
 * Return: the modified tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
