#include "ft_str_is_alpha.h"
#include "ft_strlen.h"

// fonction qui verifie si la chaine de caractère contient que des caractère alphabetique et retourne 1 si c'est le cas sinon 0
int ft_str_is_alpha(char *str)
{
  int i = 0;
  int j = 1;

  while (i < ft_strlen(str))
  {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
    {
      i++;
    }
    else if (str[i] == ' ')
    {
      while (j < ft_strlen(str))
      {
        if (str[j] == ' ')
          j++;
        else
          return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return 1;
}
