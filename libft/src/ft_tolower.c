#include "../include/libft.h"

int ft_tolower(int car)
{
  if (isupper(car))
  {
    return car + 32;
  }
}