#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: new string to add in the node
 *
 * Return: the address of the new element, or NULL if it fails
 */

#include <stdlib.h>
#include <string.h>
#include "lists.h"

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;
	unsigned int len = 0;
	const char *temp = str;

	while (*temp)
	{
		len++;
		temp++;
	}

	new = (list_t *)malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = (char *)malloc((len + 1) * sizeof(char));
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

	strcpy(new->str, str);
	new->len = len;
	new->next = *head;
	*head = new;

	return (*head);
}

