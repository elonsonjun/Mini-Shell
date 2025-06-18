// history.c
#include "shell.h"

#define MAX_HISTORY 100
static char *history[MAX_HISTORY];
static int history_count = 0;

void load_history() {
    FILE *file = fopen(HISTORY_FILE, "r");
    if (!file) return;

    char line[MAX_INPUT];
    while (fgets(line, sizeof(line), file) && history_count < MAX_HISTORY) {
        line[strcspn(line, "\n")] = 0;
        history[history_count++] = strdup(line);
    }

    fclose(file);
}

void save_history(const char *cmd) {
    FILE *file = fopen(HISTORY_FILE, "a");
    if (file) {
        fprintf(file, "%s\n", cmd);
        fclose(file);
    }

    if (history_count < MAX_HISTORY) {
        history[history_count++] = strdup(cmd);
    }
}

void print_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d: %s\n", i + 1, history[i]);
    }
}
