#include <stdio.h>
#include <stdlib.h>
#include "rpn_calc.h"

void ft_reset(int *a, int *b)
{
    *a = 0;
    *b = 0;
}

int do_calcul(int a, int b, char op)
{
    if (op == '*')
    {
        return a * b;
    }
    else if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '/')
    {
        if (b != 0)
        {
            return a / b;
        }
        else
        {
            printf("Error: Division by zero\n");
            exit(1);
        }
    }
    else
    {
        printf("Error: Invalid operator\n");
        exit(1);
    }
}

int rpn_cal(char *str)
{
    int i = 0;
    int tab[2];
    int len = 0;
    int nb_result = 0;
    
    while (str[len] != '\0')
    {
        if (str[len] == '*' || str[len] == '+' || str[len] == '/' || str[len] == '-')
        {
            nb_result++;
        }
        len++;
    }
    nb_result++;
    
    char operator = '\0';
    int *resultat = malloc(sizeof(int) * nb_result);
    char buffer[10]; // Assuming the maximum number of digits in a number is 10
    int index = 0;
    int op = 0;
    int res_count = 0;
    int step = 0;
    
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9' && str[i + 1] == ' ')
        {
            buffer[index] = str[i];
            buffer[index + 1] = '\0';
            tab[op] = atoi(buffer);
            index = 0;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            buffer[index] = str[i];
            index++;
        }
        else if (str[i] == ' ')
        {   
            if (op == 2 && step == 0)
            {
                resultat[res_count] = do_calcul(tab[op - 1], tab[op], operator);
                res_count++;
                step++;
                op = 0;
                ft_reset(&tab[0], &tab[1]);
            }
            else if (op == 1 && step > 0)
            {
                resultat[res_count] = do_calcul(resultat[res_count - 1], tab[0], operator);
                res_count++;
                step++;
                op = 0;
                ft_reset(&tab[0], &tab[1]);
            }
            op++;
        }
        else if (str[i] == '*' || str[i] == '+' || str[i] == '/' || str[i] == '-')
        {
            operator = str[i]; 
        }
        else
        {
            printf("Error: Invalid character\n");
            exit(1);
        } 
        i++;
    }
    
    int res = resultat[res_count - 1];
    free(resultat);
    return res;
}