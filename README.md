# Game like Bomberman

## Some conventions
* Git commits messages verbs' msut be on *infinitive*;
* *Avoid* use of global variables, use constants if needed;
* Headers must check if it's declarations have been defined before;

## Naming patterns

### Files
  Files' names must be **lowercase** and start with a letter.
  #### Valid examples
  ```
    main.c
    functions.c
    functions.h
  ```

### Constants and Macros
  *Macros are like "nicknames" for a value*
  Constants' must be **uppercase** and use *_* as replacement for white space characters.
  If a name seems too unexpressive it must have a comment explaning it's use.
  #### Valid examples
  ```
    MAP_CODE "101"
    HEIGHT 35.6
    SCREEN_SIZE 90
    X_QTY 1 /* quantity of x coordinates in a coord structure */
  ```

### Variables
  Variables' must be **camelCase**.
  If a name seems too unexpressive it must have a comment explaning it's use.
  Only strings shall be initialized. If a primitive type variable needs a initial value assign it just before using the variable.
  #### Valid examples
  ```
    short userId;
    char *myNameIsThis = "Luke Skywalker";
    userId = 50;
  ```

### Functions
  Functions' must be **lowercase** and be accompanied by a short documentation of it's use.
  #### Valid examples
  ```
    /* puts the menu on screen */
    void showmenu (int sizeOfScreen) ...

    /* returns a pointer to the last option in the menu */
    int *lastoption(void) ...
  ```

## Structures and Unions
  Structures and unions' shall be **PascalCase** and, if it's name isn't clear enough, a short documentation of it's use.
  If a structure is used more than in one variable, create a typedef for it.
  #### Valid examples
  ```
    struct Map {
      char *name;
      int ySize;
      int xSize;
    } mapOne;

    /* represents the feature that a car has */
    union OneCarFeature {
      SunRoof sunRoot;
      AirBag airBag;
      Nitro nitro;
      char color[50];
    } carFeature;

    typedef struct Coordinate {
      int x;
      int y;
      int z;
    } Coord;
  ```
