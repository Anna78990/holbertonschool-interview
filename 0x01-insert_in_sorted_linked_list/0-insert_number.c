#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert the node into a sorted singly linked list.
 * @head: pointer to a linked list
 * @number: the number of a new node
 * Return: NULL if it failed, otherwise new node address
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *prev = *head;
	listint_t *curr = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	while (curr->next)
	{
		if (curr->n > number)
		{
			if (curr == prev)
			{
				new->next = curr;
				return (new);
			}
			else
			{
				prev->next = new;
				new->next = curr;
				return (new);
			}
		}
		prev = curr;
		curr = curr->next;
	}
	prev->next = new;
	new->next = NULL;
	return (new);
}
