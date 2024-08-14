/*
  Provide a substring to this program to find if its in
  the list of available tracks.

  example: type in: eep
  should result in: Rolling in the Deep - Adele
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *toLowerCase(char *str)
{
  for (int i = 0; i < strlen(str); i++)
  {
    str[i] = tolower(str[i]);
  }
  return str;
}

int main(void)
{
  char searchTerm[79 + 1];
  printf("Please enter the name of a track:\n");
  fgets(searchTerm, sizeof(searchTerm), stdin);

  // remove newline character from the search term
  // this is needed
  int length = strlen(searchTerm);
  if (length > 0 && searchTerm[length - 1] == '\n')
  {
    searchTerm[length - 1] = '\0';
  }

  char tracks[][80] = {
      "Bohemian Rhapsody - Queen",
      "Hotel California - Eagles",
      "Stairway to Heaven - Led Zeppelin",
      "Imagine - John Lennon",
      "Smells Like Teen Spirit - Nirvana",
      "Billie Jean - Michael Jackson",
      "Hey Jude - The Beatles",
      "Sweet Child O' Mine - Guns N' Roses",
      "Shape of You - Ed Sheeran",
      "Rolling in the Deep - Adele"};

  int lengthOfTracks = sizeof(tracks) / sizeof(tracks[0]);

  puts("Looking for track...\n");
  for (int i = 0; i < lengthOfTracks; i++)
  {
    char *trackName = tracks[i];
    char *lowerTrackName = toLowerCase(trackName);
    char *includesSubString = strstr(tracks[i], searchTerm);
    if (includesSubString)
    {
      printf("Found this track: %s", trackName);
      puts("\n");
    }
  }

  puts("done");
  return 0;
}