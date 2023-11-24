#include <unistd.h>
//fonctione  qui sert a remplir une zone de memoire avec un octet
void *ft_memset (void* s, int c, size_t n)
{
    size_t i = 0;

    while (i < n)
    {
        ((unsigned char*)s)[i] = c;
        i++;
    }

    return s;
}