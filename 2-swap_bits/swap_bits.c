
#include <unistd.h>

unsigned char swap_bits(unsigned char octet)
{
    char left[5];
    char right[5];

    int i = 7, j = 3;

    while (i >= 0)
    {   
        if (j < 0)
        {
            j = 3;
        }

        if(i >= 4)
        {
            left[3 - j] = (octet & (1 << i)) ? '1' : '0';
            j--;
        }
        else
        {
            right[3 - j] = (octet & (1 << i)) ? '1' : '0';
            j--;
        }
        i--;
    }
    left[4] = '\0';
    right[4] = '\0';

    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "\n", 1);


    write(STDOUT_FILENO, "    ", 3);
    write(STDOUT_FILENO, &octet, 1);
    write(STDOUT_FILENO, " byte", 5);
    write(STDOUT_FILENO, "\n", 1);


    
    write(STDOUT_FILENO, "_____________", 13);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "\n", 1);



    write(STDOUT_FILENO, " ", 1);
    write(STDOUT_FILENO, left, 4);
    write(STDOUT_FILENO, " | ", 3);
    write(STDOUT_FILENO, right, 4);

    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "     \\ /      ", 12);
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, "     / \\      ", 12);

    write(STDOUT_FILENO, "\n", 1);

    write(STDOUT_FILENO, " ", 1);
    write(STDOUT_FILENO, right, 4);
    write(STDOUT_FILENO, " | ", 3);
    write(STDOUT_FILENO, left, 4);
    

    return 0;
}



int main(int argc, char const *argv[])
{

    unsigned char oct = argv[argc - 1][0];

    swap_bits(oct);

    return 0;
}
