#include <stdlib.h>
#include <unistd.h>

unsigned char reverse_bits(unsigned char octet)
{
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


void print_byte(char oct)
{

    int base = 7, i = 0;

    unsigned char result = '\0';
    
    int buffer = 0;

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
        i++;
        base--;
    }
}

int main(int argc, char const *argv[])
{
    char oct = argv[argc - 1][0];

    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "  BYTE : ", 9);
    write(STDOUT_FILENO, &argv[argc - 1][0], 1);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "_____________", 13);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "  ", 2);

    print_byte(oct);
    

    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "     ||     ", 13);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "     \\/     ", 13);
    write(STDOUT_FILENO, "\n", 1);

    //char revers = reverse_bits(oct);

    //write(STDOUT_FILENO, &revers, 1);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "  ", 2);
    print_byte(reverse_bits(oct));
    

    
    return 0;
}
