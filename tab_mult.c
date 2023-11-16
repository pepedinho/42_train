#include <unistd.h>

void ft_putshar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

void ft_putnbr(int n)
{
    if (n < 10)
        ft_putshar(n + '0');
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        ft_putshar('\n');
    }

    int i = 0, decimal_number = 0;

    while (argv[argc - 1][i] != '\0')
    {
        decimal_number = decimal_number * 10 +  (argv[argc - 1][i] - '0');
        i++;
    }

    if(decimal_number >= 2147483647)
    {
        write(STDOUT_FILENO, "Réessayer avec un nombre plus petit", 35);
    }

    int j = 1;

    int result = 0;
    char num = '\0';

    while (j <= 9)
    {
        result = decimal_number * j;
        
        
        if (j == 0)
        {
            num = '0';
        }
        else if (j == 1)
        {
            num = '1';
        }
        else if (j == 2)
        {
            num = '2';
        }
        else if (j == 3)
        {
            num = '3';
        }
        else if (j == 4)
        {
            num = '4';
        }
        else if (j == 5)
        {
            num = '5';
        }
        else if (j == 6)
        {
            num = '6';
        }
        else if (j == 7)
        {
            num = '7';
        }
        else if (j == 8)
        {
            num = '8';
        }
        else if (j == 9)
        {
            num = '9';
        }
        
        if (result >= __INT_MAX__)
        {
            write(STDOUT_FILENO, "Réessayer avec un nombre plus petit", 35);
            return 0;
        }
        
        write(STDOUT_FILENO, &num, 1);
        write(STDOUT_FILENO, " x ", 3);
        ft_putnbr(decimal_number);
        write(STDOUT_FILENO, " = ", 3);
        ft_putnbr(result);
        ft_putshar('\n');

        j++;
    }
    
    
    return 0;
}
