#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_lib.h"

void ft_putstr(char *str)
{
  int len = strlen(str);

  for (int i = 0; i < len; i++)
  {
    printf("%c\n", str[i]);
  }
}

int ft_strlen(char *str)
{
  int len = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == '\0')
    {
      break;
    }
    len = i;
  }

  return len;
}

int isupper(int car)
{
  if (car >= 'A' && car <= 'Z')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int islower(int car)
{
  if (car >= 'a' && car <= 'z')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int toupper(int car)
{
  if (islower(car))
  {
    return car - 32;
  }
}

int tolower(int car)
{
  if (isupper(car))
  {
    return car + 32;
  }
}

void ulstr(char *str)
{
  char upcar[100];

  for (int i = 0; i < ft_strlen(str); i++)
  {
    upcar[i] = islower(str[i]) ? toupper(str[i]) : tolower(str[i]);
  };

  upcar[ft_strlen(str)] = '\0';

  printf("%s\n", upcar);
}

// fait passer la valeur de a dans b et b dans a
void ft_swap(int *a, int *b)
{
  int na = *b;
  int nb = *a;

  *a = na;
  *b = nb;
}

// divise a et b, stock le resultat dans la var div,et le reste dans la var mod
void ft_div_mod(int a, int b, int *div, int *mod)
{
  *div = a / b;
  *mod = a % b;
}

void ft_ultimate_div_mod(int *a, int *b)
{
  int na = *a;
  int nb = *b;
  *a = na / nb;
  *b = na % nb;
}

char *ft_strrev(char *str)
{
  int len = ft_strlen(str);
  char *nstr = (char *)malloc(len + 1);
  if (nstr == NULL)
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

// fonction qui converti des chiffre char en int
int ft_atoi(char *str)
{
  int len = ft_strlen(str);
  char *number = (char *)malloc(len + 1);
  int result = 0;
  int j = 0;

  for (int i = 0; i != len + 1; i++)
  {
    if (str[i] >= 48 && str[i] <= 57)
    {
      number[i] = str[i];
    }
  }

  number[ft_strlen(number + 1)] = '\0';

  for (int i = 0; i <= len; i++)
  {
    switch (number[i])
    {
    case ('0'):
      result = result * 10;
      break;
    case ('1'):
      result = result * 10 + 1;
      break;
    case ('2'):
      result = result * 10 + 2;
      break;
    case ('3'):
      result = result * 10 + 3;
      break;
    case ('4'):
      result = result * 10 + 4;
      break;
    case ('5'):
      result = result * 10 + 5;
      break;
    case ('6'):
      result = result * 10 + 6;
      break;
    case ('7'):
      result = result * 10 + 7;
      break;
    case ('8'):
      result = result * 10 + 8;
      break;
    case ('9'):
      result = result * 10 + 9;
      break;
    default:
      break;
    }
  }

  return result;
}

void ft_sort_integer_table(int *tab, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (tab[i] > tab[j])
      {
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
      }
    }
  }
}

int ft_itterative_factorial(int nb)
{

  if (nb == 0)
    return 0;

  int result = nb;
  for (int i = nb - 1; i > 0; i--)
  {
    result *= i;
  }

  return result;
}

int ft_strcmp(char *s1, char *s2)
{
  int i = 0;
  int len1 = ft_strlen(s1);
  int len2 = ft_strlen(s2);

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

/*
int main(int argc, char *argv[])
{
  char str[100];
  char mot[100];
  char *test = "test20376";
  int tab[4] = {2, 4, 3, 1};
  int facto = 30;

  printf("facto de 5 : %d\n", ft_itterative_factorial(facto));

  for (int i = 0; i < 4; i++)
  {
    printf("tab : %d, ", tab[i]);
  }
  printf("\n");
  ft_sort_integer_table(tab, 4);
  for (int i = 0; i < 4; i++)
  {
    printf("new tab : %d, ", tab[i]);
  }

  printf("\n");

  int atoi = ft_atoi(test);

  printf("%d\n", atoi);
  printf("atoi * 10 : %d\n", atoi * 10);

  printf("\n-----------------------------\n");

  char *result = ft_strrev(test);

  printf("%s\n", result);

  free(result);

  int a = 10;
  int b = 3;
  int *div, *mod;

  div = malloc(sizeof(int));
  mod = malloc(sizeof(int));

  printf("a = %d, b = %d\n", a, b);
  ft_ultimate_div_mod(&a, &b);
  printf("a = %d, a = %d\n", a, b);

  printf("\n--------------------------------------------\n");

  printf("a = %d, b = %d\n", a, b);
  ft_div_mod(a, b, div, mod);
  printf("div = %d, mod = %d\n", *div, *mod);

  printf("a = %d, b = %d\n", a, b);

  ft_swap(&a, &b);

  printf("a = %d, b = %d\n", a, b);

  printf("Entré un mot :");
  fgets(mot, sizeof(mot), stdin);
  ulstr(mot);

  printf("Entré un mot : ");

  fgets(mot, sizeof(mot), stdin);

  printf("le mot contient %d caractères\n", ft_strlen(mot));

  printf("Entré un mot ou une phrase : ");
  fgets(str, sizeof(str), stdin);

  ft_putstr(str);

  return 0;
}
*/