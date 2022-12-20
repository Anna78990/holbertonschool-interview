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
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return (new);
	}
	while (curr->next)
	{
		if (curr->n > number)
		{
			if (curr == *head)
			{
				new->next = curr;
				*head = new;
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
	curr->next = new;
	new->next = NULL;
	return (new);
}
