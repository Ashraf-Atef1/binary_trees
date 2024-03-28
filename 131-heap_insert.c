#include "binary_trees.h"

heap_t *find_parent(heap_t *root);
size_t binary_tree_size(const binary_tree_t *tree);
void heapify_up(heap_t **root, heap_t *node);
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
	heap_t *parent = *root;
	int i = 31, tree_size = binary_tree_size(*root) + 1;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	/* Find the parent to insert the new node */
	while (!(tree_size >> i--) & 1)
		;
	while (i)
		if ((tree_size >> i--) & 1)
			parent = parent->right;
		else
			parent = parent->left;

	/* Create the new node */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	/* Connect the new node to the parent */
	if (tree_size & 1)
		parent->right = new_node;
	else
		parent->left = new_node;
	/* Heapify */
	heapify_up(root, new_node);

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
	heap_t *partent = root;
	int i = 31, tree_size = binary_tree_size(root) + 1;

	while ((tree_size >> i--) & 1)
		;
	while (root)
	{
		partent = root;
		if ((tree_size >> i) & 1)
			root = root->right;
		else
			root = root->left;
	}
	return (partent);
}
/**
 * switch_nodes - Switches two nodes in a binary tree
 * @root: Pointer to the root node of the binary tree
 * @first: Pointer to the first node to switch
 * @second: Pointer to the second node to switch
 */
void switch_nodes(binary_tree_t **root,
				  binary_tree_t *first, binary_tree_t *second)
{
	binary_tree_t tmp_node = {0, NULL, NULL, NULL};

	if (root == NULL || *root == NULL || first == NULL || second == NULL)
		return;
	tmp_node.n = first->n, tmp_node.parent = first->parent;
	tmp_node.left = first->left, tmp_node.right = first->right;
	first->parent = second, first->left = second->left;
	first->right = second->right;
	if (second->left)
		second->left->parent = first;
	if (second->right)
		second->right->parent = first;
	second->parent = tmp_node.parent;
	if (tmp_node.parent)
	{
		if (first == tmp_node.parent->left)
			tmp_node.parent->left = second;
		else
			tmp_node.parent->right = second;
	}
	if (second == tmp_node.left)
	{
		second->left = first, second->right = tmp_node.right;
		if (tmp_node.right)
			tmp_node.right->parent = second;
	}
	else if (second == tmp_node.right)
	{
		second->right = first, second->left = tmp_node.left;
		if (tmp_node.left)
			tmp_node.left->parent = second;
	}
	while (second->parent)
		second = second->parent;
	*root = second;
}

/**
 * heapify_up - Maintain the Max Heap property by swapping
 * the newlyinserted node upwards
 * @root: Pointer to the root node of the binary tree
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t **root, heap_t *node)
{
	/* Traverse up the tree until the node satisfies the max heap property */
	while (node->parent != NULL && node->n > node->parent->n)
		switch_nodes(root, node->parent, node);
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
