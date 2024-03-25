#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new node as
 * the right-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * This function inserts a new node with the given value as the right-child
 * of the specified parent node. If the parent already has a right-child,
 * the new node is inserted and the existing
 * right-child becomes the right-child
 * of the new node.
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (!parent)
		return (NULL);
	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = parent->right;
	newNode->parent = parent;
	if (parent->right)
		newNode->right->parent = newNode;
	parent->right = newNode;
	return (newNode);
}
