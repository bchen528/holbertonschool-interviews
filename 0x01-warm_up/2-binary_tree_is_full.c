#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to root node
 * Return: 0 or 1 for if the tree is full or not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	/* reached the leaves */
	if (!tree->left && !tree->right)
		return (1);

	/* middle nodes must have 2 children */
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));
	return (0);
}
