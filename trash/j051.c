#include <stdlib.h>
#include <stdio.h>
#include "ft_lib.h"

int ft_str_is_numeric(char *str)
{
    int i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            i++;
        }
        else if (i >= ft_strlen(str))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int ft_str_is_lowercase(char *str)
{
    int i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            i++;
        }
        else if (i >= ft_strlen(str))
        {
            return 1;
        }
        else
        {
            printf("car : %c, i : %d\n", str[i], i);
            return 0;
        }
    }
}

int ft_str_is_uppercase(char *str)
{
    int i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            i++;
        }
        else if (i >= ft_strlen(str))
        {
            return 1;
        }
        else
        {
            printf("car : %c, i : %d\n", str[i], i);
            return 0;
        }
    }
}

int ft_str_is_printable(char *str)
{
    int i = 0;

    while (i < ft_strlen(str))
    {
        if (str[i] >= 32 && str[i] <= 126)
        {
            i++;
        }
        else if (i >= ft_strlen(str))
        {
            return 1;
        }
        else
        {
            printf("car : %c, i : %d\n", str[i], i);
            return 0;
        }
    }
}

char *ft_strcat(char *dest, char *src)
{
    int i = 0;
    int len = ft_strlen(dest);
    while (src[i] != '\0')
    {
        dest[(i + 1) + len] = src[i];
        i++;
    }

    dest[(len + i) + 1] = '\0';

    return dest;
}

char *ft_strncat(char *dest, char *src, int nb)
{
    int i = 0;
    int len = ft_strlen(dest);
    while (i < nb)
    {
        dest[(i + 1) + len] = src[i];
        i++;
    }

    dest[(len + i) + 1] = '\0';

    return dest;
}

char *ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int dest_len = ft_strlen(dest);
    unsigned int src_len = ft_strlen(src);

    if (size <= dest_len)
        return dest;

    unsigned int copy_len = size - dest_len - 1;
    ft_strncat(dest + dest_len, src, copy_len);

    dest[dest_len + copy_len] = '\0';

    return dest;
}

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;
    while (i < ft_strlen(src))
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

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
    dest[i] = '\0';

    return dest;
}

void ft_putnbr_base(int nbr, char *base)
{

    char result[32];
    int index = 0;

    while (nbr > 0)
    {
        if (ft_strcmp(base, "0123456789ABCDEF") == 0)
        {
            int remainder = (nbr % 16);
            result[index] = "0123456789ABCDEF"[remainder];
            nbr /= 16;
            index++;
        }
        else if (ft_strcmp(base, "01") == 0)
        {
            int remainder = nbr % 2;
            result[index] = "01"[remainder];
            nbr /= 2;
            index++;
        }
        else if (ft_strcmp(base, "poneyvif") == 0)
        {
            int remainder = nbr % 8;
            result[index] = "01234567"[remainder];
            nbr /= 8;
            index++;
        }
        else
        {
            printf("");
        }
        }

    int i = index - 1;
    while (i >= 0)
    {
        printf("%c", result[i]);
        i--;
    }

    printf("\n");
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int i = 0;
    unsigned int dest_len = ft_strlen(dest);
    unsigned int src_len = ft_strlen(src);

    int decimalNumber = 1893137;
    char hex[] = "0123456789ABCDEF";

    ft_putnbr_base(decimalNumber, hex);

    if (size == 0)
    {
        return src_len;
    }

    unsigned int copy_len = (size > dest_len) ? size - dest_len - 1 : 0;

    while (i < size - 1)
    {
        if (i < copy_len && src[i] != '\0')
        {
            dest[i + dest_len] = src[i];
        }
        else
        {
            dest[i + dest_len] = '\0';
        }
        i++;
    }

    dest[i] = '\0';

    return src_len;
}

int main(int argc, char const *argv[])
{
    char test[] = "World !";
    char test2[100] = "Hello, ";

    ft_strlcpy(test2, test, sizeof(test2));

    printf("resultat : %s\n", test2);

    int result = ft_str_is_printable(test);
    int res = ft_str_is_lowercase(test);

    if (result != 0)
        printf("la chaine est imprimable : %s\n", test);
    else
        printf("la chaine n'est pas imprimable : %s\n", test);

    if (res != 0)
        printf("la chaine ne contient que des minuscules\n");
    else
        printf("la chaine ne contient pas que des minuscules\n");
    return 0;
}
