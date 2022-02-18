#include <stdio.h>
#include "menu.h"
#include "game.h"

int main()
{
    int o, m;
    while (1)
    {
        // getting input untill got the correct choice
        o = mainmenu(0);
        while (o == 0)
            o = mainmenu(1);

        // if user select "Start"
        if (o == 1)
        {
            // getting mode until one
            m = modeselect(0);
            while (m == 0)
                m = modeselect(1);

            // if user select mode creating game
            if (m < 4)
                game(m);
        }
        else if (o == 2)
            howtoplay();
        else if (o == 3)
            about();
        else if (o == 4)
            break;
    }
    printf("Thanks For Playing!\n");
    return 0;
}