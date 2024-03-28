#include "binary_trees.h"

/**
 * heap_extract - Extracts the root value from a binary heap
 * @root: Pointer to a pointer to the root node of the binary heap
 *
 * This function extracts the root value from the binary heap rooted
 * at the specified node.
 * It removes the root node from the heap and rearranges the heap to maintain
 * the heap property
 * (parent node value is greater than or equal to its children).
 *
 * @root: Pointer to a pointer to the root node of the binary heap
 *
 * Return: The value of the extracted root node, or 0 if the heap is empty
 */
int heap_extract(heap_t **root)
{
	heap_t *new_root = *root;
	int i = 31, tree_size = binary_tree_size(*root);

	if (!new_root)
		return (0);
	while (!(tree_size >> i--) & 1)
		;
	while (i)
		if ((tree_size >> i--) & 1)
			new_root = new_root->right;
		else
			new_root = new_root->left;
	if (tree_size & 1)
		new_root = new_root->right, new_root->parent->right = NULL;
	else
		new_root = new_root->left, new_root->parent->left = NULL;
	new_root->parent = NULL;
	new_root->left = (*root)->left, new_root->right = (*root)->right;
	i = (*root)->n, free(*root), *root = new_root;
	while (new_root)
		if (new_root->left && new_root->left->n > new_root->n &&
			new_root->left->n > new_root->right->n)
			switch_nodes(root, new_root, new_root->left);
		else if (new_root->right && new_root->right->n > new_root->n)
			switch_nodes(root, new_root, new_root->right);
		else
			break;
	return (i);
}

/**
 * binary_tree_node - Creates a new binary tree node
 * @parent: Pointer to the parent node of the new node
 * @value: Value to be stored in the new node
 *
 * This function creates a new binary tree node with the given value
 * and sets its parent pointer to the provided parent node.
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (!newNode)
		return (NULL);
	newNode->n = value;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = parent;
	return (newNode);
}
