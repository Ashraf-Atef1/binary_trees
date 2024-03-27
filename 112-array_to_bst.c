#include "binary_trees.h"

/**
 * array_to_bst - Converts an array into a binary search tree (BST)
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * This function converts the given array of integers into
 * a binary search tree (BST) by inserting each element
 * of the array into the BST using the bst_insert() function.
 *
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the resulting BST,
 * or NULL if the array is empty
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root = NULL;

	while (i < size)
		bst_insert(&root, array[i++]);
	return (root);
}
