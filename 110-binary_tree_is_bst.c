#include "binary_trees.h"

/**
 * binary_tree_is_bst_rec - Helper function to check
 * if a binary tree is a BST recursively
 * @tree: Pointer to the root node of the subtree being checked
 * @prev: Pointer to the previous node in the inorder traversal sequence
 *
 * This recursive function checks whether the binary tree rooted
 * at the specified node is a binary search tree (BST) by performing
 * an inorder traversal and comparing each
 * node with its predecessor in the inorder traversal sequence.
 *
 * @tree: Pointer to the root node of the subtree being checked
 * @prev: Pointer to the previous node in the inorder traversal sequence
 *
 * Return: 1 if the binary tree is a binary search tree (BST), 0 otherwise
 */
int binary_tree_is_bst_rec(binary_tree_t *tree, binary_tree_t *prev)
{
	if (!tree)
		return (1);
	if (!binary_tree_is_bst_rec(tree->left, prev))
		return (0);
	if (prev != NULL && tree->n <= prev->n)
		return (0);
	prev = tree;
	return (binary_tree_is_bst_rec(tree->right, prev));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a binary search tree (BST)
 * @tree: Pointer to the root node of the tree
 *
 * This function checks whether the binary tree rooted at the specified node
 * is a binary search tree (BST).
 * A binary search tree is a binary tree in which the left subtree of a node
 * contains only nodes with keys less than the node's
 * key, and the right subtree of a node contains only nodes with keys greater
 * than the node's key, and both the left and right subtrees are also binary
 * search trees.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the binary tree is a binary search tree (BST),
 * 0 otherwise or if the tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree ? binary_tree_is_bst_rec((binary_tree_t *)tree, NULL) : 0);
}
