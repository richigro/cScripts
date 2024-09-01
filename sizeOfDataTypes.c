/*
 *This is used to tell me what are the sizes of each data type
 * this is specific to where the program is ran.
 * Depends on the architecture of the machine
 */
#include <stdio.h>

int main()
{

  printf("the size of an int is: %lu bytes or %lu bits\n", sizeof(int), sizeof(int) * 8);
  printf("the size of an short is: %lu bytes or %lu bits\n", sizeof(short), sizeof(short) * 8);
  printf("the size of an double is: %lu bytes or %lu bits\n", sizeof(double), sizeof(double) * 8);
  printf("the size of an long is: %lu bytes or %lu bits\n", sizeof(long), sizeof(long) * 8);
  printf("the size of an float is: %lu bytes or %lu bits\n", sizeof(float), sizeof(float) * 8);
  printf("the size of an char is: %lu bytes or %lu bits\n", sizeof(char), sizeof(char) * 8);

  return 0;
}