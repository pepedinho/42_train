#include "ft_strrev.h"
#include "ft_strlen.h"
#include <stdlib.h>

// fonction qui inverse une chaine de caractère abc => cba
char *ft_strrev(char *str)
{
  int len = ft_strlen(str);
  char *nstr = (char *)malloc(len + 1);
  if (nstr == 0)
    exit(1);

  int j = 0;

  for (int i = len; i >= 0; i--)
  {
    nstr[j] = str[i];
    j++;
  }

  nstr[j] = '\0';

  return nstr;
}
