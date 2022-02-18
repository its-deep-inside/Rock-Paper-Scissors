#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "messages.h"
#include <ctype.h>

// declaration
int check_win(int, int);
void game(int);

// code
int check_win(int o, int mode)
{
    int cpu;
    srand(time(0)); // setting random seed
    if (mode == 1)
        cpu = rand() % 3 + 1; // getting random choice
    else if (mode == 2)
    {
        // getting random choice between 2
        cpu = rand() % 2;
        cpu = (cpu + o) % 3 + 1;
    }
    else
        cpu = o % 3 + 1; // getting perfect shot

    show_result(o, cpu);

    if (o == cpu)
        return 0;
    else if ((o == 1 && cpu == 3) || (o == 2 && cpu == 1) || (o == 3 && cpu == 2))
        return 1;
    else
        return -1;
}

void game(int mode)
{
    char choice;
    int o, win;

    print_game();
    scanf("%c", &choice);
    fflush(stdin);

    // getting users choice
    if (tolower(choice) == 'r')
        o = 1;
    else if (tolower(choice) == 'p')
        o = 2;
    else if (tolower(choice) == 's')
        o = 3;
    else
    {
        printf("Wrong Input!\n\n");
        printf("press any key to go back...");
        getchar();
        fflush(stdin);
        return;
    }

    // cheecking win with help of user input and mode
    win = check_win(o, mode);
    if (win == 0)
        printf("Draw!\n\n");
    else if (win == 1)
        printf("You Won!\n\n");
    else if (win == -1)
        printf("CPU Won!\n\n");

    printf("press any key to go back...");
    getchar();
    fflush(stdin);
}