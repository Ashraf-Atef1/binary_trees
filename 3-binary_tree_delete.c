#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 *
 * This function deletes an entire binary tree rooted at the specified node.
 * It recursively deletes all nodes in the left and right subtrees before
 * freeing the memory allocated for the current node.
 *
 * Note: This function assumes that memory for the tree nodes
 * has been allocated dynamically using malloc(), and does not handle
 * any nodes allocated on the stack.
 * Calling this function on a non-dynamically allocated node may
 * lead to undefined behavior.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left), binary_tree_delete(tree->right);
	free(tree);
}
