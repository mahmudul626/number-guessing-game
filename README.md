# number-guessing-game

This project is a modular implementation of a number guessing game written in C. Unlike typical single-file implementations, this codebase is organized into a professional directory structure that separates core concerns. The architecture ensures that the game logic, persistent storage management, and leaderboard processing are handled by independent modules. By keeping header files in include/ and implementation files in src/, the project demonstrates how to maintain a clean and scalable environment for C development.

The system features a robust data persistence layer. It tracks player statistics, including wins and losses, by reading from and writing to a dedicated storage file located in the data/ directory. A sorting algorithm is implemented within the leaderboard module to rank players dynamically. This modularity ensures that the file management system remains decoupled from the game’s interactive logic, allowing for easier debugging and potential expansion, such as adding database support or more complex scoring systems.

Build automation is handled via a Makefile, which manages the compilation and linking of the multiple source files. This approach eliminates the need for manual compilation commands and ensures that the executable, Mygame, is built with consistent flags. The project also includes a clean-up routine to maintain a tidy workspace. The use of relative paths and header guards ensures that the system is stable across different local environments, provided the directory integrity is maintained.
How to use this

    Clone it: git clone https://github.com/mahmudul626/number-guessing-game.git

    Open it: cd number-guessing-game

    Build it: make

    Run it: ./Mygame

    Clean the mess: make clean

Project Layout

The following tree structure illustrates the organization of the codebase:

number-guessing-game/
├── data/
│   └── player.txt
├── include/
│   └── game.h
├── src/
│   ├── file_manager.c
│   ├── game_logic.c
│   └── leaderboard.c
├── main.c
├── Makefile
├── README.md
└── LICENSE

-- Md. Mahmudul Hasan Mabud