#include "search.h"

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

	while (expr != NULL && expr->n <= value)
	{
		printf("Value checked at index [%lu] = [%d]\n", expr->index, expr->n);
		if (expr->n == value)
			return (expr);
		expr = expr->next;
	}

	return (NULL);
}
