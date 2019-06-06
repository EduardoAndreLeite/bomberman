#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif // EXIT_FAILURE

#ifndef NCURSES_H
#define NCURSES_H 0
#include <ncurses.h>
#endif

#ifndef COORDINATE
#define COORDINATE 0
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

#ifndef FUNCTIONS_H
#define FUNCTIONS_H 0
int kbhit(void);
int middle(char axis, WINDOW *w, unsigned int size);
WINDOW *makewindow(int lineQty, int colQty, int lineOffset, int colOffset, CONSOLE_COORD *coordEnd);
void bmsg(char *msg);
char *err(bool *success);
char *succ(bool *success);
#endif // FUNCTIONS_H


