#include <stdio.h>

typedef struct island
{
  char *name;
  char *opens;
  char *closes;
  struct island *next;
} island;

void display(island *first)
{
  // loop through each isand and print it
  while (first != NULL)
  {
    printf("Hello: %s\n", first->name);
  }
}

int main()
{
  char name[80];
  island *start = NULL;

  while (fgets(name, sizeof(name), stdin) != NULL)
  {
    // hello
    printf("Hello the current line: %s\n", name);
  }

  display(start);
  return 0;
}