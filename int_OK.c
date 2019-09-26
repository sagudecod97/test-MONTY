#include "monty.h"

/**
 * int_OK - Verifies if a string is a number
 * @value: String to test
 * Return: 0 on Success, -1 on Failure
 */
int int_OK(char *value)
{
	int i = 0;

	if (value == NULL)
		return (-1);

	if (value[0] == '-')
		i++;

	for (; *(value + i) != '\0'; i++)
	{
		if (isdigit(value[i]) == 0)
		{
			return (-1);
		}
	};
	return (0);
}
