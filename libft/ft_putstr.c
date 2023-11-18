#include <unistd.h>
#include "ft_putstr.h"
#include "ft_strlen.h"


void ft_putstr(char *str)
{
  int len = ft_strlen(str);

  for (int i = 0; i < len; i++)
  {
    write(1, &str[i], 1);
  }
}