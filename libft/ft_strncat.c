#include "ft_strncat.h"
#include "ft_strlen.h"
//La fonction ft_strncat concatène les nb premiers caractères de la chaîne src à la fin de la chaîne dest. 
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
