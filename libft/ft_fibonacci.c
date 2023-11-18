#include "ft_fibonacci.h"

//fonction qui donne la suite de fibonacci pour un index donné index = 4 => 0,1,1,2,3,5,8,13,21,34,55,89,144
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