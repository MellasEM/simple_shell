#include "main.h"

void execute_command(char *command)
{
pid_t pid;
int status;
char *path = getenv("PATH");
if (path == NULL)
{
perror("getenv");
_exit(EXIT_FAILURE);
}
char *token, *args[50];
int i = 0;
token = custom_strtok(command, " ");
while (token != NULL && i < 49)
{
if (token[0] == '\'' || token[0] == '"')
{
char *end_quote = strchr(token + 1, token[0]);
if (end_quote != NULL)
{
token++;
end_quote[0] = '\0';
}
}
args[i++] = token;
token = custom_strtok(NULL, " ");
}
args[i] = NULL;
if (strcmp(args[0], "cd") == 0)
{
if (args[1] != NULL)
{
if (chdir(args[1]) == -1)
{
perror("shell");
}
}
else
{
fprintf(stderr, "shell: cd: missing argument\n");
}
return;
}
pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("shell");
_exit(EXIT_FAILURE);
}
}
else if (pid < 0)
{
perror("shell");
}
else
{
waitpid(pid, &status, WUNTRACED);
}
}
