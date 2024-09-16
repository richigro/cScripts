/*
  This program has an intentional memory leak, that is not really obvious.
  the purpose of this program is to use it to learn how to use valgrind, which
  is a linux tool design to help you identify memoy leaks in your c programs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  char *question;
  struct node *no;
  struct node *yes;
} node;

int yes_no(char *question)
{
  char answer[3];
  printf("%s? (y/n): ", question);
  fgets(answer, 3, stdin);

  return answer[0] == 'y';
}

node *create(char *question)
{
  node *n = malloc(sizeof(node));
  n->question = strdup(question);
  n->no = NULL;
  n->yes = NULL;

  return n;
}

void release(node *node)
{
  if (node)
  {
    if (node->no)
      release(node->no);
    if (node->yes)
      release(node->yes);
    if (node->question)
      free(node->question);
    free(node);
  }
}

int main()
{
  char question[80];
  char suspect[20];
  node *start_node = create("Does suspect have a mustache");
  start_node->no = create("Loretta Barnsworth");
  start_node->yes = create("Vinny the Spoon");

  node *current;

  do
  {
    current = start_node;
    while (1)
    {
      if (yes_no(current->question))
      {
        if (current->yes)
        {
          current = current->yes;
        }
        else
        {
          printf("SUSPECT IDENTIFIED\n");
          break;
        }
      }
      else if (current->no)
      {
        current = current->no;
      }
      else
      {
        /* Make the no-node a copy of this question */
        printf("Who's the suspect? ");
        fgets(suspect, 20, stdin);
        node *yes_node = create(suspect);
        current->yes = yes_node;

        /* Make the no-node a copy of this question */
        node *no_node = create(current->question);
        current->no = no_node;

        /* Then replace this question with the new question */
        printf("Give me a question that is TRUE for %s but not for %s? ", suspect, current->question);
        fgets(question, 80, stdin);
        current->question = strdup(question);

        break;
      }
    }

  } while (yes_no("Run again"));

  release(start_node);

  return 0;
}