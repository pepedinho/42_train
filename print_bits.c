#include <stdlib.h>
#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{

        if (octet < 0 || octet > 255)
    {
        write(STDOUT_FILENO, "Error: Invalid octet\n", 22);
        return 0;
    }

    unsigned char reversed = 0;
    int i = 0; 

    while (i < 8)
    {
        reversed = (reversed << 1) | (octet & 1);
        octet >>= 1;
        i++;
    }
    
    return reversed;
}

int poww(int a, int pw)
{
    int i = 0, result = 1;

    while (i < pw)
    {
        result *= a;
        i++;
    }
    
    return result;
}

int main(int argc, char const *argv[])
{
    char oct = argv[argc - 1][0];

    int base = 7, i = 0;

    char rev_tab[9];

    unsigned char result = '\0';
    
    int buffer = 0;
    
    write(STDOUT_FILENO, &argv[argc - 1][0], 1);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "_____________", 13);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "  ", 2);

    while (base >= 0)
    {

        buffer = 1 << base;
        if(oct & buffer)
        {
            result = '1';
            oct -= buffer;
        }
        else
        {
            result = '0';
        }
        
        write(STDOUT_FILENO, &result, 1);
        rev_tab[i] = reverse_bits(oct);
        i++;
        base--;
    }
    rev_tab[i] = '\0';

    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "     ||     ", 13);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "     \\/     ", 13);
    write(STDOUT_FILENO, "\n", 1);
    for (i = 0; i < 8; i++)
    {
        write(STDOUT_FILENO, &rev_tab[i], 1);
    }

    
    return 0;
}
