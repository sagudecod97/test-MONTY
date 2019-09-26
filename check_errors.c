#include "monty.h"

/**
 * check_errors - doubly linked list representation of a stack (or queue)
 * @fp: File descriptor
 * @buffer: Buffer from tokenizer
 * @token_1: First token
 * @token_2: Second token
 * @stack: Doubly linked list
 * @line_number: Line number
 *
 * Return: 0
 */

void check_errors(char *token_1, char *token_2, unsigned int line_number)
{
	char *opcodes[] = {"push", "pall", "pop", "pint", "swap", "add", "nop", NULL};
	int delete = 0, i = 0;

	(void)line_number;
	if (strcmp(token_1, "push") == 0)
	{
		if (int_OK(token_2) != 0 || token_2 == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			delete = 1;
		}
	};
	if (strcmp(token_1, "pall") == 0 && &(data.stack) == NULL)
	{
		delete = 1;
		return;
	};
	for (i = 0; i < 7; i++)
	{
		if (strcmp(token_1, opcodes[i]) == 0 && &(data.stack) == NULL &&
			strcmp(token_1, "push") != 0)
		{
			fprintf(stderr, "L%d: can't %s stack too short\n", line_number, opcodes[i]);
			delete = 1;
		};
	}
	if (delete == 1)
	{
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
