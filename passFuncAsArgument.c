#include <stdio.h>
#include <string.h>

int NUM_ADS = 7;

char *ADS[] = {
    "Williams: sports",
    "Matt: movies, art, smoking",
    "Luis: art, working out, dinning",
    "Mike: bieber, theater",
    "Peter: working out, books, dinning",
    "Josh: sports, smoking",
    "Jed: books, movies"};

int sports_no_bieber(char *s)
{
  return strstr(s, "sports") && !strstr(s, "bieber");
}

int sports_or_workout(char *s)
{
  return strstr(s, "sports") || strstr(s, "working out");
}

int ns_theather(char *s)
{
  return !strstr(s, "smoking") && strstr(s, "theater");
}

int arts_theater_or_dinning(char *s)
{
  return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dinning");
}

void find(int (*match)(char *))
{
  puts("Search Results: \n");
  puts("Looking for a match\n");

  for (int i = 0; i < NUM_ADS; i++)
  {
    if (match(ADS[i]))
    {
      printf("%s\n", ADS[i]);
    }
  }
}

int main()
{
  puts("============================");
  find(sports_no_bieber);
  puts("============================");
  find(sports_or_workout);
  puts("============================");
  find(ns_theather);
  puts("============================");
  find(arts_theater_or_dinning);
  puts("============================");

  puts("finished\n");

  return 0;
}