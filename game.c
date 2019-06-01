#include <ncurses.h>
#include <string.h>

#include "functions.h"
#include "game.h"
#include "animation.h"

#define MENU_OPTIONS 3

/*
    game start
    menu appears
*/

/*
    should make all necessary initialization procedures to start the game
*/
int startGame() {
  MENU_OPT opts[MENU_OPTIONS];
  int game, menu;


  game = 1;
  initscr();
  start_color();
  curs_set(0);
  noecho();
  cbreak();
  keypad(stdscr,TRUE);

  refresh();

  init_pair(1, COLOR_GREEN, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_RED);
  init_pair(3, COLOR_MAGENTA, COLOR_CYAN);
  init_pair(4, COLOR_GREEN, COLOR_WHITE);

  showMenu(opts);
  enableMenu(opts);

  endwin();


  return game;

}

// TODO Change menu to a newwin and its options to subwin
/*
    should show a stylized menu with the following options:
        - New Game
        - Load Game
        - Exit

*/
void showMenu(MENU_OPT *opts)
{
  CONSOLE_COORD endcoord;
  chtype bkg;
  WINDOW *sbw, *w;
  int i, curr;
  int maxline, maxcol, offsetCol, offsetLine;
  unsigned int size;
  short int error;
  char msg[1 + MENU_OPTIONS][30] = { "MENU", "New Game", "Load Game", "Exit" };

  error = 0;
  bkg = COLOR_PAIR(4);
  getmaxyx(stdscr, maxline, maxcol);
//
  size = maxcol - 4;
  offsetCol = middle('x', stdscr, size);
  w = makewindow(5, size, 1, offsetCol, &endcoord);
//
  wborder(w, '|', '|', '-', '-', '|', '|', '|', '|');
//
  size = (unsigned int)strlen(msg[0]);
  offsetCol = middle('x', w, size);
  offsetLine = middle('y', w, 1);
  wmove(w, offsetLine, offsetCol);
  wprintw(w, msg[0]);

  for (i = 0; i != MENU_OPTIONS; i++)
  {

    curr = i + 1; // +1 do elemento "MENU" que não está contado em MENU_OPTIONS
    opts[i].lenght = (unsigned int)strlen(msg[curr]);
    offsetCol = middle('x', stdscr, opts[i].lenght);
    opts[i].coord.line = endcoord.line + (i * 2);
    opts[i].coord.col = offsetCol;
    move(opts[i].coord.line, opts[i].coord.col);
    printw(msg[curr]);
  }

  wrefresh(w);
  refresh();
}

void enableMenu(MENU_OPT *opts)
{

  MEVENT mouse;
  int i;
  int c, xend;
  char msg[MENU_OPTIONS][30] = {
      "You've selected New Game",
      "You've selected Load Game",
      "You've selected Exit",
  };

  mousemask(BUTTON1_CLICKED, NULL);

  while (1)
  {
    c = wgetch(stdscr);
    if (c == KEY_MOUSE)
    {
      getmouse(&mouse);
      for (i = 0; i != MENU_OPTIONS; i++)
      {
        xend = opts[i].coord.col + opts[i].lenght;
        if (mouse.x >= opts[i].coord.col && mouse.x <= xend && mouse.y == opts[i].coord.line)
          bmsg(msg[i]);
      }

    }
  }

}

