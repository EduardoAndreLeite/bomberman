#ifndef COORDINATE
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
int kbhit(void);
int middle(char axis,
          WINDOW *w,
          unsigned int size);
WINDOW *makewindow(int line_amount,
                   int col_amount,
                   int line_offset,
                   int col_offset,
                   CONSOLE_COORD *coord_end);
void bmsg(char *msg);
#endif // FUNCTIONALITIES_H


