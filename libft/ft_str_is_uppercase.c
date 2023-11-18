#include "ft_str_is_uppercase.h"
#include "ft_strlen.h"
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
