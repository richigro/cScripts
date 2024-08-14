/*
  This tools lets you transform, gps test data in the following format:
  92.173,-71.097,Speed = 21
  ...

  and transforms it to a json object
  Usage:
  Run executable or binary like below.
  Make sure gpsData.csv contains the data in the format mentioned above.
  $ ./main < gpsData.csv > output.json
*/

#include <stdio.h>

int main(void)
{
  float latitude;
  float longitude;
  char info[80];
  int started = 0;

  puts("data =[");
  while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
  {
    if (started)
    {
      puts(",\n");
    }
    else
    {
      started = 1;
    }
    // validate that the longitude and lattitude are within their normal ranges
    if (latitude > 90 || latitude < -90 || longitude > 180 || longitude < -180)
    {
      puts("There was a validation error: please check you latitudes and longituedes for values outside of the normal ranges.\n");

      return 2;
    }

    printf("{latitude: %f,longitude: %f, info: '%s'}", latitude, longitude, info);
  }
  puts("\n]");
}