#include "../include/libft.h"

// divise a et b, stock le resultat dans la var div,et le reste dans la var mod
void ft_div_mod(int a, int b, int *div, int *mod)
{
  *div = a / b;
  *mod = a % b;
}
