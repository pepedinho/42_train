#include "ft_find_next_prime.h"
#include "ft_is_prime.h"

// trouve le nombre premier qui suit le nombre passer en paramètre
int ft_find_next_prime(int nb)
{
  int i = 0;
  int j = 1;

  while(i != 1)
  {
    if(ft_is_prime(nb + j) == 1)
      i = 1;
    j ++;
  }

  return nb + (j - 1);
}
