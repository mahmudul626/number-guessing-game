#include "../include/game.h"

//Game Logic
void game_funtion(int *win, int *lost) {
    char choice;
    do
    {
        int input, limit = 3, prev = 0;
        int hintUsed = 2;
        int secretNum = rand() % 10 + 1;
        printf("\t Number Guessing Game \n");
        while(limit > 0)
        {
            printf("\n");
            printf("Chance : %d time | Hint Left: %d %s\n", limit, hintUsed,
            (limit == 1) ? "(disabled)" : "");
            
            printf("Enter number (or -1 for hint): ");

            while (scanf("%d", &input) != 1) {
            printf("Error! Invalid input\n");
            printf("Enter number (or -1 for hint): ");
            while (getchar() != '\n'); 
            }
            printf("\n");
            // Hint request
            if (input == -1) {
                if (hintUsed == 0) {
                    printf("Hint already used!\n");
                    continue;
                }
                
                
                if (limit == 1)
                {
                    printf("Hints not allowed on last chance!\n");
                    continue;
                } else if (hintUsed == 2)
                {
                    // Hint 1: even / odd
                    if (secretNum % 2 == 0)
                        printf("Hint: Number is even\n");
                    else
                        printf("Hint: Number is odd\n");
                } else {
                    // Hint 2: range hint
                    int low = secretNum - 2;
                    int high = secretNum + 2;

                    if (low < 1) low = 1;
                    if (high > 10) high = 10;

                    printf("Hint: Between %d and %d\n", low, high);
                }

                hintUsed --;
                limit --;
                continue;
            }


            if (input != secretNum)
                {
                limit --;
                if (limit == 0)  {
                                (*lost) ++;
                                printf("Out of limit!\n");
                                printf("No chances left.\n");
                                printf("You lost this round!\n");
                                printf("\n");
                                break;
                    } else if (secretNum < input)   {
                                if(prev != 0) {

                                    if(abs(secretNum-input) < abs(secretNum-prev))
                                    {
                                        printf("You're getting closer!\n");
                                    } else {
                                        printf("You're getting farther!\n");
                                    }
                                    
                                } else {
                                    printf("%d is too high \n", input);
                                }

                    } else if (secretNum > input)   {
                                if(prev != 0) {

                                    if(abs(secretNum-input) < abs(secretNum-prev))
                                    {
                                        printf("You're getting closer!\n");
                                    } else {
                                        printf("You're getting farther!\n");
                                    }
                                    
                                } else {
                                    printf("%d is too low \n", input);
                                }
                    }
            } else {
                    (*win) ++;
                    if(limit == 3) {
                        printf("Perfect Guess!\n");
                        printf("\n");
                    } else {
                        printf("You win\n");
                        printf("\n");
                    }
                    break;
            }
        if (input != -1)
        prev = input;

        }

    printf("Do you want to play more (y/n) :");
    scanf(" %c", &choice);

    while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
        printf("Error! Invalid input\n");
        printf("Do you want to play more (y/n) :");
        while (getchar() != '\n');
        scanf(" %c", &choice);
    }
    
    } while (choice == 'y' || choice == 'Y');
}