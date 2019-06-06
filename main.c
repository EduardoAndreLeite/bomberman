#include <ncurses.h>

#include "functions.h"
#include "game.h"
#include "makemap.h"
#include "mapconf.h"

int main(void)
{
  bool a;

  makemap("map1.txt");

  //startGame();
  // do
  // {
  //   kbhit();

  // } while (game);

  return 0;
}
