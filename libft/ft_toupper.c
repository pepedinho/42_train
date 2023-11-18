#include "ft_toupper.h"
#include "ft_islower.h"

int ft_toupper(int car)
{
  if (ft_islower(car))
  {
    return car - 32;
  }
}