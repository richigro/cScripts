/*
  This code will read a spooky_locations.csv file
  and categorize the type of creature located at that specific location.
  here is what a row should look like:
  29.024025,-75.149117,Type=Hydra

  Example usage:
  $ ./main Hydra hydras_location.csv Troll trolls_locations.csv rest_creature_locations.csv

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  char line[80];

  if (argc != 6)
  {
    fprintf(stderr, "You need to give 5 arguments\n");
    puts("Example: ./main Hydra hydras_location.csv Troll trolls_locations.csv rest_creature_locations.csv\n");
    return 1;
  }

  FILE *in = fopen("spooky_locations.csv", "r");
  FILE *file1 = fopen(argv[2], "w");
  FILE *file2 = fopen(argv[4], "w");
  FILE *file3 = fopen(argv[5], "w");

  if (in == NULL)
  {
    fprintf(stderr, "You need to have a file named spooky_locations.csv to run this program.\n");
    return 1;
  }

  while (fscanf(in, "%79[^\n]\n", line) == 1)
  {
    if (strstr(line, argv[1]))
      fprintf(file1, "%s\n", line);
    else if (strstr(line, argv[3]))
      fprintf(file2, "%s\n", line);
    else
      fprintf(file3, "%s\n", line);
  }

  fclose(file1);
  fclose(file2);
  fclose(file3);
  return 0;
}