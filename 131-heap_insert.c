#include "binary_trees.h"

heap_t *find_parent(heap_t *root);
size_t binary_tree_size(const binary_tree_t *tree);
void heapify_up(heap_t *node);
/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = NULL;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the parent to insert the new node */
	parent = (*root)->left || (*root)->right ? find_parent(*root) : (*root);
	/* Create the new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Connect the new node to the parent */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/* Heapify */
	heapify_up(new_node);

	return (new_node);
}

/**
 * find_parent - Find the parent to insert the new node
 * @root: Pointer to the root node of the Heap
 *
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root)
{
	heap_t *partent;
	int left_size,
		right_size;

	while (root)
	{
		partent = root,
		left_size = binary_tree_size(root->left),
		right_size = binary_tree_size(root->right);
		if (left_size - 1 <= right_size && right_size % 2)
			root = root->left;
		else
			root = root->right;
	}
	return (partent);
}

/**
 * heapify_up - Maintain the Max Heap property by swapping
 * the newlyinserted node upwards
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
	int temp;

	/* Traverse up the tree until the node satisfies the max heap property */
	while (node->parent != NULL && node->n > node->parent->n)
	{
		/* Swap the values */
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;

		/* Move to the parent node */
		node = node->parent;
	}
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
