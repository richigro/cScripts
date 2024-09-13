#include <stdio.h>

typedef struct island
{
  char *name;
  char *opens;
  char *closes;
  struct island *next;
} island;

void display(island *start)
{
  island *i = start;
  for (; i != NULL; i = i->next)
  {
    printf("Name %s open: %s-%s\n", i->name, i->opens, i->closes);
  }
}

int main()
{
  island monkeyIsland = {"Monkey Island", "5AM", "10PM", NULL};  // From Legend of Monkey Island
  island skullIsland = {"Skull Island", "6AM", "8PM", NULL};     // From King Kong
  island islaNublar = {"Isla Nublar", "7AM", "9PM", NULL};       // From Jurassic Park
  island laputa = {"Laputa", "8AM", "5PM", NULL};                // From Castle in the Sky
  island hyruleIsland = {"Hyrule Island", "6AM", "10PM", NULL};  // From The Legend of Zelda
  island neverland = {"Neverland", "5AM", "11PM", NULL};         // From Peter Pan
  island roanokeIsland = {"Roanoke Island", "7AM", "7PM", NULL}; // From American Horror Story
  island rapture = {"Rapture", "9AM", "8PM", NULL};              // From BioShock
  island pandora = {"Pandora", "6AM", "9PM", NULL};              // From Avatar is the last one at the moment

  // assign relationships
  monkeyIsland.next = &skullIsland;
  skullIsland.next = &islaNublar;
  islaNublar.next = &laputa;
  laputa.next = &hyruleIsland;
  hyruleIsland.next = &neverland;
  neverland.next = &roanokeIsland;
  roanokeIsland.next = &rapture;

  display(&monkeyIsland); // pass in the first island first or the head
  return 0;
}