#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree
 * @node: Pointer to the node to check
 *
 * This function determines whether the specified
 * node is a leaf node in a binary tree.
 * A leaf node is defined as a node with no children
 * (neither left nor right child).
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise or if the node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}
