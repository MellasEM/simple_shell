#include "main.h"
/**
 * custom_getline - function
 * Return: line
 */

char *custom_getline(void)
{
static char buffer[BUFFER_SIZE];
static size_t buffer_index = 0;
static size_t chars_in_buffer = 0;
char *line = NULL;
size_t line_index = 0;
while (1)
{
if (buffer_index >= chars_in_buffer)
{
chars_in_buffer = read(STDIN_FILENO, buffer, BUFFER_SIZE);
if (chars_in_buffer <= 0)
{
break;
}
buffer_index = 0;
}
if (line == NULL)
{
line = (char *)malloc(BUFFER_SIZE);
if (line == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
}
while (buffer_index < chars_in_buffer)
{
char current_char = buffer[buffer_index++];
if (current_char == '\n')
{
if (line_index == 0)
{
free(line);
return NULL;
}
line[line_index] = '\0';
return line;
}
line[line_index++] = current_char;
if (line_index % BUFFER_SIZE == 0)
{
line = (char *)realloc(line, line_index + BUFFER_SIZE);
if (line == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
}
}
}
if (line != NULL)
{
line[line_index] = '\0';
}
return (line);
}
