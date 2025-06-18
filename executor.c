// parser.c
#include "shell.h"

char **parse_input(char *input) {
    char **tokens = malloc(MAX_TOKENS * sizeof(char *));
    char *token;
    int position = 0;

    if (!tokens) {
        fprintf(stderr, "minishell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(input, " \t\r\n");
    while (token != NULL) {
        tokens[position++] = token;
        token = strtok(NULL, " \t\r\n");
    }
    tokens[position] = NULL;

    return tokens;
}
