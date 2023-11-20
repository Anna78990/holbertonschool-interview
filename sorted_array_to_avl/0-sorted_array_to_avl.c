#include "binary_trees.h"


/**
 * create_node - create new node
 * @n: n of node
 * @parent: parent of a node
 *
 * Return: pointer to new node
 **/
avl_t *create_node(int n, avl_t *parent)
{
	avl_t *new;

	new = (avl_t *)malloc(sizeof(avl_t));

	if (!new)
		return (NULL);
	new->n = n;
	new->parent = parent;
	return (new);
}

/**
 * binary_recursion - create recursively the node child
 * @parent: pointer to the parent
 * @array: array to be tree
 * @left: the index to be the left part of the tree
 * @right: the index to be the right part of the tree
 *
 * Return: modified tree
 */
avl_t *binary_recursion(avl_t *parent, int *array, int left, int right)
{
	avl_t *new;
	int mid;

	if (left > right)
		return (NULL);
	mid = (left + right) / 2;
	new = create_node(array[mid], parent);
	if (!new)
		return (NULL);
	new->left = binary_recursion(new, array, left, mid - 1);
	new->right = binary_recursion(new, array, mid + 1, right);
	return (new);
}

/**
 * sorted_array_to_avl - create a binary tree by given array
 * @array: array
 * @size: size of array
 *
 * Return: pointer to root of tree
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (binary_recursion(NULL, array, 0, (int)size - 1));
}
