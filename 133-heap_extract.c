#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);
void switch_nodes(binary_tree_t **root,
				  binary_tree_t *first, binary_tree_t *second);
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
	int i = 31, tree_size = binary_tree_size(new_root);

	if (!new_root)
		return (0);
	if (!new_root->left && !new_root->right)
	{
		i = new_root->n, free(new_root), *root = NULL;
		return (i);
	}
	while (!(tree_size >> i--) & 1)
		;
	while (i)
		if ((tree_size >> i--) & 1)
			new_root = new_root->right;
		else
			new_root = new_root->left;
	if (tree_size > 2)
	{
		if (tree_size & 1)
			new_root = new_root->right, new_root->parent->right = NULL;
		else
			new_root = new_root->left, new_root->parent->left = NULL;
	}
	else
	{
		if (tree_size & 1)
			new_root = new_root->right;
		else
			new_root = new_root->left;
	}
	new_root->parent = NULL;
	new_root->left = (*root)->left, new_root->right = (*root)->right;
	i = (*root)->n, free(*root), *root = new_root;
	if (tree_size == 2)
		new_root->left = new_root->right = NULL;
	while (tree_size > 2)
		if (new_root->left && new_root->left->n > new_root->n &&
			(!new_root->right || new_root->left->n > new_root->right->n))
			switch_nodes(root, new_root, new_root->left);
		else if (new_root->right && new_root->right->n > new_root->n)
			switch_nodes(root, new_root, new_root->right);
		else
			break;
	return (i);
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
