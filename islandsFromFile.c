#include <stdio.h>

int main()
{
  char name[80];

  while (fgets(name, sizeof(name), stdin) != NULL)
  {
    // hello
    printf("Hello the current line: %s\n", name);
  }
  return 0;
}