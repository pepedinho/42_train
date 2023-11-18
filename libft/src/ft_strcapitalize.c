#include "../include/libft.h"

//met en majuscule la premiere lettre de chaque mot
char *ft_strcapitalize(char *str)
{
  int i = 0;

  while (i < ft_strlen(str))
  {
    if (str[i] == ' ' && str[i + 1] >= 'a' && str[i] <= 'z')
    {
      if (str[i + 1] >= 'a' && str[i] <= 'z')
      {
        str[i + 1] = str[i + 1] - 32;
        i++;
      }
      else if (str[i + 1] >= 'A' && str[i + 1] <= 'Z')
      {
        str[i + 1] = str[i + 1];
        i++;
      }
      else
      {
        str[i + 1] = str[i + 1];
        i++;
      }
    }
    i++;
  }

  return str;
}