#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct island
{
  char *name;
  char *opens;
  char *closes;
  struct island *next;
} island;

island *createIsland(char *name)
{

  // create space for new island on the heap
  island *newIsland = malloc(sizeof(island));
  // make a copy of the name string
  char *nameCopy = strdup(name);

  // assign value to newIsland
  newIsland->name = nameCopy;
  newIsland->opens = "7AM";
  newIsland->closes = "11PM";
  newIsland->next = NULL;

  // Free the memory from heap of nameCopy pointer
  free(nameCopy);

  return newIsland;
}

void displayFlightLog(island *one, island *two)
{
  puts("DISPLAYING FLIGHT LOG >>\n");
  printf("The Name of the first Island was: %s\nThe Name of the second Island was: %s\n", one->name, two->name);
}

int main()
{
  char islandName[80];

  // get the name for the island
  puts("Provide the name for the first Island: \n");
  fgets(islandName, 80, stdin);
  // create first island
  island *island_1 = createIsland(islandName);

  // get the name for the next island
  puts("Provide the name of the second Island: \n");
  fgets(islandName, 80, stdin);
  // create second island
  island *island_2 = createIsland(islandName);

  // print the name of both island
  displayFlightLog(island_1, island_2);

  // remove pointer from the heap
  free(island_1);
  free(island_2);

  return 0;
}