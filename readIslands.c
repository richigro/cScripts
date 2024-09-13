#include <stdio.h>

int main()
{
  char line[256];
  FILE *islandsFile = fopen("islands.txt", "r");

  if (islandsFile == NULL)
  {
    fprintf(stderr, "Error opening file.\n");

    return -1;
  }

  printf("Successfully opened file.\n");

  while (fgets(line, 256, islandsFile))
  {
    printf("Current line: %s", line);
  }

  fclose(islandsFile);

  return 0;
}