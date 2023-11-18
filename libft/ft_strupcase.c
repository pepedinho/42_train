#include "ft_strupcase.h"

//change les caractère alphabetique minuscule d'une chaine en majuscule
char *ft_strupcase(char *str)
{
  int i = 0;

  while (i < ft_strlen(str))
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      str[i] = str[i];
      i++;
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
      i++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i];
      i++;
    }
    else
    {
      str[i] = str[i];
      i++;
    }
  }

  return str;
}