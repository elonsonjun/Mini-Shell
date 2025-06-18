// utils.c
#include "shell.h"

void print_prompt() {
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("\033[1;36mMiniShell\033[0m:\033[1;32m%s\033[0m$ ", cwd);
    fflush(stdout);
}

void set_env_var(char *name, char *value) {
    if (setenv(name, value, 1) != 0) {
        perror("minishell (setenv)");
    }
}

void unset_env_var(char *name) {
    if (unsetenv(name) != 0) {
        perror("minishell (unsetenv)");
    }
}

void print_env_vars() {
    extern char **environ;
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}
