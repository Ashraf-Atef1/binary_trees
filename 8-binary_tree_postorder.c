#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs a post-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * This function performs a post-order traversal on the binary tree
 * rooted at the specified node, applying the given function to
 * each node visited.
 * Post-order traversal visits the left subtree,
 * then the right subtree, and finally the current node recursively.
 *
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * Note: The provided function must accept an integer parameter representing
 * the value stored in each node.
 * If the function pointer is NULL, this function does nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}