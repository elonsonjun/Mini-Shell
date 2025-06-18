// autocorrect.c
#include "shell.h"

static const char *known_cmds[] = {
    "cd", "exit", "history", "clear", "stats",
    "setenv", "unsetenv", "printenv",
    "quantum", "summon", "fortune", "dance", NULL
};

// Compute Levenshtein Distance (Edit Distance)
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int matrix[len1+1][len2+1];

    for (int i = 0; i <= len1; i++) matrix[i][0] = i;
    for (int j = 0; j <= len2; j++) matrix[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            matrix[i][j] = fmin(
                fmin(matrix[i-1][j] + 1,     // deletion
                     matrix[i][j-1] + 1),    // insertion
                     matrix[i-1][j-1] + cost); // substitution
        }
    }

    return matrix[len1][len2];
}

char *correct_command(char *input) {
    int min_dist = 3;
    const char *best_match = NULL;

    for (int i = 0; known_cmds[i]; i++) {
        int dist = levenshtein(input, known_cmds[i]);
        if (dist < min_dist) {
            min_dist = dist;
            best_match = known_cmds[i];
        }
    }

    if (best_match) {
        printf("🤖 Did you mean '%s' instead of '%s'?\n", best_match, input);
        return strdup(best_match);
    }

    return input;
}
