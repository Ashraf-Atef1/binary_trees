#include "binary_trees.h"

/**
 * array_to_avl - Converts an array into a binary search tree (AVL)
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * This function converts the given array of integers into
 * a binary search tree (AVL) by inserting each element
 * of the array into the AVL using the avl_insert() function.
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the resulting AVL,
 * or NULL if the array is empty
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	avl_t *root = NULL;

	while (i < size)
		avl_insert(&root, array[i++]);
	return (root);
}
