#include "../include/libft.h"

//fonction qui renvoie la racine carré du nombre passer en paramètre
int ft_sqrt(int nb)
{

  if (nb < 0)
    return 0;

  if (nb == 0)
    return 0;
  if (nb == 1)
    return 1;


  float est = nb / 2.0;
  float nest = 0.0;
  float tempEst = 0.0;

  do {
    tempEst = nest;
    nest = (est + (nb / est)) / 2;
    est = nest;
  }while (est != tempEst);
  
  int intNest = (int)nest;
  float mod = nest - intNest;
  
  if (mod < 0.00001)
  {
    return intNest;
  }
  else{
    return 0; 
  }
}
