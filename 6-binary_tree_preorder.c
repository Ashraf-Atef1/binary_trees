#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs a pre-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * This function performs a pre-order traversal
 * on the binary tree rooted at the
 * specified node, applying the given function to each node visited.
 * Pre-order traversal visits the current node first, then recursively visits
 * the left subtree, and finally recursively visits the right subtree.
 *
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * Note: The provided function must accept an integer parameter representing
 * the value stored in each node.
 * If the function pointer is NULL, this function
 * does nothing.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
