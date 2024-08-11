/*
 * This is just a test program to test the compiler
 */

#include <stdio.h>

int main()
{
  int decks;
  puts("entr a number of decsk");
  scanf("%i", &decks);
  if (decks < 1)
  {
    puts("that is not a valid number of decks");
    return 1;
  }

  printf("there are %i cards\n", (decks * 52));
  return 0;
}