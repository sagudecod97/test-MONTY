#include "monty.h"

/**
 * tokenizer - Tokenize a string to an array pointer.
 * @value: Line wrote in console.
 * Return: An array with all words splittBed.
 */

char **tokenizer(char *value)
{
	char **tokens;

	tokens = _strtok(value);
	if (tokens == NULL)
	{
		perror("shell:, Error allocating the buffer");
		return (NULL);
	}

	return (tokens);
}
