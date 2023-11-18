#include "ft_swap.h"

// fait passer la valeur de a dans b et b dans a
void ft_swap(int *a, int *b)
{
  int na = *b;
  int nb = *a;

  *a = na;
  *b = nb;
}