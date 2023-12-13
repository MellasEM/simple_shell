#ifndef MAIN_H
		
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define PROMPT "$ "

char *custom_getline(void);
void execute_command(char *command);
char *custom_strtok(char *str, const char *delimiters);


#endif
