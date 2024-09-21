/*
  creating an array of function pointers.
  When creating an enum, c will give each of the symbols a number starting at 0.
  So DUMP = 0, Second_Chance = 1, and Marriage =2 and so on.
  This is really helpful because it allow us to pass the enum as the index for
  the array of pointer functions, so that depending on the response type a different
  function will ran thus reducing the amount of code written in advanceFunctionsPart1

  This will reduce the amount of code significantly specially when new functions are added.
  Because we no longer need to manage a long swith statement.
*/
#include <stdio.h>

enum response_type
{
  DUMP,
  SECOND_CHANCE,
  MARRIAGE
};
typedef struct
{
  char *name;
  enum response_type type;
} response;

void dump(response r)
{
  printf("Dear %s,\n", r.name);
  puts("Unfortunately your last date contacted us to");
  puts("say that they will not be seeing you again\n");
}

void second_chance(response r)
{
  printf("Dear %s,\n", r.name);
  puts("Good news: your last date has asked us to");
  puts("arrange another meeting. Please call ASAP.\n");
}

void marriage(response r)
{
  printf("Dear %s,\n", r.name);
  puts("Congratulations! Your last date has contancted");
  puts("use with a proposal of marriage.\n");
}

// this is an array of functions
// void means the functions don't return anything
// *replies[] means is a pointer to function arrays.
// and (reponse) means is the argument that all the functions take
void (*replies[])(response) = {dump, second_chance, marriage};

int main()
{

  response r[] = {{"Mike", DUMP}, {"Luis", SECOND_CHANCE}, {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}};

  int i;
  for (i = 0; i < 4; i++)
  {
    response currentResponse = r[i];
    replies[currentResponse.type](currentResponse);
  }

  return 0;
}