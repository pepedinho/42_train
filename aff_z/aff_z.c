#include <unistd.h>


void ft_print_number(void)
{
    int i = 0;
    char num = 0;

    while (i <= 9)
    {
        if(i == 0)
        {
            num = '0';
        }
        else if (i == 1)
        {
            num = '1';
        }
        else if (i == 2)
        {
            num = '2';
        }
        else if (i == 3)
        {
            num = '3';
        }
        else if (i == 4)
        {
            num = '4';
        }
        else if (i == 5)
        {
            num = '5';
        }
        else if (i == 6)
        {
            num = '6';
        }
        else if (i == 7)
        {
            num = '7';
        }
        else if (i == 8)
        {
            num = '8';
        }
        else if (i == 9)
        {
            num = '9';
        }
        write(1, &num, 1);
        write(1, "\n", 1);
        i++;
    }
}


int main(int argc, char const *argv[])
{
    int i = 0;


    if(argc != 2)
    {
        write(1, "z\n", 1);
        return 0;
    }

    const char* str = argv[1];
    char z = 'z';

    while (str[i] != '\0')
    {
        if(str[i] == 'z')
        {
            write(1, &z, 1);
            write(1, "\n", 1);
            return 0;
        }
        i++;
    }

    write(1, &z, 1);
    write(1, "\n", 1);

    ft_print_number();
    
    return 0;
}
