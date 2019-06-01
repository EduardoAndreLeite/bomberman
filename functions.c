#include <ncurses.h>
#include "functions.h"

int kbhit(void) {
    int ch, r;

    // turn off getch() blocking and echo
    nodelay(stdscr, TRUE);
    noecho();

    // check for input
    ch = getch();
    if( ch == ERR)      // no input
            r = FALSE;
    else                // input
    {
            r = TRUE;
            ungetch(ch);
    }

    // restore block and echo
    echo();
    nodelay(stdscr, FALSE);
    return r;
}


/*
    axis: axis whose middle is wanted
    parent: window whose middle will be gotten
    child: window where the message will be placed
    pos: position for the other axis
    msg: message to place

*/
int middle(char axis,
          WINDOW *w,
          unsigned int size)
{

  int maxCol,
      maxLine,
      middle,
      halfsize;

  getmaxyx(w, maxLine, maxCol);
  halfsize = size / 2;

  if (axis == 'y' || axis == 'Y')
    middle = (maxLine / 2) - halfsize;

  if (axis == 'x' || axis == 'X')
    middle = (maxCol / 2) - halfsize;

  return middle;
}

WINDOW *makewindow(int line_amount,
                  int col_amount,
                  int line_offset,
                  int col_offset,
                  CONSOLE_COORD *coord_end)
{
  coord_end->line = line_amount + line_offset;
  coord_end->col = col_amount + col_offset;

  return newwin(line_amount, col_amount, line_offset, col_offset);

}

void bmsg(char *msg) {

  WINDOW *sbw;
  int maxLine, maxCol;

  getmaxyx(stdscr, maxLine, maxCol);
  sbw = subwin(stdscr, 1, 0, maxLine - 1, 0);
  werase(sbw);
  wrefresh(sbw);
  wprintw(sbw, msg);
  wrefresh(sbw);
}