#include <stdio.h>
#include <stdlib.h>
#include "rpn_calc.h"

//fonction pour restet la valeur de tab; 
void ft_reset(int a, int b)
{
    a = 0;
    b = 0;
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
        return a / b;
    }
    else
    {
        return 0;
    }
}

int rpn_cal(char *str)
{
    int i = 0;

    int tab[2];
    
    int len = 0;

    int nb_result = 0;//variable qui stock le nombre de resultat intermiediaire nessecaire 
    //recuperation de la longueur de str
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

    int *resultat = (int *)malloc(nb_result * sizeof(int));// tableau pour stocker les resultat intermediaire et le resultat final
    char *buffer = malloc(sizeof(char) * len);//buffer pour stocker les les chiffres composant le nombre
    int index = 0;

    int op = 0;//represente l'index de l'operande contenue dans tab
    int res_count = 0;//index du tableau de resultta
    int step = 0; //indicateur de l'etape actuel
    //boucle qui rempli le buffer et qui decoupe la chaine en operateur
    while (str[i] != '\0')
    {

        if (str[i] >= '0' && str[i] <= '9' && str[i +1] == ' ')
        {
            buffer[index] = str[i];
            if(atoi(buffer) != 0)
            {
                if (buffer[index] == 0)
                    buffer[index] = '\0';
                else
                    buffer[index + 1] = '\0';
                
                
                tab[op] = atoi(buffer);
                int count = 0;
                printf("buffer = [");
                while (buffer[count] != '\0')
                {
                    printf("%c", buffer[count]);
                    count++;
                }
                printf("]\n");
                
                printf("debug op : tab[%d] = %d\n", op, atoi(buffer));
                index = 0;
            }

        }
        else if (str[i] >= '0' && str[i] <= '9')//si le caractere est un un chiffre on le stock dans buffer;
        {
            buffer[index] = str[i];
            printf("debug buffer : buffer[%d] = %c \n", index, buffer[index]);
            
            index++;
        }
        else if (str[i] == ' ')//si le caractere est un espace on on verifie si nou avon deja les operateur, si c'est le cas on proccede au calcul du resultat temporaire
        {   
            if (step > 0)
            {
                op = 1;
            }
            else
            {
                op++;
            }
        }
        else if (str[i] == '*' || str[i] == '+' || str[i] == '/' || str[i] == '-')
        {
            operator = str[i]; 

            if (op == 2 && step == 0)
            {

                resultat[res_count] = do_calcul(tab[0], tab[1], operator);
                printf(" l80 (etapes : %d): resultat[%d] = %d = (%d %c  %d)operator = '%c' \n", step,res_count, do_calcul(tab[op - 2], tab[op - 1], operator), tab[op - 2], operator, tab[op - 1], operator);
                res_count++;
                step++;
                op = 0;
                ft_reset(tab[0], tab[1]);
            }
            else if (op == 1 && step > 0)
            {
                resultat[res_count] = do_calcul(resultat[res_count - 1], tab[1], operator);
                printf(" l88 (etapes : %d): resultat[%d] = %d = (res[res_count-1(%d)]%d %c  %d)operator = '%c' \n", step, res_count, do_calcul(resultat[res_count - 1], tab[0], operator), res_count - 1, resultat[res_count], operator, tab[0], operator);
                res_count++;
                step++;
                op = 0;
                ft_reset(tab[0], tab[1]);
            }
        }
        else
        {
            printf("Error!");
            return 1;
        }
        
        i++;
    }
    
    //free(buffer);
    int res = resultat[res_count - 1];
    free(resultat);
    return res;
}