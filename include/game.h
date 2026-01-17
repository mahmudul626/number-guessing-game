#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void game_funtion(int *win, int *lost);
void update_file(const char *user, int win, int lost);
void leaderboard(const char *user, int win, int lost);

#endif