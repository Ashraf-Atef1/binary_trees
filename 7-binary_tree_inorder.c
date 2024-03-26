#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs an in-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * This function performs an in-order traversal
 * on the binary tree rooted at the
 * specified node, applying the given function to each node visited.
 * In-order traversal visits the left subtree,
 * then the current node, and finally
 * the right subtree recursively.
 *
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * Note: The provided function must accept an integer parameter representing
 * the value stored in each node. If the function pointer is NULL,
 * this function does nothing.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
