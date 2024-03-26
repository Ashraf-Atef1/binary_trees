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
	binary_tree_t *root;
	int bst;

	root = binary_tree_node(NULL, 98);

	bst = binary_tree_is_bst(root);
	printf("Is the tree with root node (%d) a BST: %d\n", root->n, bst);

	binary_tree_print(root);
	return (0);
}
