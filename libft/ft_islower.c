#include "ft_islower.h"

int ft_islower(int car)
{
  if (car >= 'a' && car <= 'z')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}