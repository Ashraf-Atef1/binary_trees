#include "binary_trees.h"
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * This function checks whether the binary tree rooted at the specified node
 * is a perfect binary tree. A perfect binary tree is a full binary tree in
 * which all leaf nodes are at the same depth.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return (binary_tree_is_full(tree) && !binary_tree_balance(tree));
}
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
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);
	l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
	r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
	return ((l > r) ? l : r);
}

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
