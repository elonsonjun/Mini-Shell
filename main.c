// main.c
#include "shell.h"

int command_count = 0;

int main() {
    char input[MAX_INPUT];
    char **args;

    signal(SIGINT, handle_sigint);
    signal(SIGTSTP, handle_sigtstp);

    load_history();
    load_config();

    while (1) {
        print_prompt();

        if (!fgets(input, MAX_INPUT, stdin)) break;
        input[strcspn(input, "\n")] = 0;

        if (strlen(input) == 0) continue;

        save_history(input);
        log_command(input);
        command_count++;

        args = parse_input(input);

        if (args[0] == NULL) continue;

        if (is_builtin(args[0])) {
            run_builtin(args);
        } else {
            handle_fantasy_command(args);
            execute_command(args);
        }

        free(args);
    }

    return 0;
}
