#include <stdio.h>

struct preferences
{
  const char *food;
  float exercise_hours;
};

struct fish
{
  const char *name;
  const char *species;
  int teeth;
  int age;
  struct preferences care;
};

void catalog(struct fish f)
{
  printf("%s is a %s with %i teeth, and he is %i years old.\n", f.name, f.species, f.teeth, f.age);
};

void label(struct fish f)
{
  printf("Name: %s\nSpecies: %s\nTeeth: %i\nAge: %i\n", f.name, f.species, f.teeth, f.age);
};

void care(struct fish f)
{
  printf("%s likes to eat %s, and usually exercises around %.1f hours.", f.name, f.care.food, f.care.exercise_hours);
};

int main()
{
  struct fish nemo = {"Nemo", "Clown Fish", 5, 3, {"Baby sharks", 1.2}};
  catalog(nemo);
  label(nemo);
  care(nemo);

  return 0;
}