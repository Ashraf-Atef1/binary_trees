#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *second_node;

	if (!tree)
		return (tree);
	second_node = tree->left;
	second_node->parent = tree->parent;
	tree->parent = second_node;
	tree->left = second_node->right;
	if (second_node->right)
		second_node->right->parent = tree;
	second_node->right = tree;
	return (second_node);
}
