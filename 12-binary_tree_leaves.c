#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the number of leaf nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function counts the number of leaf nodes in the binary tree rooted at
 * the specified node. A leaf node is a node that has no children (neither left
 * nor right child).
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of leaf nodes in the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
