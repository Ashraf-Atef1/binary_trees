#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * This function finds the lowest common ancestor (LCA)
 * of the two specified nodes
 * in a binary tree. The lowest common ancestor is
 * the lowest (i.e., deepest) node
 * in the tree that has both the specified nodes as descendants.
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor of the two nodes,
 * or NULL if either of the nodes is NULL or they are not in the same tree
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	int first_depth = binary_tree_depth(first);
	int second_depth = binary_tree_depth(second);
	int i = second_depth - first_depth;
	binary_tree_t *first_node = (binary_tree_t *)first,
				  *second_node = (binary_tree_t *)second;

	if (!first_depth || !second_depth)
		return (NULL);
	if (first_depth > second_depth)
		first_node = (binary_tree_t *)second,
		second_node = (binary_tree_t *)first,
		i = first_depth - second_depth;

	while (i)
		second_node = second_node->parent, i--;
	while (first_node != second_node)
		first_node = first_node->parent,
		second_node = second_node->parent;
	return (first_node);
}

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
