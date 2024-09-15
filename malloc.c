#include <stdio.h>
#include <stdlib.h>

void printValueFromIntPointer(int *ptr)
{
  // print the int by dereferencing.
  printf("This is your value: %i\n", *(ptr));
}

int main()
{
  // allocate dynamic memory for an int
  int *ptr = malloc(sizeof(int));

  *ptr = 55;

  // print the memory address of where the int lives in the heap
  printf("Here is the location in the heap: %x\n", (void *)ptr);
  // dereference pointer to get value
  printValueFromIntPointer(ptr);
  free(ptr);
  return 0;
}