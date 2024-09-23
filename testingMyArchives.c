/*
  Here is how to compile the file:
  gcc .\testingMyArchives.c -I .\messages\ -L .\messages\ -lhfsecurity -o .\testingMyArchives.exe
  or
  gcc .\testingMyArchives.c -I .\messages\ -lhfsecurity -o .\testingMyArchives.exe

  the difference with the second one is that I've already uploaded the libhfsecurity.a archive file to mingw64/lib
*/

#include <stdio.h>
#include <encrypt.h>
#include <checksum.h>

int main()
{
  char s[] = "Speak friend and enter";
  encrypt(s);
  printf("Encrypted to '%s'\n", s);
  printf("checksum is %i\n", checksum(s));
  encrypt(s);
  printf("Decrypted back to '%s'\n", s);
  printf("Checksum is %i\n", checksum(s));

  return 0;
}