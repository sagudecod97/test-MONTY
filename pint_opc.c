#include "monty.h"

/**
 * pint_opc - Prints the value at top of the stack
 * @stack: Doubly linked list
 * @line_number: Number's line
 * Return: Nothing
 */

void pint_opc(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	tmp = *stack;

	if (*stack == NULL)
	{
		printf("L<%i>: can't pint, stack empty", line_number);
	};

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	};

	printf("%i\n", tmp->n);
}
