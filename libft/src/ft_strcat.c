#include "../include/libft.h"
//concatène la chaine src a la fin de la chaine dest
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
