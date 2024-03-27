#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Build a basic binary tree
 *
 * Return: A pointer to the created tree
 */
binary_tree_t *basic_tree(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 90);
	root->right = binary_tree_node(root, 85);
	root->left->right = binary_tree_node(root->left, 80);
	root->left->left = binary_tree_node(root->left, 79);
	return (root);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int heap;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 90);
	root->right = binary_tree_node(root, 85);
	root->left->left = binary_tree_node(root->left, 87);
	root->left->right = binary_tree_node(root->left, 25);
	root->right->left = binary_tree_node(root->right, 29);
	/*root->right->right = binary_tree_node(root->right, 40);*/
	/*root->right->right->left = binary_tree_node(root->right->right, 39);*/
	/*root->right->right->right = binary_tree_node(root->right->right, 38);*/
	root->right->left->left = binary_tree_node(root->right->left, 22);
	root->right->left->right = binary_tree_node(root->right->left, 28);
	root->left->right->left = binary_tree_node(root->left->right, 21);
	root->left->right->right = binary_tree_node(root->left->right, 20);
	root->left->left->left = binary_tree_node(root->left->left, 35);
	root->left->left->right = binary_tree_node(root->left->left, 45);

	heap = binary_tree_is_heap(root);
	printf("Is the tree with root node (%d) a Max Heap: %d\n", root->n, heap);

	binary_tree_print(root);
	return (0);
}
