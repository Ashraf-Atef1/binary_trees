#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
/**
 * heap_to_sorted_array - Converts a binary heap into a sorted array
 * @heap: Pointer to the root node of the binary heap
 * @size: Pointer to a variable to store the size of the resulting array
 *
 * This function converts a binary heap into a sorted array by repeatedly
 * extracting the root value from the heap using the heap_extract() function.
 * It allocates memory for the sorted array and returns a pointer to it,
 * along with the size of the array. If the heap is empty, it returns NULL.
 *
 * @heap: Pointer to the root node of the binary heap
 * @size: Pointer to a variable to store the size of the resulting array
 *
 * Return: Pointer to the sorted array, or NULL if the heap is empty
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int heap_size = binary_tree_size(heap), i = 0,
		*sorted_array = (int *)malloc(sizeof(int) * heap_size);

	if (!heap)
	{
		free(sorted_array);
		return (NULL);
	}
	*size = heap_size;
	while (i < heap_size)
		sorted_array[i++] = heap_extract(&heap);
	return (sorted_array);
}
