#include <unistd.h>


void ft_putchar(char c)
{
    write(STDOUT_FILENO, &c, 1);
}

void print_hex(int n)
{

    if (n == 0)
    {
        //ft_putchar('0');
        return;
    }


    if (n < 16)
    {
        // Si n est inférieur à 16, imprime le chiffre directement sans appel récursif
        char hex_digit = (n < 10) ? n + '0' : n - 10 + 'a';
        ft_putchar(hex_digit);
    }
    else
    {
        // Appel récursif pour les nombres supérieurs à 16
        print_hex(n / 16);

        // Impression du chiffre actuel
        int remainder = n % 16;
        char hex_digit = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
        ft_putchar(hex_digit);
    }
}

//0123456789abcdef
int main(int argc, char const *argv[])
{
        if (argc != 2) {
        ft_putchar('\n');
        return 0;
    }

    int decimal_number = 0;
    int i = 0;

    while (argv[argc - 1][i] != '\0')
    {
        decimal_number = decimal_number * 10 + (argv[argc - 1][i] - '0');
        i++;
    }

    print_hex(decimal_number);
    ft_putchar('\n');
    
    
    return 0;
}
