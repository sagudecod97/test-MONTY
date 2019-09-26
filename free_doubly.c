#include "monty.h"

/**
 * free_dlistint - free all the linked list
 * @head: Head pointer
 *
 * Return: Nothing.
 */

void free_doubly(dlistint_t *head)
{
	dlistint_t *next_node = head;
	dlistint_t *current_node = head;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
