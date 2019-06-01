#include <ncurses.h>
/*
    player moves
    player takes damage

    enemy moves
    enemy dies

    bomb is planted
    bomb explodes

    blocks explode

    key appears

    score, life or available bombs change

    ----

    menu appears



*/

int move_player(WINDOW *wind) {
    WINDOW *subwind;
    char key;
    short int x,y;
    unsigned short int flag;
    chtype background;

    background = COLOR_PAIR(1);
    wbkgd(wind, background);

    flag = 0;
    x = 10;
    y = 10;
    while (1)
    {

        key = getchar();
        if (key == 'a')
            x--;
        else if (key == 'd')
            x++;
        else if (key == 's')
            y++;
        else if (key == 'w')
            y--;
        else if (key == KEY_ENTER)
            break;

        if (flag)
        {

            wbkgd(wind, background);
            delwin(subwind);
        }

        flag = 1;
        subwind = subwin(wind, 1, 1, y, x);
        wbkgd(subwind, COLOR_PAIR(3));
        wrefresh(wind);

    }

    return 0;
}
