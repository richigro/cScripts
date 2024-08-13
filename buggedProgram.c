/*
  The code below won't compile, because we are attempting to change the contents
  of a string literal, and string literals are stored in the constants section
  in memory, making this string literal read-only.
  To fix this you must simply change how the cards string is define, and define it
  with an array rather than using a pointer.
  E.g: char cards[] = "JQK";
*/

#include <stdio.h>

int main()
{
  char *cards = "JQK";
  char a_card = cards[2];
  cards[2] = cards[1];
  cards[1] = cards[0];
  cards[0] = cards[2];
  cards[2] = cards[1];
  cards[1] = a_card;
  puts(cards);
  return 0;
}