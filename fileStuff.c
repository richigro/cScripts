/*
  This program will allow you to read in a file
*/
#include <stdio.h>

int main()
{
  char text[80];
  // Read from file
  FILE *in_file = fopen("test.txt", "r");

  // Display the text inside of this file.
  fprintf(in_file, "%79[^\n]", text);

  return 0;
}