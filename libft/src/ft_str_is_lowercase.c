#include "../include/libft.h"
#include <unistd.h>
//La fonction renvoie 1 si tous les caractères de la chaîne sont des minuscules, sinon elle renvoie 0.
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
            return 0;
        }
    }
    return 0;
}
