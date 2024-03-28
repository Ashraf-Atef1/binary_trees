#include "binary_trees.h"

/**
 * array_to_heap - Converts an array into a binary search tree (HEAP)
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * This function converts the given array of integers into
 * a binary search tree (HEAP) by inserting each element
 * of the array into the HEAP using the heap_insert() function.
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the resulting HEAP,
 * or NULL if the array is empty
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t i = 0;
	heap_t *root = NULL;

	while (i < size)
		heap_insert(&root, array[i++]);
	return (root);
}
