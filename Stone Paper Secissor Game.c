//PROJECT:- "Stone Paper Secissor Game"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int player, computer;
    /*
    0 ---> Stone
    1 ---> Paper
    2 ---> Scissors
    */
    printf("!!! Welcome to our game !!!\n");
    while (1)
    {
        printf("Enter 0 for Stone,1 for Paper,2 for Scissors & 5 to leave ");
        scanf("%d", &player);
        computer = (rand() % 3) + 0;
        if (player == 0)
        {
            if (computer == 0)
            {
                printf("Draw !\n");
            }
            else if (computer == 1)
            {
                printf("Computer Won !\n");
            }
            else if (computer == 2)
            {
                printf("You Won !\n");
            }
        }
        else if (player == 1)
        {
            if (computer == 0)
            {
                printf("You Won !\n");
            }
            else if (computer == 1)
            {
                printf("Draw !\n");
            }
            else if (computer == 2)
            {
                printf("Computer Won !\n");
            }
        }
        else if (player == 2)
        {
            if (computer == 0)
            {
                printf("Computer Won !\n");
            }
            else if (computer == 1)
            {
                printf("You Won !\n");
            }
            else if (computer == 2)
            {
                printf("Draw !\n");
            }
        }
        else if (player == 5)
        {
            break;
        }
        else
        {
            printf("Please Enter 0,1,2 to lead the game and enter 5 to leave the game!\n");
        }
    }
    printf("!!! GoodBuy !!!");
    return 0;
}