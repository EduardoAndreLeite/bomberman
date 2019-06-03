#ifndef NCURSES_H
#define NCURSES_H
#include <ncurses.h>
#endif

#ifndef COORDINATE
#define COORDINATE
typedef struct console_coordinates
{
  int col;
  int line;
} CONSOLE_COORD;
typedef struct menu_option
{
  CONSOLE_COORD coord;
  unsigned int lenght;
} MENU_OPT;
#endif // COORDINATE

#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
int kbhit(void);
int middle(char axis, WINDOW *w, unsigned int size);
WINDOW *makewindow(int lineQty, int colQty, int lineOffset, int colOffset, CONSOLE_COORD *coordEnd);
void bmsg(char *msg);
char *err(bool *success);
char *succ(bool *success);
#endif // FUNCTIONALITIES_H


