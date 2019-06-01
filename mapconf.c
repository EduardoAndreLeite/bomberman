/*
*
* This file contains functions that simplify the reading
* of the mapconfig file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapconf.h"

int getLineAmount()
{
  char *amountAsString = getConf("lineAmount");
  int amount = (int)strtol(amountAsString, NULL, 10);

  return amount;
}

int getColumnAmount()
{
  char *amountAsString = getConf("columnAmount");
  int amount = (int)strtol(amountAsString, NULL, 10);

  return amount;
}

char *getConf(char *query)
{
  FILE *fp;
  char buff[255];
  char *val;  // tem de ser ponteiro devido ao retorno da funcao strtok
  char bk[] = "=";
  int found = 0;

  while (!found)
  {

    fp = fopen("mapconf.conf", "r+");

    /*
    *   Coloca a primeira linha do documento aberto em fp no array buff
    */
    fgets(buff, 255, (FILE *)fp);

    /*
    * This function returns a pointer to the first token found in the string.
    * A null pointer is returned if there are no tokens left to retrieve.
    */
    val = strtok(buff, bk);
    if (val != NULL)
    {

      if (strcmp(val, query) == 0)
      {
        val = strtok(NULL, bk);
        found = 1;
      }
    }
  }

  fclose(fp);

  return val;
}
