#include "ft_itterative_factorial.h"
// fonction qui retourne le produit factorial d'un nombre 1234 => 1*2*3*4 = 24
int ft_itterative_factorial(int nb)
{

  if (nb == 0)
    return 0;

  int result = nb;
  for (int i = nb - 1; i > 0; i--)
  {
    result *= i;
  }

  return result;
}
