/*
 * Array behave a little differently than other data types when it comes to pointers.
 */

#include <stdio.h>

int main()
{
  char quote[] = "Cookies make you fat";

  // Here I'm printing quote as if it was a pointer ?
  printf("%p", quote);
  return 0;
}
