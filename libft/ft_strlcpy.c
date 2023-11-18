#include "ft_strlcpy.h"
#include "ft_strlen.h"
#include "ft_putnbr_base.h"

//copie la chaine src dans la chaine dest en verifiant que la chaine dest final ne depaase pas la taille size passer en commentaire
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