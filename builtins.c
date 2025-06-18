// builtins.c
#include "shell.h"

int is_builtin(char *cmd) {
    return strcmp(cmd, "cd") == 0 ||
           strcmp(cmd, "exit") == 0 ||
           strcmp(cmd, "history") == 0 ||
           strcmp(cmd, "clear") == 0 ||
           strcmp(cmd, "stats") == 0 ||
           strcmp(cmd, "setenv") == 0 ||
           strcmp(cmd, "unsetenv") == 0 ||
           strcmp(cmd, "printenv") == 0;
}

int run_builtin(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "minishell: expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1]) != 0)
                perror("minishell");
        }
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting MiniShell. Goodbye!\n");
        exit(0);
    }

    if (strcmp(args[0], "history") == 0) {
        print_history();
        return 1;
    }

    if (strcmp(args[0], "clear") == 0) {
        printf("\033[H\033[J");
        return 1;
    }

    if (strcmp(args[0], "stats") == 0) {
        print_dashboard();
        return 1;
    }

    if (strcmp(args[0], "setenv") == 0 && args[1] && args[2]) {
        set_env_var(args[1], args[2]);
        return 1;
    }

    if (strcmp(args[0], "unsetenv") == 0 && args[1]) {
        unset_env_var(args[1]);
        return 1;
    }

    if (strcmp(args[0], "printenv") == 0) {
        print_env_vars();
        return 1;
    }

    return 0;
}
