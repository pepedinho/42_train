#include "../include/libft.h"
// divise a et b, stock le resultat dans la var a,et le reste dans la var b
void ft_ultimate_div_mod(int *a, int *b)
{
  int na = *a;
  int nb = *b;
  *a = na / nb;
  *b = na % nb;
}