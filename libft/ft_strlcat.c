#include "ft_strlcat.h"
#include "ft_strlen.h"
#include "ft_strncat.h"
//concatène la chaine src a la fin de la chaine dest en verifiant que la chaine dest final ne depaase pas la taille size passer en commentaire
char *ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int dest_len = ft_strlen(dest);
    unsigned int src_len = ft_strlen(src);

    if (size <= dest_len)
        return dest;

    unsigned int copy_len = size - dest_len - 1;
    ft_strncat(dest + dest_len, src, copy_len);

    dest[dest_len + copy_len] = '\0';

    return dest;
}