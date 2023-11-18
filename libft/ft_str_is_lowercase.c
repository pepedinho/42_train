#include "ft_str_is_lowercase.h"
#include "ft_strlen.h"
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
            printf("car : %c, i : %d\n", str[i], i);
            return 0;
        }
    }
}
