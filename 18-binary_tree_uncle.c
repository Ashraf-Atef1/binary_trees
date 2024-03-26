#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node whose uncle is to be found
 *
 * This function finds the uncle of the specified node in the binary tree.
 * The uncle of a node is the sibling of its parent node.
 *
 * @node: Pointer to the node whose uncle is to be found
 *
 * Return: Pointer to the uncle node, or NULL if the specified node is NULL,
 *         the node has no parent, or the node's parent has no sibling
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	return (binary_tree_sibling(node ? node->parent : NULL));
}

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 * @node: Pointer to the node whose sibling is to be found
 *
 * This function finds the sibling of the specified node in the binary tree.
 * The sibling of a node is another node in
 * the tree that shares the same parent as the specified node.
 *
 * @node: Pointer to the node whose sibling is to be found
 *
 * Return: Pointer to the sibling node, or NULL if the specified node is NULL,
 *         the node has no parent, or the node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent = node ? node->parent : NULL;

	if (!parent)
		return (NULL);
	return (parent->left == node ? parent->right : parent->left);
}
