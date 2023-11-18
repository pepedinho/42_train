#include "ft_atoi.h"

// fonction qui converti des chiffre char en int
int ft_atoi(char *str)
{
  int result = 0;

  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      result = result * 10 + (str[i] - '0');
    }
  }

  return result;
}