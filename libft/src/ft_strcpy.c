#include "../include/libft.h"

//fonction qui copie une chaine de caractère dans une autre
char *ft_strcpy(char *dest, char *src)
{
  int i = 0;
  while (i < ft_strlen(src))
  {
    dest[i] = src[i];
    i++;
  }

  return dest;
}