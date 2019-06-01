/*
*
* This file shall take care of making a random new map
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "mapconf.h"
#include "mapcomponents.h"
#include "makemap.h"


#define BRK_LINE '\n'

/*
* Local structures
*/



/*
* Functions
*/

// bool makeMap(void)
// {
//   bool borderExists = makeBorders();

//   if (!borderExists)
//     printf("An error has occurred!\n The program couldn't make a border. CALL 911!!!");

//   return true;
// }

// bool makeBorders(void)
// {
//   int i, j;
//   const int LINEAMOUNT   = getLineAmount();
//   const int COLUMNAMOUNT = getColumnAmount();
//   MapComponent components[] =
//     {
//       {CMP_UNBRKL_WALL, .1},
//       {CMP_EMPTY_SPACE, .3},
//       {CMP_BRKL_WALL, .6}
//     };


//   FILE *mapfp = fopen("newMap.txt", "w+");

//   fillLine(mapfp, CMP_UNBRKL_WALL, COLUMNAMOUNT);

//   for (i = 0; i < LINEAMOUNT - 2; i++)
//   {
//     breakLine(mapfp);

//     fputc(CMP_UNBRKL_WALL, mapfp);

//     /* COLUMAMOUNT - 2 is used to remove both sidewalls */
//     fillLineShuffle(mapfp, components, sizeof(components)/sizeof(*components), COLUMNAMOUNT - 2);

//     fputc(CMP_UNBRKL_WALL, mapfp);
//   }

//   breakLine(mapfp);

//   fillLine(mapfp, CMP_UNBRKL_WALL, COLUMNAMOUNT);



//   fclose(mapfp);

//   return true;
// }

// void fillLine(FILE *fp, char c, int columnAmount)
// {
//   int i;

//   for (i = 1; i <= columnAmount; i++)
//       fputc(c, fp);
// }


// void fillMapShuffle(FILE *fp, MapComponent *comps, size_t componentAmount, int columnAmount, int lineAmount)
// {

//   for (i = 0; i < lineAmount; i++)
//   {

//     // Coloca o CMP_UNBRKL_WALL na primeira coluna do mapa
//     fputc(CMP_UNBRKL_WALL, mapfp);

//     // Preenche o meio do mapa
//     fillMiddleShuffle(fp, comps, componentAmount, lineAmount);

//     // Coloca o CMP_UNBRKL_WALL na última coluna do mapa
//     fputc(CMP_UNBRKL_WALL, mapfp);

//     // Preenche as primeira e ultima linhas
//     if (i == 0 || i == lineAmount - 1)
//       fillLine(mapfp, CMP_UNBRKL_WALL, COLUMNAMOUNT);

//     // Quebra linha do arquivo a ser escrita
//     breakLine(mapfp);

//   }
// }

// void fillLineRandomly(FILE *fp, MapComponent *comps, size_t componentAmount, int columnAmount)
// {
//   int i, j;
//   unsigned short selected, unbkIndex;
//   unsigned int random, left;
//   unsigned int unbkWalls; /* keeps record of how many CMP_UNBRKL_WALLS were set */


//   /*
//   * Gets the index to the unbreakable wall component
//   */
//   for (i = 0; unbkIndex == componentAmount; i++)
//   {
//     if (comps[i].c == CMP_UNBRKL_WALL)
//       unbkIndex = i;
//     else
//       unbkIndex = componentAmount;
//   }


//   for (i = 1; i <= columnAmount; i++)
//   {
//     left = 0;
//     for (j = 0; j < componentAmount; j++)
//     {
//       random = rand() % 11;
//       left += 10 * comps[j].prob;
//       if (random <= left)
//       {
//         selected = j;

//         /*
//         * Keep count of how many unbreakable walls are being set
//         */
//         if (j == unbkIndex)
//           unbkWalls++;

//         break;
//       }
//     }


//     /*
//     * This conditional is to certify that there is no line full occupied with unbreakable walls
//     */
//     if (unbkWalls != columnAmount)
//       fputc(comps[selected].c, fp);
//     else
//       fputc(CMP_EMPTY_SPACE, fp);
//   }
// }

// void fillMiddleShuffle(FILE *fp, MapComponent *comps, size_t componentAmount, int columnAmount, int lineAmount)
// {
//   int i, j, lineControl;
//   char around[3][columnAmount], currComponent;
//   unsigned short selected, unbkIndex;
//   unsigned int random, left;
//   unsigned int unbkWalls; /* keeps record of how many CMP_UNBRKL_WALLS were set */

//   lineControl = 0;
//   for (i = 0; i < columnAmount; i++)
//   {

//     currComponent = randomComponent(comps, componentAmount);
//     around[lineControl][i] = currComponent;

//     if (currComponent == CMP_UNBRKL_WALL)
//       unbkWalls++;

//     if (lineControl < 2)
//         lineControl++;
//     else
//         lineControl = 0;

//     ////////////////////////////
//     // Considerar as linhas ja preenchidas pela função anterior
//     ////////////////////////////


//     if (i != 0)
//     {

//         if (around)

//     }


//     /*
//     * This conditional is to certify that there is no line full occupied with unbreakable walls
//     */
//     if (unbkWalls != columnAmount)
//     {
//       around[lineControl][i] = selected;
//       fputc(currComponent, fp);

//     }
//     else
//     {

//       around[lineControl][i] = CMP_EMPTY_SPACE;
//       fputc(CMP_EMPTY_SPACE, fp);
//     }
//   }
// }

// char randcmpt(MapComponent *comps, size_t componentAmount)
// {
//   int i;
//   unsigned int random, left;
//   char comp;

//   left = 0;
//   random = rand() % 11;

//   for (i = 0; i < componentAmount; i++)
//   {
//     left += 10 * comps[i].prob;
//     if (random <= left)
//     {
//       comp = comps[i].c;
//       break;
//     }
//   }
//   return comp;
// }

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
// void breakLine(FILE *fp)
// {
//   fputc(BRK_LINE, fp);
// }
