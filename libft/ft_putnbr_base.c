#include "ft_putnbr_base.h"
#include "ft_strcmp.h"
#include <unistd.h>

//La fonction convertit un nombre entier en une représentation dans une base donnée et l'affiche à l'écran.
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
            write(1, " ", 1);
        }
        }

    int i = index - 1;
    while (i >= 0)
    {
        write(1, &result[i], 1);
        i--;
    }

    write(1, "\n", 1);
}