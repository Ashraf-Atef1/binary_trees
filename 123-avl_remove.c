#include "binary_trees.h"

bst_t *bst_search(const bst_t *tree, int value);
int binary_tree_is_leaf(const binary_tree_t *node);
int node_is_complete(const binary_tree_t *node);
void change_parent(binary_tree_t *node, binary_tree_t *child);
bst_t *bst_remove(bst_t *root, int value);
void delete_balance(avl_t **tree);

/**
 * avl_remove - Removes a node with a specified value from an AVL tree
 * @root: Pointer to the root node of the AVL tree
 * @value: Value of the node to be removed
 *
 * This function removes a node with the specified value from
 * the AVL tree rooted at the specified node. It calls
 * the bst_remove() function to remove the node and
 * then calls the delete_balance() function to rebalance the tree if necessary.
 *
 * @root: Pointer to the root node of the AVL tree
 * @value: Value of the node to be removed
 *
 * Return: Pointer to the root node of the AVL tree after removal
 * and rebalancing, or NULL if the specified value is not present
 * in the AVL tree or if the tree becomes empty after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	root = (avl_t *)bst_remove((bst_t *)root, value);

	if (root == NULL)
		return (NULL);
	delete_balance(&root);
	return (root);
}

/**
 * delete_balance - Balances the AVL tree after node removal
 * @tree: Pointer to a pointer to the root node of the AVL tree
 *
 * This function balances the AVL tree rooted at the specified node
 * after a node has been removed from the tree. It recursively traverses
 * the tree and performs rotations if necessary to maintain the AVL property.
 *
 * @tree: Pointer to a pointer to the root node of the AVL tree
 */
void delete_balance(avl_t **tree)
{
	int bval;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	delete_balance(&(*tree)->left);
	delete_balance(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * bst_remove - Removes a node with a specified value from
 * a binary search tree (BST)
 * @root: Pointer to the root node of the BST
 * @value: Value of the node to be removed
 *
 * This function removes a node with the specified value from
 * the binary search tree (BST)
 * rooted at the specified node. If the node with the given value is found,
 * it is removed
 * from the tree and the tree structure is adjusted accordingly to maintain
 * the BST property.
 *
 * @root: Pointer to the root node of the BST
 * @value: Value of the node to be removed
 *
 * Return: Pointer to the root node of the resulting BST after removal,
 * or NULL if the specified value is not present in the BST
 * or if the tree is empty
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *delete_node = bst_search(root, value);

	if (!delete_node)
		return (root);
	if (binary_tree_is_leaf(delete_node))
	{
		root = delete_node->parent ? root : NULL;
		change_parent(delete_node, NULL);
		free(delete_node);
	}
	else if (node_is_complete(delete_node))
	{
		bst_t *replace_node = delete_node->right;

		while (replace_node->left)
			replace_node = replace_node->left;
		delete_node->n = replace_node->n;
		bst_remove(replace_node, replace_node->n);
	}
	else
	{
		if (delete_node->left)
			root = delete_node->parent ? root : delete_node->left,
			change_parent(delete_node, delete_node->left);
		else
			root = delete_node->parent ? root : delete_node->right,
			change_parent(delete_node, delete_node->right);
		free(delete_node);
	}

	return (root);
}

/**
 * bst_search - Searches for a value in a binary search tree (BST)
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for in the BST
 *
 * This function searches for the specified value in
 * the binary search tree (BST) rooted at the specified node.
 * It performs a binary search starting from the root node and
 * traverses the tree according to the BST property.
 *
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for in the BST
 *
 * Return: Pointer to the node containing the value if found, or NULL if the
 *         value is not present in the BST or if the tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree && tree->n > value)
		return (bst_search(tree->left, value));
	else if (tree && tree->n < value)
		return (bst_search(tree->right, value));
	else
		return ((bst_t *)tree);
}
/**
 * binary_tree_is_leaf - Checks if a node is a leaf in a binary tree
 * @node: Pointer to the node to check
 *
 * This function determines whether the specified
 * node is a leaf node in a binary tree.
 * A leaf node is defined as a node with no children
 * (neither left nor right child).
 *
 * @node: Pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise or if the node is NULL
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
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
/**
 * change_parent - Changes the parent of a node
 * @node: Pointer to the node whose parent is to be changed
 * @child: Pointer to the new parent node
 *
 * This function changes the parent of the specifiednode
 * to the given child node.
 * It updates the left or right child pointer of
 * the original parent node to point
 * to the new child node. If the specified node is NULL
 * or has no parent, or if the
 * new child node is NULL, no changes are made.
 *
 * @node: Pointer to the node whose parent is to be changed
 * @child: Pointer to the new parent node
 */
void change_parent(binary_tree_t *node, binary_tree_t *child)
{
	if (!node || !node->parent)
		return;
	else if (node->parent->left == node)
		node->parent->left = child;
	else if (node->parent->right == node)
		node->parent->right = child;
	if (child)
		child->parent = node->parent;
}
