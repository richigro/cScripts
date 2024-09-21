#include <stdio.h>
#include <stdlib.h>

int compare_scores_desc(const void *score_a, const void *score_b)
{
  int a = *(int *)score_a;
  int b = *(int *)score_b;

  return b - a;
}

int least_to_greatest(const void *score_a, const void *score_b)
{

  // cast to their actual value
  int a = *(int *)score_a;
  int b = *(int *)score_b;

  // will return positive if a is greater than b, negative if b is greater than a,
  // or 0 if both are equal
  return a - b;
}

int main()
{
  int scores[] = {543, 323, 32, 554, 11, 3, 112};

  size_t sizeOfArr = sizeof(scores) / sizeof(scores[0]);

  qsort(scores, sizeOfArr, sizeof(scores[0]), compare_scores_desc);

  // Loop through array and print numbers in order
  for (int i = 0; i < sizeOfArr; i++)
  {
    printf("%i\n", scores[i]);
  }
  return 0;
}