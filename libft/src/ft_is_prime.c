#include "../include/libft.h"
//fonction qui indique si le nombre passer en paramètre est un nombre premier 
int ft_is_prime(int nb)
{
  if (nb == 0 ||nb == 1)
    return 0;
  float divnb = nb / nb;
  int intDivnb = (int)divnb;
  float mod = divnb - intDivnb;
  int i = 2;

  while(i < nb)
  {
    divnb = (float)nb / i;
    intDivnb = (int)divnb;
    mod = divnb - intDivnb;
    i++;
    if (mod < 0.0000001)
    {
      return 0;
      break;
    }
  }
  return 1;
}