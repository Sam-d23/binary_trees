#include "binary_trees.h"

/**
 * struct node_s - A singly-linked list
 * @node: the binary tree node
 * @next: points to the subsequent node
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Traverse a binary tree
 *                          using level-order traversal.
 * @tree: Points to the root node of the tree being traversed.
 * @func: Points to a function to call for every node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - func are called on all nodes at each level.
 * @head: Points to head of linked list with nodes at same level.
 * @func: Points to a function to calling each node.
 */
void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - children of parent are appended to linked list.
 * @head: Points to head of linked list.
 * @parent: Points to node whose children we want to append.
 * Return: Pointer to head of children linked list.
 */
ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds a new node at a linked lists' end
 * @head: pointer to linked lists' head
 * @btnode: binary tree node to be apended
 * Return: the pointer to head, or NULL (failure)
 */
ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - frees all nodes in a linked list
 * @head: points to the head of list_t linked list
 */
void free_list(ll *head)
{
	ll *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
