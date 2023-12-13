#include "main.h"

/**
 * custom_strtok - strtok function
 * @str: string to split
 * @delimiters: pointer
 *
 * Return: token
 */

char *custom_strtok(char *str, const char *delimiters)
{
	static char *lastToken;
	char *token;

	lastToken = NULL;

	if (str != NULL)
	{
		lastToken = str;
	}

	while (*lastToken != '\0' && strchr(delimiters, *lastToken) != NULL)
	{
		lastToken++;
	}

	if (*lastToken == '\0')
	{
		return (NULL);
	}

	token = lastToken;

	while (*lastToken != '\0' && strchr(delimiters, *lastToken) == NULL)
	{
		lastToken++;
	}

	if (*lastToken != '\0')
	{
		*lastToken = '\0';
		lastToken++;
	}

	return (token);
}
