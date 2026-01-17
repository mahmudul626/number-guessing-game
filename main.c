#include "include/game.h"

int main() {
    srand(time(0));
    int win = 0, lost = 0, found = 0;
    char user[1024], name[1024];

    printf("Enter Your Name: ");
    scanf("%1023s", user);

    FILE *fptr = fopen("data/player.txt", "r");
    if (!fptr) {
        fptr = fopen("data/player.txt", "w");
        if (!fptr) {
            printf("Failed to open file\n");
            return 1;
        }
        fclose(fptr);
        fptr = fopen("data/player.txt", "r");
    }


    // search user
    while (fscanf(fptr, "%1023s %d %d", name, &win, &lost) == 3) {
        if (strcmp(user, name) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fptr);

    // new user
    if (!found) {
        win = 0, lost = 0;
        fptr = fopen("data/player.txt", "a");
        fprintf(fptr, "%s %d %d\n", user, win, lost);
        fclose(fptr);
        printf("New user added\n");
        game_funtion(&win, &lost);

        printf("Wins: %d | Losses: %d\n", win, lost);
        if (win > lost)
            {
                printf("Unstoppable!\n");
            } else if (win < lost) {
                printf("Keep-trying!\n");
            } else {
                printf("Balanced!\n");
            }

        update_file(user, win, lost);
        leaderboard(user, win, lost);

        return 0;
    }

    // existing user
    printf("Welcome back %s\n", user);
    printf("Wins: %d | Losses: %d\n", win, lost);
    game_funtion(&win, &lost);
    update_file(user, win, lost);
    leaderboard(user, win, lost);

    printf("Wins: %d | Losses: %d\n", win, lost);
    if (win > lost)
            {
                printf("Unstoppable!\n");
            } else if (win < lost) {
                printf("Keep-trying!\n");
            } else {
                printf("Balanced!\n");
            }
    return 0;
}