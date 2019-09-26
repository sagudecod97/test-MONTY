#include "monty.h"

/**
* free_all - custom memory handling function
* @all: flag to indicate what to free
*/

void free_all(int all)
{
	if (data.buffer)
	{
		free(data.buffer);
		data.buffer = NULL;
		free_everything(data.tokens);
		data.tokens = NULL;
	}
	if (all)
	{
		if (data.stack)
		{
			free_doubly(data.stack);
			data.stack = NULL;
		}
		if (data.fp)
		{
			fclose(data.fp);
			data.fp = NULL;
		}
	};

}

/**
* free_everything - frees arrays of strings
* @args: array of strings to free
*/

void free_everything(char **args)
{
	int i;

	if (!args)
		return;
	for (i = 0; args[i]; i++)
		free(args[i]);
		free(args);

}
