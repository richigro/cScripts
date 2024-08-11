#include <stdio.h>

void go_south_east(int *lat, int *lon)
{
  // decrease lat by 1
  lat -= 1;
  // increase lon by 1
  lon += 1;
  // return new lat and lon
}

int main()
{
  int curr_lat = 0;
  int curr_lon = 0;

  go_south_east(&curr_lat, &curr_lon);

  printf(" The current lat is: %i\n The current lon is: %i ", curr_lat, curr_lon);
}