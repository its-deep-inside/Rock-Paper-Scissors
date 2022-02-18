#include <stdio.h>
#include "messages.h"

// declaration
int mainmenu(int);
int modeselect(int);
void howtoplay();
void about();

// code
int mainmenu(int flag)
{
    int o = 0;
    print_mainmenu(flag);
    scanf("%d", &o);
    fflush(stdin);

    if (o >= 1 && o <= 4)
        return o;
    return 0;
}

int modeselect(int flag)
{
    int o = 0;
    print_modeselect(flag);
    scanf("%d", &o);
    fflush(stdin);

    if (o >= 1 && o <= 4)
        return o;
    return 0;
}

void howtoplay()
{
    print_howtoplay();
    getchar();
    fflush(stdin);
}

void about()
{
    print_about();
    getchar();
    fflush(stdin);
}