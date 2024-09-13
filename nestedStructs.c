#include <stdio.h>

typedef struct
{
  const char *description;
  float duration;
} exercise;

typedef struct
{
  const char *ingredients;
  float weight;
} meal;

typedef struct
{
  meal food;
  exercise exercises;
} preferences;

typedef struct
{
  const char *name;
  const char *species;
  int teeth;
  int age;
  preferences care;
} fish;

void categorize(fish f)
{
  printf("Name: %s\nSpecies: %s\nTeeth: %i\nAge: %i\nFavoriteFood: %s\nFood in lbs: %.1f\nExercise routine: %s\nExercise Duration: %.1f\n", f.name, f.species, f.teeth, f.age, f.care.food.ingredients, f.care.food.weight, f.care.exercises.description, f.care.exercises.duration);
}

int main()
{
  fish nemo = {"Nemo", "Clown Fish", 2, 7, {{"baby dolphins", 2.5}, {"escaping from sharks", 3.5}}};
  categorize(nemo);
  return 0;
}
