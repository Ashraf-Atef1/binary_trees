#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function counts the number of nodes
 * (including both internal nodes and leaf nodes)
 * in the binary tree rooted at the specified node.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the binary tree,
 * or 0 if the tree is NULLor has no children
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
