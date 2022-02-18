#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// declaration
void create_line(int);
void clear();
void print_mainmenu(int);
void print_modeselect(int);
void print_howtoplay();
void print_about();
void print_game();
void rev(char s[][25], char c[][25]);
void show_result(int, int);

// code

// create_line: prints a line of length len
void create_line(int len)
{
    int i;
    printf("+");
    for (i = 0; i < len + 12; i++)
        printf("-");
    printf("+\n");
}

// clear: clear the screen and print heading of page
void clear(char s[])
{
    int len = strlen(s);
    system("cls");
    create_line(len);
    printf("|      %s      |\n", s);
    create_line(len);
    printf("\n");
}

// Print Functions
void print_mainmenu(int flag)
{
    clear("Main Menu");
    printf("1. Start\n");
    printf("2. How to play!\n");
    printf("3. About\n");
    printf("4. Exit\n\n");

    if (flag)
        printf("wrong choice!\n");
    printf("Enter Choice: ");
}

void print_modeselect(int flag)
{
    clear("Mode Select");
    printf("1. Normal\n");
    printf("2. Hard\n");
    printf("3. God\n");
    printf("4. Back\n\n");

    if (flag)
        printf("wrong choice!\n");
    printf("Enter Choice: ");
}

void print_howtoplay()
{
    clear("How To Play");
    printf("### Modes ###\n");
    printf("1. Easy    : your chances of winning are high.\n");
    printf("2. Normal  : your chances of winning are low.\n");
    printf("3. God     : your chances of winning are zero.\n\n");

    printf("### Rules ###\n");
    printf("It's just rock paper scissor, you know the rules so do I!\n\n");
    printf("press any key to go back...");
}

void print_about()
{
    clear("About");
    printf("Developer: Deep\n");
    printf("Version: v0.1\n");
    printf("Language: C\n");
    printf("Compiler: GCC 6.3.0\n\n");
    printf("press any key to go back...");
}

void print_game()
{
    clear("Game");
    printf("Choices:\n");
    printf("Rock: (r / rock / R / Rock)\n");
    printf("Paper: (p / paper / P / Paper)\n");
    printf("Scissor: (s / Scissor / S / Scissor)\n\n");
    printf("Enter Your Choice: ");
}

// rev: custom reverse function to reverse the shape
void rev(char s[6][25], char c[6][25])
{
    int i, j, l;
    for (i = 0; i < 6; i++)
    {
        j = 0;
        l = strlen(s[i]) - 1;
        while (l)
        {
            if (s[i][l] == '(')
                c[i][j++] = ')';
            else if (s[i][l] == ')')
                c[i][j++] = '(';
            else
                c[i][j++] = s[i][l];
            l--;
        }
        c[i][j] = '\0';
    }
}

// show_result: print result and art
void show_result(int p, int c)
{
    int i;
    char cpu[6][25];

    char rock[6][25] = {
        "      _______  ",
        "  ---'   ____) ",
        "        (_____)",
        "        (_____)",
        "        (____) ",
        "  ---.__(___)  "};

    char paper[6][25] = {
        "      _______       ",
        "  ---'   ____)____  ",
        "           _______) ",
        "           ________)",
        "          ________) ",
        "  ---._________)    "};

    char scissor[6][25] = {
        "      _______      ",
        "  ---'   ____)____ ",
        "           _______)",
        "         _________)",
        "        (____)     ",
        "  ---.__(___)      "};

    // getting cpu art
    if (c == 1)
        rev(rock, cpu);
    else if (c == 2)
        rev(paper, cpu);
    else if (c == 3)
        rev(scissor, cpu);

    // printing both art with gap of 10 space
    for(i = 0; i < 6; i++)
    {
        if(p == 1)
            printf("%s          %s\n", rock[i], cpu[i]);
        else if(p == 2)
            printf("%s          %s\n", paper[i], cpu[i]);
        else if(p == 3)
            printf("%s          %s\n", scissor[i], cpu[i]);
    }

    // ending the art and showing result
    printf("\n");
    printf("     You                         Cpu\n");
    printf("\n\n");
}