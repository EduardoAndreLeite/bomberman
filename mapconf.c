/*
*
* This file contains functions that simplify the reading
* of the mapconfig file.
*/
#define ABSOLUTE_PATH 129

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "mapconf.h"

static char *conf(char *query);

short getlineqty(void)
{
  char *qtyAsString = conf("line_quantity");
  int quantity = (int)strtol(qtyAsString, NULL, 10);

  return quantity;
}

short getcolqty(void)
{
  char *qtyAsString = conf("column_quantity");
  int quantity = (int)strtol(qtyAsString, NULL, 10);

  return quantity;
}

static char *conf(char *query) {
  FILE *fp;
  char buff[255];
  char *ret;  // tem de ser ponteiro devido ao retorno da funcao strtok
  char *brkpt; // it has to be a char pointer due to strtok parameter type
  char dirPath[ABSOLUTE_PATH];
  int endLoop;

  getcwd(dirPath, ABSOLUTE_PATH);

  strcat(dirPath, "map.conf");


  brkpt = "=";
  if (!(fp = fopen(dirPath, "r+")))
    ret = NULL;
  else
  {
    endLoop = 0;
    while (!endLoop)
    {
      if (fgets(buff, 255, (FILE *)fp) == NULL)
      {

        printf("Query not found!");
        endLoop = 1;
      }
      else
      {
        /*
        * This function returns a pointer to the first token found in the string.
        * A null pointer is returned if there are no tokens left to retrieve.
        */
        if ((ret = strtok(buff, brkpt)) != NULL)
        {

          if (strcmp(ret, query) == 0)
          {
            ret = strtok(NULL, brkpt);
            endLoop = 1;
          }
        }
      }
    }

    fclose(fp);
  }


  return ret;
}
