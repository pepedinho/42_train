#include "../include/libft.h"
//change les caractère alphabetique majuscule d'une chaine en minuscule
char *ft_strlowcase(char *str)
{
  int i = 0;

  while (i < ft_strlen(str))
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      str[i] = str[i];
      i++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i] + 32;
      i++;
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
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