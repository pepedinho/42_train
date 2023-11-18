#include "ft_strstr.h"
#include "ft_strlen.h"
#include <stdlib.h>

//cherche un chaine de carcater dans une autre et retourne la chaine trouvé sinon renvoie une chaine vide
char *ft_strstr(char *str, char *to_find)
{
  int i = 0;
  int len = ft_strlen(str);
  int len_to_find = ft_strlen(to_find);
  char *result = (char *)malloc(len_to_find + 1);
  while (i < len)
  {
    if (str[i] == to_find[0])
    {
      int j = 1;
      result[0] = str[i];
      i++;
      while (j < len_to_find)
      {
        if (str[i] == to_find[j])
        {
          result[j] = str[i];
        }
        else
          return 0;
        i++;
        j++;
      }
    }
    i++;
  }
  return result;
}
