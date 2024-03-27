#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary search tree (BST)
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for in the BST
 *
 * This function searches for the specified value in
 * the binary search tree (BST) rooted at the specified node.
 * It performs a binary search starting from the root node and
 * traverses the tree according to the BST property.
 *
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for in the BST
 *
 * Return: Pointer to the node containing the value if found, or NULL if the
 *         value is not present in the BST or if the tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current_node = (bst_t *)tree;

	while (current_node)
	{
		if (current_node->n > value)
			current_node = current_node->left;
		else if (current_node->n < value)
			current_node = current_node->right;
		else
			return (current_node);
	}
	return (current_node);
}
