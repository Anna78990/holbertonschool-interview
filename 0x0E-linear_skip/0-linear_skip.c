#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: Value to search for.
 *
 * Return: Pointer to the node where value is located,
 *		 or NULL if value is not present in list or if head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *prev;

	if (list == NULL)
		return (NULL);

	node = list;
	while (node)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);

		if (node->express == NULL || node->express->n >= value)
		{
			if (node->express == NULL && node->n < value)
			{
				prev = node;
				while (node->next)
					node = node->next;
				printf("Value found between indexes [%lu] and [%lu]\n",
					   prev->index, node->index);
			}
			else
			{
				printf("Value found between indexes [%lu] and [%lu]\n",
					   prev->index, node->index);
			}

			while (prev && prev->index <= node->index)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				prev = prev->next;
			}
			break;
		}
		prev = node;
		node = node->express;
	}
	return (NULL);
}
