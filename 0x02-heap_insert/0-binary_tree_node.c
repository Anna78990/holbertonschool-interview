#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - create a new branch
 * @parent: Pointer to the root of a branch
 * @value: the value of new branch
 * Return: pointer to a new node. if it failed, it return NULL
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *p;

	p = malloc(sizeof(binary_tree_t));
	if (p == NULL)
		return (NULL);
	p->n = value;
	p->parent = parent;
	p->left = NULL;
	p->right = NULL;
	if (parent == NULL)
		parent = p;
	if (value > parent->n)
		parent->right = p;
	else
		parent->left = p;

	return (p);
}
