#include "ft_ulstr.h"
#include "ft_strlen.h"
#include "ft_tolower.h"
#include "ft_toupper.h"
#include "ft_islower.h"
#include <unistd.h>

// fonction qui inverse les majuscule en minuscule et inversement
void ulstr(char *str)
{
  char upcar[100];

  for (int i = 0; i < ft_strlen(str); i++)
  {
    upcar[i] = ft_islower(str[i]) ? ft_toupper(str[i]) : ft_tolower(str[i]);
    write(1, &upcar[i], 1);
  };
    write(1, "\n", 1);
}
