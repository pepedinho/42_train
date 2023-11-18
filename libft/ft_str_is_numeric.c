#include "ft_str_is_numeric.h"
#include "ft_strlen.h"

//La fonction renvoie 1 si tous les caractères de la chaîne sont des chiffres, sinon elle renvoie 0.
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