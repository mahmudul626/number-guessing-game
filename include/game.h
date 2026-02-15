#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define CYAN    "\033[1;36m"
#define RESET   "\033[0m"


void game_funtion(int *win, int *lost);
void update_file(const char *user, int win, int lost);
void leaderboard(const char *user, int win, int lost);
void menu(const char *user, int win, int lost);
void clear_screen();

#endif