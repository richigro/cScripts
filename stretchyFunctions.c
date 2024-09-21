/*
  Topic: Creating functions that can take a varying number of arguments.
  variadic function
*/
#include <stdio.h>
// module to handle variadic functions
#include <stdarg.h>

enum drink
{
  MUDSLIDE,
  FUZZY_NAVEL,
  MONKEY_GLAND,
  ZOMBIE
};

void print_ints(int args, ...)
{

  // va_list is used to store the extra arguments passed to the function
  va_list ap;

  va_start(ap, args);

  int i;
  for (i = 0; i < args; i++)
  {
    // takes in the list of arguments and their type
    printf("arguments: %i\n", va_arg(ap, int));
  }
  // end the list
  va_end(ap);
}

double price(enum drink d)
{
  switch (d)
  {
  case MUDSLIDE:
    return 6.79;
  case FUZZY_NAVEL:
    return 5.31;
  case MONKEY_GLAND:
    return 4.82;
  case ZOMBIE:
    return 5.89;
  default:
    return 0;
  }
}

double total(int args, ...)
{
  va_list ap;
  va_start(ap, args);

  int i;
  double total = 0;
  for (i = 0; i < args; i++)
  {
    // get the current argument
    enum drink currentDrink = va_arg(ap, int);
    // get price of the drink
    double priceOfCurrentDrink = price(currentDrink);
    // print the current price
    printf("current price of the drink: %.2f\n", priceOfCurrentDrink);
    // add the price to the total amount
    total += priceOfCurrentDrink;
  }

  return total;
}

int main()
{
  // print_ints(3, 79, 101, 32);
  puts("============================\n");
  // print_ints(45, 2); // this call is broken on purpose, because we are telling
  // our varidic function to expect 45 arguments but we only pass in one besides the number of arguments.

  double totalPrice = total(3, MONKEY_GLAND, FUZZY_NAVEL, ZOMBIE);

  printf("The total amount for all drinks is: %.2f\n", totalPrice);

  return 0;
}