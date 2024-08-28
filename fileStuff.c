/*
  This program will allow you to read in a file
*/
#include <stdio.h>

int main()
{
  char buffer[256];
  // Read from file
  FILE *in_file = fopen("test.txt", "r");

  // Display the text inside of this file.
  fprintf(in_file, "%79[^\n]", buffer);

  if (in_file == NULL)
  {
    fprintf(stderr, "Error: could not open file.\n");
    return 1;
  }

  // fgets(buffer, sizeof(buffer), in_file);
  printf("the line of text is: %s", buffer);

  return 0;
}