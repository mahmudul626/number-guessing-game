#include "include/game.h"

int main() {
    srand(time(0));
    int win = 0, lost = 0, found = 0;
    char user[1024], name[1024];
    clear_screen();
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
        menu(user, win, lost);
        return 0;
    }

    // existing user
    printf("Welcome back %s\n", user);
    menu(user, win, lost);
    return 0;
}

void clear_screen() {
    printf("\033[2J\033[H");
}
