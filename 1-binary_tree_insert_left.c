#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a new node as
 * the left-child of another node
 * @parent: Pointer to the parent node
 * @value: Value to store in the new node
 *
 * This function inserts a new node with the given value as the left-child
 * of the specified parent node. If the parent already has a left-child,
 * the new node is inserted and the existing left-child becomes the left-child
 * of the new node.
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode;

	if (!parent)
		return (NULL);
	newNode = malloc(sizeof(binary_tree_t));
	if (!newNode)
		return (NULL);
	newNode->n = value;
	newNode->left = parent->left;
	newNode->right = NULL;
	newNode->parent = parent;
	if (parent->left)
		newNode->left->parent = newNode;
	parent->left = newNode;
	return (newNode);
}
