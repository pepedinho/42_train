#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




int main(int argc, char const *argv[])
{
    if (argc != 4)
    {
        write(1, "\n", 1);
        return 0;
    }

    int left_agr = atoi(argv[1]);
    int right_arg = atoi(argv[3]);


     if (left_agr == 0 && argv[1][0] != '0')
    {
        printf("Erreur de conversion pour le premier argument\n");
        return 1; // Retournez une valeur différente de zéro pour indiquer une erreur
    }

    if (right_arg == 0 && argv[3][0] != '0')
    {
        printf("Erreur de conversion pour le deuxième argument\n");
        return 1; // Retournez une valeur différente de zéro pour indiquer une erreur
    }

    if (argv[2][0] == '+')
    {
        printf("%d", left_agr + right_arg);
    }
    else if (argv[2][0] == '*')
    {
        printf("%d", left_agr * right_arg);
    }
    else if (argv[2][0] == '-')
    {
        printf("%d", left_agr - right_arg);
    }
    else if (argv[2][0] == '/')
    {
        printf("%d", left_agr / right_arg);
    }
    

    return 0;
}
