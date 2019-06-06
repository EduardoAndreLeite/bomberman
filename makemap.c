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

static void skipline(FILE *fp, int colQty);
static void breakline(FILE *fp);
static void line(FILE *fp, char c, int colQty);
static void randline(FILE *fp, MapComponent cmps[], size_t cmpQty, int colQty);
static void makeborders(FILE *fp, int lineQty, int colQty);

/*
* Functions
*/

void makemap(char *mapName) {
  getlineqty();
  const int LINE_QTY = getlineqty();
  const int COL_QTY = getcolqty();
  int i;
  size_t cmpsSize;
  FILE *mapFile;
  MapComponent cmps[] = {{CMP_UNBRKL_WALL, .1}, {CMP_EMPTY_SPACE, .38}, {CMP_BRKL_WALL, .52}};


  srand(clock());
  cmpsSize = sizeof(cmps) / sizeof(MapComponent);

  strcat(path, mapName);
  if (!(mapFile = fopen(path, "w+")))
    error("File not found!");
  else
  {
    fseek(mapFile, 0, SEEK_SET); // reseta o cursor para o inicio do arquivo
    skipline(mapFile, COL_QTY); // pula COL_QTY colunas e quebra a linha

    for (i = 0; i < LINE_QTY - 2; i++)
    {

      fseek(mapFile, 1, SEEK_CUR);
      randline(mapFile, cmps, cmpsSize, COL_QTY - 1);
      fseek(mapFile, 1, SEEK_CUR);
      breakline(mapFile);
    }
    fclose(mapFile);
  }
}

static void makeborders(FILE *fp, int lineQty, int colQty) {

  int i, j;

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
}

static void line(FILE *fp, char c, int colQty) {

  int i;

  for (i = 1; i <= colQty; i++)
  {
    if (!fputc(c, fp))
      erro("Couldn't print line.");
  }
}

static void randline(FILE *fp, MapComponent cmps[], size_t cmpQty, int colQty)
{

  int i, j;
  int unbkWalls; /* keeps record of how many CMP_UNBRKL_WALLS were set */
  short random, left;
  char selected;

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
          error("Couldn't print random line.");
        break;
      }
    }
  }
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
static void breakline(FILE *fp)
{

  if (!fputc(BRK_LINE, fp))
    erro("Couldn't breakline.");
}


static void skipline(FILE *fp, int colQty) {

  if (fseek(fp, colQty, SEEK_CUR) != 0)
    erro("Error when skipping line.");
  else
    breakline(fp);
}
