#include "binary_trees.h"

/**
 * fix_balance - Fixes the balance of an AVL tree after insertion
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value of the newly inserted node
 *
 * This function fixes the balance of the AVL tree rooted at the specified node
 * after inserting a new node with the given value.
 * It checks the balance factor of the tree and performs rotations
 * if necessary to maintain the AVL property.
 *
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value of the newly inserted node
 */
void fix_balance(avl_t **tree, int value)
{
	int bfactor = binary_tree_balance(*tree);

	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
}
/**
 * avl_insert - Inserts a value into an AVL tree
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value to insert into the AVL tree
 *
 * This function inserts a new node with the given value into the AVL tree
 * pointed to by the specified pointer to the root node. After insertion,
 * it fixes the balance of the tree using the fix_balance() function.
 *
 * @tree: Pointer to a pointer to the root node of the AVL tree
 * @value: Value to insert into the AVL tree
 *
 * Return: Pointer to the newly inserted node, or NULL if the insertion fails
 */
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
	while (current_node)
		fix_balance(current_node == *tree ? tree : &current_node, value),
			current_node = current_node->parent;
	return (new_node);
}
