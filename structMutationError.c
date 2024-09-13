#include <stdio.h>

typedef struct
{
  const char *name;
  const char *species;
  int age;
} turtle;

void happy_birthday(turtle *t)
{
  // increase its age by 1
  // this create a copy of myrtle that is one year older!
  // we want to increase the age of the original myrtle
  // t.age = t.age + 1; // by value this is wrong
  // (*t).age = (*t).age + 1; // this is correct
  t->age = t->age + 1; // this is correct too but a simpler notation
  // printf("Happy Birthday %s! You are now %i years old!\n", (*t).name, (*t).age); // this is correct
  printf("Happy Birthday %s! You are now %i years old!\n", t->name, t->age); // simpler notation
}

int main()
{
  turtle myrtle = {"Myrtle", "Land Turtle", 99};

  happy_birthday(&myrtle);
  printf("%s's age is now %i\n", myrtle.name, myrtle.age);

  return 0;
}