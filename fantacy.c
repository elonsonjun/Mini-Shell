// fantasy.c
#include "shell.h"

void handle_fantasy_command(char **args) {
    if (strcmp(args[0], "quantum") == 0) {
        printf("🌀 Initiating quantum tunnel... Entangling particles...\n");
        sleep(2);
        printf("✅ Quantum leap successful. You are now in a parallel universe 🌌\n");
    }
    else if (strcmp(args[0], "summon") == 0 && args[1]) {
        printf("✨ Summoning %s...\n", args[1]);
        sleep(1);
        printf("⚡ %s has arrived!\n", args[1]);
    }
    else if (strcmp(args[0], "fortune") == 0) {
        const char *fortunes[] = {
            "🌟 Your shell will shine brighter than ever!",
            "💡 A clever command is in your near future.",
            "🪄 Magic lies in mastering the command line.",
            "☁️ Beware of pipes and redirects."
        };
        srand(time(NULL));
        int r = rand() % 4;
        printf("🔮 %s\n", fortunes[r]);
    }
    else if (strcmp(args[0], "dance") == 0) {
        printf("💃 Executing shell dance sequence...\n");
        for (int i = 0; i < 3; i++) {
            printf("🕺💃 ");
            fflush(stdout);
            sleep(1);
        }
        printf("\n🎉 Done!\n");
    }
}
