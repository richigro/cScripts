/*
 *This is used to tell me what are the sizes of each data type
 * this is specific to where the program is ran.
 * Depends on the architecture of the machine
 */
#include <stdio.h>

int main()
{

  printf("the size of an int is: %zu\n", sizeof(int));

  return 0;
}