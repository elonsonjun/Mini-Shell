// signals.c
#include "shell.h"

void handle_sigint(int sig) {
    (void)sig; // Unused
    printf("\n🚫 Interrupt caught (Ctrl+C). Type 'exit' to quit.\n");
    print_prompt();
    fflush(stdout);
}

void handle_sigtstp(int sig) {
    (void)sig; // Unused
    printf("\n⏸️  Suspend blocked (Ctrl+Z is disabled).\n");
    print_prompt();
    fflush(stdout);
}
