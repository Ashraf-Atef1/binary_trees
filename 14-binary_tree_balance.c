#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - Computes the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function computes the balance factor of the binary tree rooted at
 * the specified node. The balance factor of a binary tree is defined as
 * the difference between the height of its left subtree and the height
 * of its right subtree.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Balance factor of the binary tree, or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function measures the height of
 * the binary tree rooted at the specified node.
 * The height of a binary tree is defined
 * as the length of the longest path from
 * the root node to a leaf node. The height of
 * an empty tree (or a tree with only
 * the root node) is 0.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Height of the binary tree,
 * -1 the tree is NULL or 0 if has no children
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (-1);
	if (!tree->left && !tree->right)
		return (0);
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}
