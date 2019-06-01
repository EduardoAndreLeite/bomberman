#ifndef MAKEMAP_H
#define MAKEMAP_H

typedef struct MapComponent
{
  char c;     /* character representative of the map component */
  float prob; /* a given probability to the character (defines the range it has in a random pick) */
} MapComponent;

short int makeMap(void);

#endif