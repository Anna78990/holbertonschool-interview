#include "search.h"

/**
 * last_index - search last index
 * @list: list to search
 * Return: the last index
 */
size_t last_index(skiplist_t *list)
{
	skiplist_t *tmp = list;

	while (tmp->next)
		tmp = tmp->next;
	return (tmp->index);
}


/**
 * linear_skip - Searches for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer to the first node
 *         where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *expr;

	if (list == NULL)
		return (NULL);

	expr = list;
	while (expr->express != NULL && expr->n < value)
	{
		prev = expr;
		expr = expr->express;
		printf("Value checked at index [%lu] = [%d]\n", expr->index, expr->n);
	}

	if (expr->n >= value)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, expr->index);
		expr = prev;
	}
	else
	{
		printf("Value found between indexes [%lu] and [%ld]\n",
			expr->index, last_index(list));
	}
	while (expr != NULL && expr->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", expr->index, expr->n);
		if (expr->n == value)
			return (expr);
		expr = expr->next;
	}

	return (NULL);
}
