#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
int binary_tree_is_complete_rec(const binary_tree_t *tree,
								size_t index, size_t size);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 *
 * This function checks whether the binary tree rooted at the specified node
 * is a complete binary tree. A complete binary tree is a binary tree in which
 * every level, except possibly the last, is completely filled, and all nodes
 * are as far left as possible.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is complete, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	return (tree && binary_tree_is_complete_rec(tree, 0, binary_tree_size(tree)));
}
/**
 * binary_tree_is_complete_rec - Helper function to check
 * if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Current index of the node being checked
 * @size: Total number of nodes in the tree
 *
 * This recursive function checks if the binary tree rooted
 * at the specified node is a complete binary tree by traversing
 * the tree in a level-order manner and checking
 * if all nodes are present and in the correct order.
 *
 * @tree: Pointer to the root node of the tree
 * @index: Current index of the node being checked
 * @size: Total number of nodes in the tree
 *
 * Return: 1 if the binary tree is complete, 0 otherwise
 */
int binary_tree_is_complete_rec(const binary_tree_t *tree,
								size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (binary_tree_is_complete_rec(tree->left, index * 2 + 1, size) &&
			binary_tree_is_complete_rec(tree->right, index * 2 + 2, size));
}
/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function measures the size of the binary tree
 * rooted at the specified node.
 * The size of a binary tree is defined as
 * the total number of nodes in the tree.
 * The size of an empty tree is 0.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
