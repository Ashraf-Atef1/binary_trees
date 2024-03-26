#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	bst_t *root;
	bst_t *node;
	int array[] = {
		98, 110, 43};
	size_t size = sizeof(array) / sizeof(array[0]);
	size_t i;

	root = NULL;
	for (i = 0; i < size; i++)
	{
		node = bst_insert(&root, array[i]);
		if (node)
			printf("Value inserted: %d\n", node->n);
		else
		{
			printf("Value not inserted: %d\n", array[i]);
		}
	}

	binary_tree_print(root);
	return (0);
}
