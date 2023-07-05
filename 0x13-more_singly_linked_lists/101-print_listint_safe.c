#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t nodes = 0;

	if (head == NULL)
		return (nodes);

	tortoise = head;
	hare = head;

	do {
		if (hare == NULL || hare->next == NULL)
			return (0);

		tortoise = tortoise->next;
		hare = hare->next->next;
	} while (tortoise != hare);

	tortoise = head;
	while (tortoise != hare)
	{
		tortoise = tortoise->next;
		hare = hare->next;
		nodes++;
	}

	hare = hare->next;
	while (tortoise != hare)
	{
		hare = hare->next;
		nodes++;
	}

	return (nodes);
}

size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;

	nodes = looped_listint_len(head);

	while (head != NULL && nodes > 0)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nodes--;
	}

	return (nodes);
}

