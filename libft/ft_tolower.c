#include "ft_tolower.h"
#include "ft_isupper.h"

int ft_tolower(int car)
{
  if (isupper(car))
  {
    return car + 32;
  }
}