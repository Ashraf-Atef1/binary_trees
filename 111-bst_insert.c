#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a binary search tree (BST)
 * @tree: Pointer to a pointer to the root node of the BST
 * @value: Value to insert into the BST
 *
 * This function inserts a new node with the given value into the binary search
 * tree (BST) pointed to by the specified pointer to the root node.
 * If a node with the same value already exists in the BST,
 * the insertion is not performed.
 *
 * @tree: Pointer to a pointer to the root node of the BST
 * @value: Value to insert into the BST
 *
 * Return: Pointer to the newly inserted node, or NULL if the insertion fails
 */
bst_t *bst_insert(bst_t **tree, int value)
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
	return (new_node);
}
