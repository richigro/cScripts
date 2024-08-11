/*
 * simple test program
 */

#include <stdio.h>

int value_in_array(char val, char *arr, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (arr[i] == val)
    {
      return 1;
    }
  }

  return 0;
}

// Declaration of atoi neede to remove compiler warning
int atoi(const char *str);

int main()
{
  char value_ten_cards[] = {'K', 'Q', 'J'};
  char card_name[3];
  int count = 0;

  while (card_name[0] != 'X')
  {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    char card_value = card_name[0];
    int val = 0;

    if (value_in_array(card_value, &value_ten_cards, sizeof(value_ten_cards)))
    {
      val = 10;
    }
    else if (card_value == 'A')
    {
      val = 11;
    }
    else
    {
      val = atoi(card_name);
    }
    if (val < 1 || val > 10)
    {
      puts("I don't understand that value!");
      continue;
    }

    // Check if the value is between 3 to 6
    if (val >= 3 && val <= 6)
    {
      count++;
    }
    else if (val == 10)
    {
      count--;
    }
    printf("Current count: %i\n", count);
  }

  return 0;
}