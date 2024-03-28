#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	heap_t *root;
	int array[] = {
		98, 110, 43, 56, 2, 78, 123, 76, 234};
	size_t size = sizeof(array) / sizeof(array[0]);
	int value;

	root = array_to_heap(array, size);
	binary_tree_print(root);

	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	value = heap_extract(&root);
	printf("Extracted: %d\n", value);
	binary_tree_print(root);
	return (0);
}
