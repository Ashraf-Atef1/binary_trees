#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
binary_tree_t *check_balance(binary_tree_t *node, binary_tree_t *root);
avl_t *avl_insert(avl_t **tree, int value)
{
	bst_t *new_node = binary_tree_node(NULL, value), *current_node = *tree;

	if (current_node)
	{
		while (current_node)
		{
			if (value == current_node->n)
				free(new_node), new_node = current_node = NULL;
			else if (value < current_node->n && current_node->left)
				current_node = current_node->left;
			else if (value > current_node->n && current_node->right)
				current_node = current_node->right;
			else
			{
				if (value < current_node->n)
					current_node->left = new_node;
				else
					current_node->right = new_node;
				new_node->parent = current_node;
				break;
			}
		}
	}
	else
		*tree = new_node;

	check_balance(new_node, *tree);
	return (new_node);
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
/**
 * node_is_complete - Checks if a node has both left and right children
 * @node: Pointer to the node to be checked
 *
 * This function checks whether the specified node has both
 * left and right children.
 * If both children are present, the function returns 1;
 * otherwise, it returns 0.
 *
 * @node: Pointer to the node to be checked
 *
 * Return: 1 if the node has both left and right children, 0 otherwise or if
 *         the node is NULL
 */
int node_is_complete(const binary_tree_t *node)
{
	if (node && node->left && node->right)
		return (1);
	return (0);
}
int check_balance_helper(const binary_tree_t *node)
{
	if (!node || !node->parent ||
		!node->parent->parent ||
		!node->parent->parent->parent ||
		node_is_complete(node->parent) ||
		node_is_complete(node->parent->parent))
		return (1);
	return (0);
}
void swap_nodes(binary_tree_t *first, binary_tree_t *second)
{
	binary_tree_t *tmp;

	if (!first || !second)
		return;
	second->parent = first->parent;
	first->parent = second;
	if (second->parent && second->parent->left == first)
		second->parent->left = second;
	if (second->parent && second->parent->right == first)
		second->parent->right = second;
	if (first->left == second)
		first->left = second->right,
		second->right = first,
		tmp = first->right,
		first->right = second->left,
		second->left = tmp;
	if (first->right == second)
		first->right = second->left,
		second->left = first,
		tmp = first->left,
		first->left = second->right,
		second->right = tmp;
	if (first->left)
		first->left->parent = first;
	if (first->right)
		first->right->parent = first;
	if (second->left)
		second->left->parent = second;
	if (second->right)
		second->right->parent = second;
}
binary_tree_t *check_balance(binary_tree_t *node, binary_tree_t *root)
{
	binary_tree_t *parent, *grand_parent;

	if (check_balance_helper(node))
		return (root);
	parent = node->parent, grand_parent = node->parent->parent;
	if (parent->left && parent->right)
		return (root);
	if (parent->left && grand_parent->left == parent)
		grand_parent->parent = binary_tree_rotate_right(grand_parent);
	else if (parent->right && grand_parent->right == parent)
		grand_parent->parent = binary_tree_rotate_left(grand_parent);
	else if (parent->left && grand_parent->right == parent)
		swap_nodes(parent, node), root = binary_tree_rotate_left(grand_parent);
	else if (parent->right && grand_parent->left == parent)
		swap_nodes(parent, node), root = binary_tree_rotate_right(grand_parent);
	return (root);
}
// binary_tree_t *check_balance(binary_tree_t *node, binary_tree_t *root)
// {
// 	if (!node)
// 		return (root);
// 	check_balance(node->left, root);
// 	check_balance(node->right, root);
// 	return (fix_balance(node, root));
// }
