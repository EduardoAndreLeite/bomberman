#include <ncurses.h>

#include "functions.h"
#include "game.h"

int main(void)
{
  int game;

  startGame();
  do
  {
    kbhit();

  } while (game);

  return 0;
}