#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to the head of the linked list
 * Return: 1 if the linked list is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *prev = NULL;
	listint_t *next, *second_half;
	int is_palindrome = 1;

	if (*head == NULL || (*head)->next == NULL)
		return (is_palindrome);
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev = slow;
		slow = slow->next;
	}
	if (fast != NULL)
		second_half = slow->next;
	else
		second_half = slow;
	prev->next = NULL;
	prev = NULL;
	while (second_half != NULL)
	{
		next = second_half->next;
		second_half->next = prev;
		prev = second_half;
		second_half = next;
	}
	second_half = prev;
	next = *head;
	while (second_half != NULL)
	{
		if (next->n != second_half->n)
		{
			is_palindrome = 0;
			break;
		}
		next = next->next;
		second_half = second_half->next;
	}
	prev = NULL;
	second_half = NULL;
	return (is_palindrome);
}
