#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_fibonacci(int index)
{
  if (index < 0)
    return -1;
  else if (index == 0)
    return 0;
  else if (index == 1)
    return 1;
  else
  {
    int a = 0;
    int b = 1;
    int fib = 0;
    int i = 2;

    while(i <= index)
    {
      fib = a + b; 
      a = b;
      b = fib;
      i++;
    }
    return fib;
  }
}


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
    //printf("nest : %f\n", nest);
    //printf("est : %f\n", est);
  }while (est != tempEst);
  
  int intNest = (int)nest;
  float mod = nest - intNest;
  //printf("mod : %f\n", mod);
  
  if (mod < 0.00001)
  {
    return intNest;
  }
  else{
    return 0; 
  }
}


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

int main(int argc, char* argv[])
{
  int index = 20; 
  int i = 0;
  
  while (i < index) {   
    printf("%lld\n", (long long)ft_fibonacci(i));
    i++;
  }

  i = 0;
  while (i != 30) {

    if (ft_sqrt(i) != 0) 
    {
      printf("\nracine carré de %d : %d\n", i, ft_sqrt(i));
    };
    i++;
  }
  
  int sample = 17;

  if (ft_is_prime(sample) == 1)
    printf("%d est un nombre premier\n", sample);
  else
    printf("%d n'est pas un nombre premier\n", sample);

  printf("le nombre premier qui suit %d , est %d\n", sample, ft_find_next_prime(sample));

  return 0;
}
