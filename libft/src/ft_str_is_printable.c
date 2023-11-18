#include "../include/libft.h"
#include <unistd.h>
//renvoie 1 si le caractère est imprimable sinon affiche le caractère non imprimable et renvoie 0
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
            char c = str[i];
            write(STDOUT_FILENO, &c, 1);
            return 0;
        }
    }
}