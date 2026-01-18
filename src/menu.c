#include "../include/game.h"

void menu(const char *user, int win, int lost) {

    char choice;

    while (1) {
        printf("\n================================\n");
        printf("       NUMBER GUESSING GAME\n");
        printf("================================\n");
        printf("1. Play Game\n");
        printf("2. View Leaderboard\n");
        printf("3. Exit\n");
        printf("--------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
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
                break;
            case '2':
                leaderboard(user, win, lost);
                break;
            case '3':
                printf("Thanks for playing!\n");
                return;
            default:
                printf("Invalid choice!\n");
        }
    }

}