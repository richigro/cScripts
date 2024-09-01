/*
 *This is used to tell me what are the sizes of each data type
 * this is specific to where the program is ran.
 * Depends on the architecture of the machine
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

// Detect OS
#if defined(_WIN32)
#define OS "Operating system: Windows\n"
#elif defined(__linux__)
#define OS "Operating system: Linux\n"
#elif defined(__APPLE__)
#define OS "Operating system: macOS\n"
#else
#define OS "Operating system: Unknown\n"
#endif

int main()
{
  char *os = (OS == NULL) ? "" : OS;

  printf("%s\n", os);

  // Detect Architecture
#if defined(__x86_64__) || defined(_M_X64)
  puts("Architecture: 64-bit (x86_64)\n");
#elif defined(__i386__) || defined(_M_IX86)
  puts("Architecture: 32-bit (x86)\n");
#elif defined(__arm__) || defined(__aarch64__)
  puts("Architecture: ARM\n");
#else
  puts("Architecture: Unknown\n");
#endif

  printf("the size of an char is: %lu byte(s) or %lu bits\n", sizeof(char), sizeof(char) * 8);
  printf("the size of an short is: %lu bytes or %lu bits\n", sizeof(short), sizeof(short) * 8);
  printf("the size of an float is: %lu bytes or %lu bits\n", sizeof(float), sizeof(float) * 8);
  printf("FLT_MAX is: %\n", FLT_MAX);
  printf("FLT_MIN is: %.50f\n", FLT_MIN);
  printf("the size of an int is: %lu bytes or %lu bits\n", sizeof(int), sizeof(int) * 8);
  printf("INT_MAX is: %i\n", INT_MAX);
  printf("INT_MIN is: %i\n", INT_MIN);
  printf("the size of an double is: %lu bytes or %lu bits\n", sizeof(double), sizeof(double) * 8);
  printf("the size of an long is: %lu bytes or %lu bits\n", sizeof(long), sizeof(long) * 8);

  return 0;
}