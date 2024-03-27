#include "binary_trees.h"

/**
 * sorted_array_to_avl_rec - Recursively converts
 * a sorted array into an AVL tree
 * @array: Pointer to the sorted array of integers
 * @start: Index of the start of the current subarray
 * @end: Index of the end of the current subarray
 * @parent: Pointer to the parent node of the current node
 *
 * This function recursively converts a sorted array of integers
 * into an AVL tree.
 * It constructs the AVL tree by selecting the middle element of
 * the subarray as the root node and recursively builds the left
 * and right subtrees using the subarrays
 * to the left and right of the middle element.
 *
 * @array: Pointer to the sorted array of integers
 * @start: Index of the start of the current subarray
 * @end: Index of the end of the current subarray
 * @parent: Pointer to the parent node of the current node
 *
 * Return: Pointer to the root node of the resulting AVL tree,
 * or NULL if the current subarray is empty
 */
avl_t *sorted_array_to_avl_rec(int *array, int start, int end, avl_t *parent)
{
	binary_tree_t *newNode = start <= end ? malloc(sizeof(binary_tree_t)) : NULL;
	int mid = (start + end) / 2;

	if (!newNode)
		return (NULL);
	newNode->n = array[mid];
	newNode->parent = parent;
	newNode->left = sorted_array_to_avl_rec(array, start, mid - 1, newNode);
	newNode->right = sorted_array_to_avl_rec(array, mid + 1, end, newNode);
	return (newNode);
}
/**
 * sorted_array_to_avl - Converts a sorted array into an AVL tree
 * @array: Pointer to the sorted array of integers
 * @size: Size of the array
 *
 * This function converts a sorted array of integers into an AVL tree. It calls
 * the sorted_array_to_avl_rec() function to recursively build the AVL tree
 * from the sorted array elements.
 *
 * @array: Pointer to the sorted array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the root node of the resulting AVL tree, or NULL
 * if the array is empty or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (array ? sorted_array_to_avl_rec(array, 0, size - 1, NULL) : NULL);
}
