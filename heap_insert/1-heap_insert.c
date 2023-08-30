#include "binary_trees.h"

/**
 * count_nodes - count the number of nodes
 * @tree: pointer to the root node of the tree
 * to count the number of the node
 * Return: number of the nodes
 */

int count_nodes(const binary_tree_t *tree)
{
	int size = 0;

	if (tree == NULL)
		return (0);

	size++;
	size += count_nodes(tree->left);
	size += count_nodes(tree->right);

	return (size);
}


/**
 * swap - swap the values of nodes
 * @parent : value of element
 * @value : value of element
 */
void swap(int *parent, int *value)
{
	int tmp;

	tmp = *value;
	*value = *parent;
	*parent = tmp;
}


/**
 * find_parent - find the parent, assingning indexes into each nodes
 * @tree : tree to search
 * @idx : index of the tree
 * @n : number of the node
 *
 * Return: the parent of the node to insert
 */
heap_t *find_parent(heap_t *tree, int idx, int n)
{
	heap_t *left, *right;

	if (idx == n)
		return (tree);

	if (idx > n)
		return (NULL);

	left = find_parent(tree->left, 2 * idx + 1, n);
	right = find_parent(tree->right, 2 * idx + 2, n);

	if (left)
		return (left);
	else if (right)
		return (right);
	else
		return (NULL);

}

/**
 * insert_node - insert the node under the parent node
 * @tree : tree into insert the node
 * @new : node to insert
 *
 * Return: tree
*/
heap_t *insert_node(heap_t *tree, heap_t *new)
{
	int size = count_nodes(tree);
	heap_t *parent = find_parent(tree, 0, ((size - 1) / 2));

	if (!parent->left)
		parent->left = new;
	else
		parent->right = new;

	return (parent);

}

/**
 * heap_insert - inserts a value into a max binary heap
 * @root : double pointer to the root node of the Heap
 * @value : value to insert
 *
 * Return: pointer to the inserted node or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = binary_tree_node(NULL, value);
	heap_t *parent;

	if (!root)
		return (NULL);
	if (!(*root))
	{
		*root = new;
		return (new);
	}
	parent = insert_node(*root, new);
	new->parent = parent;

	while (new->parent && new->n > new->parent->n)
	{
		swap(&new->parent->n, &new->n);
		new = new->parent;
	}
	return (new);
}
