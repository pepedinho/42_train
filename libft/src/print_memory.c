#include "../include/libft.h"
#include <unistd.h>


void print_memory(const void *addr, size_t size)
{
    const unsigned char *p = addr;

    size_t i = 0;
    size_t size_length = 16; 
    size_t space_length = 2;


    while (i < size)
    {
        unsigned char c = p[i] / 16;
        write(1, &"0123456789abcdef"[c], 1);
        c = p[i] % 16;
        write(1, &"0123456789abcdef"[c], 1);
        
        if ((i + 1) % size_length == 0 || i + 1 == size)
        {
            write(1, "  ", 2);
            size_t j = 0;
            while (j < size_length && (i + j) < size)
            {
                if (ft_isprint(p[i + j]))
                {
                    write(1, (char *)&p[i + j], 1);
                }
                else
                {
                    write(1, ".", 1);
                }
                j++;
            }
            write(1, "\n", 1);
        }
        else if ((i + 1) % space_length == 0)
        {
            write(1, " ", 1);
        }
        
        

        // if (i % 2 != 0)
        // {
        // }
        i++;
    }
    write(1, "\n", 1);
}


