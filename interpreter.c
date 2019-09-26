#include "monty.h"

data_t data = {NULL, NULL, NULL, NULL};

/**
 * interpreter - inteprete and process each line of a Monty byte code
 * @file: Path to the file
 *
 * Return: Nothing
 */

void interpreter(char *file)
{
	size_t size = 100;
	unsigned int line_number = 0;

	data.fp = fopen(file, "r");
	if (data.fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	};

	while (getline(&data.buffer, &size, data.fp) != -1)
	{
		line_number++;
		data.tokens = tokenizer(data.buffer);
		if (data.tokens[0] == NULL)
		{
			free_all(0);
			continue;
		};
		execute(line_number);
		free_all(0);
	};
	free_all(1);
}
