#include "../include/libft.h"
// fonction que compare deux chaine de caractère et retourne 1 si s1 > s2, -1 si s1 < s2, 0 si s1 == s2
int ft_strcmp(char *s1, char *s2)
{
  int i = 0;
  int len1 = ft_strlen(s1);

  while (i < len1)
  {
    if (s1[i] == s2[i])
      i++;
    else if (s1[i] < s2[i])
    {
      return -1;
    }
    else if (s1[i] > s2[i])
    {
      return 1;
    }
  }
  return 0;
}
