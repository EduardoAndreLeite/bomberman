/*
*
* This file contains functions that simplify the reading
* of the mapconfig file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapconf.h"

static char *conf(char *query);

short getlineqty(void)
{
  char *qty_asstring = conf("line_quantity");
  int quantity = (int)strtol(qty_asstring, NULL, 10);

  return quantity;
}

short getcolqty(void)
{
  char *qty_asstring = conf("column_quantity");
  int quantity = (int)strtol(qty_asstring, NULL, 10);

  return quantity;
}

static char *conf(char *query) {
  FILE *fp;
  char buff[255];
  char *ret;  // tem de ser ponteiro devido ao retorno da funcao strtok
  char *brkpt; // it has to be a char pointer due to strtok parameter type
  int endloop;

  brkpt = "=";

  if (!(fp = fopen("mapconf.conf", "r+")))
    ret = NULL;
  else
  {
    endloop = 0;
    while (!endloop)
    {
      if (fgets(buff, 255, (FILE *)fp) == NULL)
      {

        printf("Query not found!");
        endloop = 1;
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
            endloop = 1;
          }
        }
      }
    }

    fclose(fp);
  }


  return ret;
}
