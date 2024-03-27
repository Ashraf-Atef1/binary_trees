#include "binary_trees.h"

int is_bst_rec(const binary_tree_t *tree, const binary_tree_t *root);
int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_is_avl - Checks if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the binary tree
 *
 * This function checks whether the binary tree rooted at the specified node
 * is an AVL tree. An AVL tree is a binary search tree (BST) in which the
 * heights of the left and right subtrees of every node differ by at most 1,
 * and all subtrees of the tree are also AVL trees.
 *
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is an AVL tree,
 * 0 otherwise or if the tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (tree ? !binary_tree_balance(tree) && is_bst_rec(tree, tree) : 0);
}

/**
 * is_bst_rec - Helper function to check
 * if a binary tree is a BST recursively
 * @tree: Pointer to the root node of the subtree being checked
 * @root: Pointer to the previous node in the inorder traversal sequence
 *
 * This recursive function checks whether the binary tree rooted
 * at the specified node is a binary search tree (BST) by performing
 * an inorder traversal and comparing each
 * node with its predecessor in the inorder traversal sequence.
 *
 * Return: 1 if the binary tree is a binary search tree (BST), 0 otherwise
 */
int is_bst_rec(const binary_tree_t *tree, const binary_tree_t *root)
{
	if (!tree)
		return (1);
	if (tree && !tree->left && !tree->right)
	{
		binary_tree_t *curent_parent = tree->parent;
		int is_left = curent_parent && curent_parent->left == tree;

		while (curent_parent)
		{
			if (is_left && tree->n >= curent_parent->n)
				return (0);
			if (!is_left && tree->n <= curent_parent->n)
				return (0);
			if (!curent_parent->parent || curent_parent == root)
				break;
			is_left = curent_parent->parent->left == curent_parent;
			curent_parent = curent_parent->parent;
		}
	}
	return (is_bst_rec(tree->left, root) && is_bst_rec(tree->right, root));
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
