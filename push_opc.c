#include "monty.h"

/**
 * push_opc - Push an element into a linked list
 * @stack: Doubly linked list
 * @value: Value to be pushed into a linked list
 * @line_number: Number of line
 *
 * Return: Nothing
 */

void push_opc(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new;
	stack_t *tmp = *stack;
	(void)line_number;

	new = (stack_t *) malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = value;

	if (*stack == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*stack = new;
	}

	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;

		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;

	}
}
