#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function performs a left rotation on the binary tree rooted at the
 * specified node. A left rotation is a transformation that moves the right
 * child of the specified node up to the position of the specified node, with
 * the specified node becoming the left child of the new root.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the new root node after the left rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *first_node = tree, *second_node = tree->right;

	second_node->parent = first_node->parent;
	first_node->parent = second_node;
	first_node->right = second_node->left;
	if (second_node->left)
		second_node->left->parent = first_node;
	second_node->left = first_node;
	return (second_node);
}
