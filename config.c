// config.c
#include "shell.h"

void load_config() {
    FILE *file = fopen(CONFIG_FILE, "r");
    if (!file) return;

    char line[MAX_INPUT];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        // Simple variable format: VAR=VALUE
        char *eq = strchr(line, '=');
        if (eq) {
            *eq = '\0';
            char *key = line;
            char *value = eq + 1;
            set_env_var(key, value);
        }
    }

    fclose(file);
}
