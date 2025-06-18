// shell.h
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>

#define MAX_INPUT 1024
#define MAX_TOKENS 100
#define HISTORY_FILE ".minihistory"
#define LOG_FILE ".minilog"
#define CONFIG_FILE ".minirc"

extern int command_count;

void print_prompt();
char **parse_input(char *input);
int execute_command(char **args);
int is_builtin(char *cmd);
int run_builtin(char **args);
void load_history();
void save_history(const char *cmd);
void print_history();
void handle_sigint(int sig);
void handle_sigtstp(int sig);
void log_command(const char *cmd);
void load_config();
void print_dashboard();
void handle_fantasy_command(char **args);
char *correct_command(char *input);
void set_env_var(char *name, char *value);
void unset_env_var(char *name);
void print_env_vars();

#endif
