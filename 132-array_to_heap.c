#include "binary_trees.h"

/**
 * array_to_heap - a Max Binary Heap tree is built from an array
 * @array: points to the first element of the converted array
 * @size: number of array elements
 *
 * Return: pointer to the created binary heaps root node (success)
 *         NULL (failure)
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);

	return (root);
}
