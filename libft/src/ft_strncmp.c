#include "../include/libft.h"

// fonction qui compare une chaine de caractère jusqua n caractère
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
  int i = 0;

  while (i < n)
  {
    if (s1[i] == s2[i])
      i++;
    else if (s1[i] < s2[i])
      return -1;
    else if (s1[i] > s2[i])
      return 1;
  }

  return 0;
}
