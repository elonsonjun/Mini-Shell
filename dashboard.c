// dashboard.c
#include "shell.h"

static time_t session_start;

__attribute__((constructor))  // Automatically run when program starts
void start_timer() {
    session_start = time(NULL);
}

void print_dashboard() {
    time_t now = time(NULL);
    double duration = difftime(now, session_start);

    printf("\n🔍 \033[1;34mSession Stats\033[0m\n");
    printf("----------------------\n");
    printf("🕐 Time Active: %.0f seconds\n", duration);
    printf("💬 Commands Entered: %d\n", command_count);
    printf("📜 History Entries: %d\n", command_count < 100 ? command_count : 100);
    printf("----------------------\n\n");
}
