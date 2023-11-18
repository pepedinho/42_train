#include <unistd.h>

//fonction qui affiche un nombre sur la sortie standard en le conertissant en char
void ft_putnbr(int nb)
{
    char minus = '-';
    if (nb < 0)
    {
        write(1, &minus, 1);
    }
    
    char c = nb + '0';
    write(1, &c, 1);
}