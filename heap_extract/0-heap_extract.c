#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of the binary tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_down - Moves the node down the heap to its correct position
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;
	int temp;

	if (left != NULL && left->n > largest->n)
		largest = left;
	if (right != NULL && right->n > largest->n)
		largest = right;
	if (largest != root)
	{
		temp = root->n;
		root->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - get the last node in heap_min
 * @root: head of the heap tree
 * Return: last node in heap_min
 */
binary_tree_t *get_last_node(heap_t *root)
{
	int nodes = 0, size_heap = 0;
	binary_tree_t *last_node = NULL;

	size_heap = binary_tree_size(root);

	for (nodes = 1; nodes <= size_heap; nodes <<= 1)
		;
	nodes >>= 2;

	for (last_node = root; nodes > 0; nodes >>= 1)
	{
		if (size_heap & nodes)
			last_node = last_node->right;
		else
			last_node = last_node->left;
	}

	return (last_node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *last, *tmp;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	value = (*root)->n;
	if (binary_tree_size(*root) == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(*root);
	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;
	}
	tmp = *root;
	*root = last;
	(*root)->left = tmp->left;
	(*root)->right = tmp->right;
	if ((*root)->left)
		(*root)->left->parent = *root;
	if ((*root)->right)
		(*root)->right->parent = *root;

	free(tmp);
	heapify_down(*root);

	return (value);
}
