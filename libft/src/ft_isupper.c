#include "../include/libft.h"

int isupper(int car)
{
  if (car >= 'A' && car <= 'Z')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}