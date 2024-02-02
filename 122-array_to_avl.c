#include "binary_trees.h"

/**
 * array_to_avl - an AVL tree from an array is built.
 * @array: pointer to the first converted element of the array.
 * @size: number of elements in array.
 *
 * Return: pointer to the root node of the created AVL (Success), NULL (failure).
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}
		if (j == i)
		{
			if (avl_insert(&tree, array[i]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
