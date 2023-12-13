#include "main.h"

/**
 * main  - main entry
 * @argc: number of arguments
 * @argv: arguments
 *
 * Return: 0 Always
 */

int main(int argc, char *argv[])
{
	char *buffer = NULL;
	int i;

	if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
		execute_command(argv[i]);
		}
	} else
	{
		while (1)
		{
			write(STDOUT_FILENO, PROMPT, strlen(PROMPT));

			buffer = custom_getline();

			if (buffer == NULL)
			{
				printf("\n");
				break;
			}

			if (buffer[0] != '\0')
			{
				execute_command(buffer);
			}

			free(buffer);
		}
	}
	return (0);
}
