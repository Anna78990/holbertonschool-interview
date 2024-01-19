#include "binary_trees.h"
#include <stdio.h>

/**
 * _size - gets size of tree
 * @node: pointer to root
 * Return: size of tree
 */
int _size(heap_t *node)
{
	if (node == NULL)
		return (0);
	else
		return (_size(node->left) + 1 + _size(node->right));
}


/**
 * heapify_down - swap the number of node in the correct order
 * @heap: pointer to heap
 */
void heapify_down(heap_t *heap)
{
	heap_t *node = heap, *child;
	int temp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
		{
			if (node->left->n > node->right->n)
				child = node->left;
			else
				child = node->right;
		}
		if (node->n > child->n)
			break;
		temp = node->n;
		node->n = child->n;
		child->n = temp;
		node = child;
	}
}

/**
 * heap_extract - extracts top node from binary tree
 * @heap: pointer to heap
 * Return: node n value
 */
int heap_extract(heap_t **heap)
{
	int n, size, bit;
	heap_t *node, *root;

	if (!heap || !*heap)
		return (0);
	root = *heap;
	n = root->n;
	size = _size(root);
	if (size == 1)
	{
		free(root);
		*heap = NULL;
		return (n);
	}
	for (bit = 1; bit <= size; bit <<= 1)
		;
	for (node = root, bit >>= 2; bit > 0; bit >>= 1)
	{
		if (size & bit)
			node = node->right;
		else
			node = node->left;
	}
	root->n = node->n;
	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;
	free(node);
	heapify_down(root);
	*heap = root;
	return (n);
}
