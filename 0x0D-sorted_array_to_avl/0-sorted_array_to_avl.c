#include "binary_trees.h"

int find_idx(int *array, size_t size)
{
	if ((int)size % 2 == 1)
		return ((int)size / 2);
	else if ((int)size % 2 == 0)
		return (((int)size / 2) - 1);

}

int find_height(size_t size)
{
	int ctr = 0;

	while ((int)size /= 2)
		ctr++; 
}



avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *node, *swp;
	int mid, i;

	if (array == NULL)
		return (NULL);
	mid = find_idx(array, size);
	node = (avl_t*)malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	node->n = array[mid];
	node->parent = NULL;

	for (i = 0; array[i]; i++)
	{
		while (node != NULL)
		{
			if (array[i] < node->n)
				node = node->right;
			else
				node = node->left;
		}

	}
}
