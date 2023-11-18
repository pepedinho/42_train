

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
void ft_putnbr(int nb)
{
  printf("%d\n", nb);
}

char *ft_strcpy(char *dest, char *src)
{
  int i = 0;
  while (i < strlen(src))
  {
    dest[i] = src[i];
    i++;
  }

  return dest;
}

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

int ft_str_is_alpha(char *str)
{
  int i = 0;
  int j = 1;

  while (i < strlen(str))
  {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
    {
      i++;
    }
    else if (str[i] == ' ')
    {
      while (j < strlen(str))
      {
        if (str[j] == ' ')
          j++;
        else
          return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  return 1;
}

char *ft_strstr(char *str, char *to_find)
{
  int i = 0;
  int len = strlen(str);
  int len_to_find = strlen(to_find);
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

int ft_strcpm(char *s1, char *s2)
{
  int i = 0;
  int len1 = strlen(s1);
  int len2 = strlen(s2);

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

char *ft_strupcase(char *str)
{
  int i = 0;

  while (i < strlen(str))
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      str[i] = str[i];
      i++;
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i] - 32;
      i++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i];
      i++;
    }
    else
    {
      str[i] = str[i];
      i++;
    }
  }

  return str;
}

char *ft_strlowcase(char *str)
{
  int i = 0;

  while (i < strlen(str))
  {
    if (str[i] >= '0' && str[i] <= '9')
    {
      str[i] = str[i];
      i++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z')
    {
      str[i] = str[i] + 32;
      i++;
    }
    else if (str[i] >= 'a' && str[i] <= 'z')
    {
      str[i] = str[i];
      i++;
    }
    else
    {
      str[i] = str[i];
      i++;
    }
  }

  return str;
}

char *ft_strcapitalize(char *str)
{
  int i = 0;

  while (i < strlen(str))
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

int main(int argc, char *argv[])
{

  char src[] = "Test42";
  char test[] = "Test32";
  int num = ft_str_is_alpha(src);

  if (num == 1)
    printf("le text contient que des carcter alphabetique : %d\n", num);
  else
    printf("le texte ne contient pas  que des carcter alphabetique : %d\n", num);

  printf("result upper : %s\n", ft_strcapitalize(src));

  int res = ft_strncmp(src, test, 5);

  if (res == 0)
    printf("ce sont les meme chaines\n");
  else if (res < 0)
    printf("la chaine src est plus petite\n");
  else
    printf("la chaine src est plus grande\n");

  char *dest = (char *)malloc(strlen(src) + 1);
  ft_strncpy(dest, src, 10);

  char *result = ft_strstr(src, "est");

  if (result)
    printf("Sous chaine trouvé : %s\n", result);
  else
    printf("Sous chaine non trouvé\n");

  printf("src = %s\n", src);
  printf("dest = %s\n", dest);

  return 0;
}
