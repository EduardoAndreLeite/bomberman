/*
*
* This file shall take care of making a random new map
*/

/* includes */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "mapconf.h"
#include "mapcomponents.h"
#include "makemap.h"
#include "functions.h"

/* macros and constants */

#define BRK_LINE '\n'

/* local structures */

typedef struct MapComponent
{
  char c;     /* character representative of the map component */
  float prob; /* a given probability to the character (defines the range it has in a random pick) */
} MapComponent;

static bool skipline(FILE *fp, int colQty);
static bool breakline(FILE *fp);
static bool line(FILE *fp, char c, int colQty);
static bool randline(FILE *fp, MapComponent cmps[], size_t cmpQty, int colQty);
static bool makeborders(FILE *fp, int lineQty, int colQty);

/*
* Functions
*/

bool makemap(char *mapName) {

  const int LINE_QTY = getlineqty();
  const int COL_QTY = getcolqty();
  bool s;
  int i;
  size_t cmpsSize;
  char path[50] = "map/";
  FILE *mapFile;
  MapComponent cmps[] = {{CMP_UNBRKL_WALL, .1}, {CMP_EMPTY_SPACE, .38}, {CMP_BRKL_WALL, .52}};


  srand(clock());
  cmpsSize = sizeof(cmps) / sizeof(MapComponent);

  strcat(path, mapName);

  succ(&s);
  if (!(mapFile = fopen(path, "w+")))
    err(&s);
  else
  {

    if (!makeborders(mapFile, LINE_QTY, COL_QTY))
      err(&s);
    else
    {
      if (fseek(mapFile, 0, SEEK_SET) != 0) // reseta o cursor para o inicio do arquivo
        err(&s);
      else
      {

        if (!skipline(mapFile, COL_QTY)) // pula COL_QTY colunas e quebra a linha
          err(&s);
        else
        {

          for (i = 0; i < LINE_QTY - 2; i++)
          {

            fseek(mapFile, 1, SEEK_CUR);
            randline(mapFile, cmps, cmpsSize, COL_QTY - 1);
            fseek(mapFile, 1, SEEK_CUR);
            breakline(mapFile);
          }
        }
      }
    }

    fclose(mapFile);
  }


  return s;
}

static bool makeborders(FILE *fp, int lineQty, int colQty) {

  bool s;
  int i, j;

  succ(&s);

  line(fp, CMP_UNBRKL_WALL, colQty);
  for (i = 0; i < lineQty - 2; i++)
  {
    breakline(fp);
    fputc(CMP_UNBRKL_WALL, fp);
    line(fp, CMP_EMPTY_SPACE, colQty - 2);
    fputc(CMP_UNBRKL_WALL, fp);
  }
  breakline(fp);
  line(fp, CMP_UNBRKL_WALL, colQty);

  return s;
}

static bool line(FILE *fp, char c, int colQty) {

  bool ret;
  int i;

  ret = 1;
  for (i = 1; i <= colQty; i++)
  {
    if (!fputc(c, fp))
    {
      ret = 0;
      break;
    }
  }

  return ret;
}

static bool randline(FILE *fp, MapComponent cmps[], size_t cmpQty, int colQty)
{

  bool s;
  int i, j;
  int unbkWalls; /* keeps record of how many CMP_UNBRKL_WALLS were set */
  short random, left;
  char selected;

  succ(&s);
  for (i = 1; i < colQty; i++)
  {
    left = 0;
    random = rand() % 101; // devolve um numero no intervalo [0, 100]
    for (j = 0; j < cmpQty; j++)
    {
      left += 100 * cmps[j].prob;
      if (random <= left)
      {

        if ((selected = cmps[j].c) == CMP_UNBRKL_WALL)
        {
          if (unbkWalls >= colQty * .7)
            selected = CMP_EMPTY_SPACE;
          else
            unbkWalls++;
        }

        if (fputc(selected, fp) != selected)
          err(&s);
        break;
      }
    }
  }

  return s;
}

// void fillBoxes(int amount)
// {
//   /* TODO make fillBoxes
//   coloca baus, pelo menos 5, em lugares acessiveis para o player;
//   scolumnAmounto que para ser acessivel deve ter um caminho de espaços em branco ou paredes quebraveis até o player
//   */
// }
// /* TODO make placeEnemies
// coloca inimigos em lugares com bastante espaço em branco, permitindo a eles se movimentar
// */
static bool breakline(FILE *fp)
{

  bool s;

  succ(&s);
  if (!fputc(BRK_LINE, fp))
    err(&s);

  return s;
}


static bool skipline(FILE *fp, int colQty) {
  bool s;

  succ(&s);
  if (fseek(fp, colQty, SEEK_CUR) != 0)
    err(&s);
  else
    breakline(fp);

  return s;
}