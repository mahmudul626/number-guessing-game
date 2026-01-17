CC = gcc

CFLAGS = -Iinclude

SRCS = main.c src/game_logic.c src/file_manager.c src/leaderboard.c

TARGET = Mygame

all:
		$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
		rm -f $(TARGET)