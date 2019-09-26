#include "monty.h"
#define DELIMITER " \t\n"

/**
 * _strcpy - Copies a string to another
 * @dest: Destination str
 * @src: Source str
 * Return: The destination str
 */

char *_strcpy(char *dest, char *src)
{
	int n = 0, j = 0;

	while (*(src + n) != '\0')
	{
		n++;
	};

	while (j <= n)
	{
		dest[j] = *(src + j);
		j++;
	}

	return (dest);
}

/**
 * _strLen - Return the length of a string
 * @str: String
 * Return: Length
 */

int _strLen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	};

	return (i);
}

/**
 * _strtok - Return an array of tokens
 * @buff: String
 * Return: An array
 */

char **_strtok(char *buff)
{
	int i = 0, sizeCopy = 0, tokCuantity = 0;
	char *token = NULL, **arr_TOK = NULL, *copy = NULL;

	sizeCopy = _strLen(buff);
	copy = malloc(sizeof(char) * (sizeCopy + 1));

	if (copy == NULL)
	{
		free(copy);
		perror("Error: ");
	};

	copy = _strcpy(copy, buff);
	token = strtok(copy, DELIMITER);

	while (token)
	{
		tokCuantity++;
		token = strtok(NULL, DELIMITER);
	};
	free(copy);

	arr_TOK = (char **)malloc(sizeof(char *) * (tokCuantity + 1));
	token = strtok(buff, DELIMITER);

	while (token)
	{
		arr_TOK[i] = malloc(sizeof(char) * (_strLen(token) + 1));
		_strcpy(arr_TOK[i], token);
		token = strtok(NULL, DELIMITER);
		i++;
	};

	arr_TOK[i] = NULL;

	return (arr_TOK);

}
