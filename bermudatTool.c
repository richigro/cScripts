/*
  This small tool can take in any coordinates provided to its standard input
  and it will return the gps data latitude and longituede that fall within the
  bermuda rectangle
*/
#include <stdio.h>

int main()
{
  float latitude;
  float longitude;
  char info[80];

  while (scanf("%f,%f,%79[^\n]", &latitude, &longitude, info) == 3)
    if ((latitude > 26.0) && (latitude < 34.0))
      if ((longitude > -76.0) && (longitude < -64.0))
        printf("%f,%f,%s\n", latitude, longitude, info);

  return 0;
}