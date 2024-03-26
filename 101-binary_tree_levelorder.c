#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
/**
 * binary_tree_levelorder - Performs a level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * This function performs a level-order traversal on the binary tree
 * rooted at the specified node, applying the given function to each node
 * visited. Level-order traversal visits the nodes level by level,
 * from left to right.
 *
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to the function to be called for each node
 *
 * Note: The provided function must accept an integer parameter representing
 * the value stored in each node. If the function pointer is NULL,
 * this function does nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **nodes_queue =
					  malloc(sizeof(binary_tree_t *) * binary_tree_size(tree)),
				  *tmp_node;
	int i = 0, j = 0;

	if (!tree || !func || !nodes_queue)
	{
		free(nodes_queue);
		return;
	}
	nodes_queue[i++] = (binary_tree_t *)tree;
	while (i)
	{
		tmp_node = nodes_queue[j];
		func(tmp_node->n);
		if (tmp_node->left)
			nodes_queue[j + i++] = tmp_node->left;
		if (tmp_node->right)
			nodes_queue[j + i++] = tmp_node->right;
		i--, j++;
	}
	free(nodes_queue);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * This function measures the size of the binary tree
 * rooted at the specified node.
 * The size of a binary tree is defined as
 * the total number of nodes in the tree.
 * The size of an empty tree is 0.
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
