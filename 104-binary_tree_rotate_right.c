#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function performs a right rotation on the binary tree rooted at the
 * specified node. A right rotation is a transformation that moves the left
 * child of the specified node up to the position of the specified node, with
 * the specified node becoming the right child of the new root.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Pointer to the new root node after the right rotation
 */
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
