CC = gcc

CFLAGS = -Iinclude

SRCS = main.c src/game_logic.c src/file_manager.c src/leaderboard.c src/menu.c

TARGET = mygame

all:
		$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
		rm -f $(TARGET)