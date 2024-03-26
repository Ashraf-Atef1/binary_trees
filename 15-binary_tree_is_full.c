#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree
 *
 * This function checks whether the binary tree rooted at the specified node
 * is a full binary tree. A full binary tree is a binary tree in which every
 * node other than the leaves has exactly two children.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is full, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	if (tree && !tree->left && !tree->right)
		return (1);
	else if (!tree || !tree->left || !tree->right)
		return (0);
	left = binary_tree_is_full(tree->left);
	right = binary_tree_is_full(tree->right);
	return (left == right ? left : 0);
}
