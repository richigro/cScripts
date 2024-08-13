#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sayGreeting(char *ptr)
{
  // strcpy is needed to assign the string to the pointer
  // no need to return pointer, since the caller of this function
  // alredy has access to it, and can see the string
  strcpy(ptr, "Hello World!");
}

int main(void)
{
  // Allocate memory into the heap
  // malloc allocates enough memory for a string that is 13 characters long
  // (char*) is casting. In this case this is optional.
  // 12 + 1 is the same as just saying 13, but this way we remember
  // that we have to allocate space for the sentinel character \0
  // If we are not careful here we can create a buffer overflow.
  char *str = (char *)malloc(12 + 1 * sizeof(char));

  sayGreeting(str);
  // at this point the str pointer should point to the first
  // character in our greeting which is the letter 'h'
  // and puts should be able to print the whole string
  puts(str);
  // Remove the string from the heap, so that we have more memory available
  // and we don't leak data. this is good practice
  free(str);
  // This ensures the pointer doesn't point to any invalid memory addresses
  // after it has been de-allocated
  str = NULL;
  return 0;
}