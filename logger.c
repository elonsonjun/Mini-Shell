// logger.c
#include "shell.h"

void log_command(const char *cmd) {
    FILE *log = fopen(LOG_FILE, "a");
    if (!log) return;

    time_t now = time(NULL);
    char *timestamp = ctime(&now);
    timestamp[strcspn(timestamp, "\n")] = 0; // Remove newline

    fprintf(log, "[%s] %s\n", timestamp, cmd);
    fclose(log);
}
