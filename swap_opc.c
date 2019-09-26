#include "monty.h"

/**
 * swap_opc - Swap the two top element of stack
 * @stack: Doubly linked list
 * @line_number: Line's number
 * Return: Nothing
 */

void swap_opc(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp1, *tmp2;
	int i = 0, count = 0, num1 = 0, num2 = 0;
	(void)line_number;

	tmp1 = *stack;
	tmp2 = *stack;

	while (tmp1->next)
	{
		count++;
		tmp1 = tmp1->next;
	};
	while ((i + 1) < count)
	{
		i++;
		tmp2 = tmp2->next;
	};
	num1 = tmp1->n;
	num2 = tmp2->n;
	tmp1->n = num2;
	tmp2->n = num1;
}
