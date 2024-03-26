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
	binary_tree_t *root;

	root = binary_tree_rotate_left(NULL);
	printf("Root: %p\n", (void *)root);
	return (0);
}
