#include "../include/game.h"

//Updating Scores in the Score Sheet
void update_file(const char *user, int win, int lost) {
    FILE *read = fopen("data/player.txt", "r");
    FILE *temp = fopen("data/temp.txt", "w");

    char name[1024];
    int w, l;

    while (fscanf(read, "%1023s %d %d", name, &w, &l) == 3) {
        if (strcmp(name, user) == 0) {
            fprintf(temp, "%s %d %d\n", user, win, lost);
        } else {
            fprintf(temp, "%s %d %d\n", name, w, l);
        }
    }

    fclose(read);
    fclose(temp);

    remove("data/player.txt");
    rename("data/temp.txt", "data/player.txt");
}