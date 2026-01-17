#include "../include/game.h"

void leaderboard(const char *user, int win, int lost)
{
    FILE *fptr = fopen("data/player.txt", "r");
    if (!fptr) {
        printf("Failed to open leaderboard file\n");
        return;
    }

    char name[1024];
    int w, l;

    // temporary storage
    char names[100][1024];
    int wins[100], losses[100];
    int count = 0;

    // read all players
    while (fscanf(fptr, "%1023s %d %d", name, &w, &l) == 3) {
        strcpy(names[count], name);
        wins[count] = w;
        losses[count] = l;
        count++;
    }
    fclose(fptr);

    // sort by wins (descending)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (wins[j] > wins[i]) {
                int tw = wins[i], tl = losses[i];
                char tn[1024];

                wins[i] = wins[j];
                losses[i] = losses[j];
                strcpy(tn, names[i]);

                wins[j] = tw;
                losses[j] = tl;
                strcpy(names[i], names[j]);
                strcpy(names[j], tn);
            }
        }
    }

    // print leaderboard
    printf("\n=========== LEADERBOARD ===========\n");
    printf("%-5s %-15s %-6s %-6s\n", "Rank", "Name", "Win", "Lost");
    printf("----------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-5d %-15s %-6d %-6d",
               i + 1, names[i], wins[i], losses[i]);

        if (strcmp(names[i], user) == 0)
            printf("  <-- YOU");

        printf("\n");
    }

    printf("==================================\n");
}