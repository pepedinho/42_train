#include "../include/libft.h"

int ft_toupper(int car)
{
  if (ft_islower(car))
  {
    return car - 32;
  }
  return car;
}