#include "main.h"

char *custom_strtok(char *str, const char *delimiters) {
    static char *lastToken = NULL;
    char *token;

    if (str != NULL) {
        lastToken = str;
    }

    while (*lastToken != '\0' && strchr(delimiters, *lastToken) != NULL) {
        lastToken++;
    }

    if (*lastToken == '\0') {
        return NULL;
    }

    token = lastToken;

    while (*lastToken != '\0' && strchr(delimiters, *lastToken) == NULL) {
        lastToken++;
    }

    if (*lastToken != '\0') {
        *lastToken = '\0';
        lastToken++;
    }

    return token;
}
