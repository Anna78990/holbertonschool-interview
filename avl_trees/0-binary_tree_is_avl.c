#include "binary_trees.h"
#include <stdio.h>

/**
 * is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root
 * @min: minimum value
 * @max: maximum value
 * @height: height of this tree
 * Return: return 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0, abs = 0;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!is_avl(tree->left, min, tree->n, &h1) ||
		!is_avl(tree->right, tree->n, max, &h2))
		return (0);
	if (h1 > h2)
		*height = h1 + 1;
	else
		*height = h2 + 1;
	abs = h1 - h2;
	if (abs < 0)
		abs *= -1;
	if (abs <= 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to root node
 * Return: 1 if AVL else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX, &height));
}
