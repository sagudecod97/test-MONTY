#include "monty.h"

/**
 * do_Functions - Find the functions of the opcodes to execute
 * @token: Opcode name
 * @int_token: Integer to push
 * @stack: Doubly linked list
 * @line_number: Number of line
 *
 * Return: 0 in success or -1 if error
 */

int do_Functions(char *token, int int_token, unsigned int line_number)
{
	int opc = 0;
	/* Add 1 to opc if functions are added*/
	instruction_t opcodes_Fun[] = {
	{"pall", pall_opc}, {"pint", pint_opc},
	{"pop", pop_opc}, {"swap", swap_opc},
	{"add", add_opc}, {"nop", nop_opc},
	{NULL, NULL}
	};
	if (strcmp(token, "push") == 0)
	{
		push_opc(&(data.stack), int_token, line_number);
		return (0);
	};

	for (opc = 0; opc < 6 ; opc++)
	{
		if (strcmp(opcodes_Fun[opc].opcode, token) == 0)
		{
			opcodes_Fun[opc].f(&(data.stack), line_number);
			return (0);
		};
	}

	if (opc <= 7)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, token);
		exit(EXIT_FAILURE);
	};

	return (-1);
}
