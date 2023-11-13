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


int main()
{
    ft_print_number();
    return 0;
}
