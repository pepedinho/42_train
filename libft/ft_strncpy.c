#include "ft_strncpy.h"
//fonction qui copy une chaine de caractère dans une autre jusqu'a n caractère
char *ft_strncpy(char *dest, char *src, int size)
{
  int i = 0;

  while (i < size)
  {
    dest[i] = src[i];
    i++;
  }
  return dest;
}