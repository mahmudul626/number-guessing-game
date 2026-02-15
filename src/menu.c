#include "../include/game.h"

void menu(const char *user, int win, int lost) {

    char choice;

    while (1) {
        printf(BLUE"================================\n"RESET);
        printf(CYAN"       NUMBER GUESSING GAME\n"RESET);
        printf(BLUE"================================\n"RESET);
        printf("1. Play Game\n");
        printf("2. View Leaderboard\n");
        printf("3. Exit\n");
        printf("--------------------------------\n");
        printf(GREEN"Enter your choice: "RESET);
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                game_funtion(&win, &lost);
                printf(GREEN "Wins: %d" RESET " | " RED "Losses: %d\n" RESET, win, lost);
                if (win > lost)
                    {
                        printf(CYAN"Unstoppable!\n"RESET);
                    } else if (win < lost) {
                        printf(CYAN"Keep-trying!\n"RESET);
                    } else {
                        printf(CYAN"Balanced!\n"RESET);
                    }

                update_file(user, win, lost);
                break;
            case '2':
                leaderboard(user, win, lost);
                break;
            case '3':
                printf(CYAN"Thanks for playing!\n"RESET);
                return;
            default:
                printf(RED"Invalid choice!\n"RESET);
        }
    }

}