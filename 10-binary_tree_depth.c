#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node for which depth is to be measured
 *
 * This function measures the depth of the specified node in the binary tree.
 * The depth of a node is defined as the length of the path from the root node
 * to the specified node. The depth of the root node is 0.
 *
 * @tree: Pointer to the node for which depth is to be measured
 *
 * Return: Depth of the specified node,
 * or 0 if the node is NULL or has no parent
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
