#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));

    while (s1[i] != '\0')
    {
        str[k] = s1[i];
        i++;
        k++;
    }

    while (s2[j] != '\0')
    {
        str[k] = s2[j];
        j++;
        k++;
    }

    str[k] = '\0';

    return str;
}

int ft_strlen(char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        i++;
    }

    return i;
}

// fonction qui copie une chaîne de caractères dans une autre
char *ft_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;
}

char *ft_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';

    return dest;
}

// fonction qui convertit une chaîne de caractères en entier
int ft_atoi(char *str)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    // on ignore les espaces et les caractères de contrôle au début de la chaîne
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
    {
        i++;
    }

    // on gère le signe éventuel
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
    {
        i++;
    }

    // on convertit la chaîne de caractères en entier
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}


void remove_spaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
           str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}
// fonction qui évalue une expression arithmétique
int eval_expr(char* str)
{
    int i = 0;
    int num_operator = 0;
    char **big_buffer = NULL;
    char **operator = NULL;

    // on supprime les espaces de la chaîne de caractères
    remove_spaces(str);

    // on compte le nombre d'opérateurs dans la chaîne
    while (str[i] != '\0')
    {
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == '(' || str[i] == ')')
        {
            num_operator++;
        }
        i++;    
    }

    int j = 0;
    int k = 0;
    int part_count = 0;
    operator = (char**)malloc((num_operator + 1) * sizeof(char*));
    big_buffer = (char**)malloc((num_operator + 1) * sizeof(char*));
    int op_index = 0;

    // on découpe la chaîne en parties séparées par les opérateurs
    // Cette boucle permet de séparer la chaîne de caractères "str" en plusieurs parties en fonction des opérateurs (+, -, *, /, %) qu'elle contient.
    // Chaque partie est stockée dans un tableau "big_buffer", et chaque opérateur est stocké dans un tableau "operator".
    // Les tableaux "big_buffer" et "operator" sont alloués dynamiquement.
    // La boucle se termine lorsque tous les opérateurs ont été trouvés dans la chaîne "str".
    while (j <= num_operator)
    {
        // Allocation dynamique des tableaux "buffer" et "operator_buffer".
        char *buffer = malloc(sizeof(char) * ft_strlen(str));
        char *operator_buffer = malloc(sizeof(char) * ft_strlen(str));
        int l = 0;

        // Cette boucle permet de stocker chaque caractère de "str" dans "buffer" jusqu'à ce qu'un opérateur soit trouvé.
        while (str[k] != '+' && str[k] != '-' && str[k] != '*' && str[k] != '/' && str[k] != '%' && str[k] != '(' && str[k] != ')' && str[k] != '\0')
        {

            if(str[k] != ' ')
            {
                buffer[l] = str[k];
                l++;
            }
            k++;
        }

        buffer[l] = '\0';

        // Si la fin de "str" n'a pas été atteinte, on incrémente "k".
        if (str[k] != '\0')
        {
            k++;
        }

        // Stockage de l'opérateur dans "operator_buffer".
        operator_buffer[0] = str[k - 1];
        operator_buffer[1] = '\0';

        // Allocation dynamique de la mémoire pour stocker l'opérateur dans "operator".
        operator[op_index] = (char *)malloc(2);
        ft_strcpy(operator[op_index], operator_buffer);
        op_index++;

        // Allocation dynamique de la mémoire pour stocker la partie de "str" dans "big_buffer".
        big_buffer[part_count] = (char *)malloc(ft_strlen(buffer) + 1);
        ft_strcpy(big_buffer[part_count], buffer);
        part_count++;

        // Si l'opérateur est une parenthèse fermante, on stocke également l'opérateur dans "big_buffer".
        if (*operator_buffer == ')')
        {
            big_buffer[part_count] = (char *)malloc(2);
            ft_strcpy(big_buffer[part_count], operator_buffer);
            part_count++;
        }

        // Libération de la mémoire allouée pour "operator_buffer".
        free(operator_buffer);

        // Libération de la mémoire allouée pour "buffer".
        free(buffer);

        j++;
    }

    big_buffer[part_count] = NULL;

    // on évalue l'expression en appliquant les opérateurs aux parties
    int index = 0;
    int result = ft_atoi(big_buffer[index]);
    int paren_count = 0;
    int before_index = 0;

    while (big_buffer[index] != NULL)
    {
        if (*operator[index] == '(')
        {
            before_index = index - 1;
            // Compter le nombre de parenthèses ouvrantes.
            paren_count++;

            // Stocker l'opérateur précédent la parenthèse ouvrante.
            char prev_operator = '+';
            if (index > 0)
            {
                prev_operator = *operator[index - 1];
            }

            // Concaténer toutes les parties de la sous-expression entre parenthèses en une seule chaîne de caractères.
            char *sub_expression = malloc(sizeof(char) * ft_strlen(str));
            ft_strcpy(sub_expression, big_buffer[index + 1]);
            int i = index + 2;
            while (*operator[i] != ')')
            {
                char *operator_str = malloc(sizeof(char) * 2);
                operator_str[0] = *operator[i];
                operator_str[1] = '\0';
                sub_expression = ft_strjoin(sub_expression, operator_str);
                free(operator_str);
                sub_expression = ft_strjoin(sub_expression, big_buffer[i]);
                i++;
            }
            
            // Évaluer la sous-expression.
            int sub_result = eval_expr(sub_expression);

            // Ajouter le résultat au résultat final en fonction de l'opérateur précédent la parenthèse ouvrante.
            if (prev_operator == '+')
            {
                result += sub_result;
            }
            else if (prev_operator == '-')
            {
                result -= sub_result;
            }
            else if (prev_operator == '*')
            {
                result *= sub_result;
            }
            else if (prev_operator == '/')
            {
                result /= sub_result;
            }
            else if (prev_operator == '%')
            {
                result %= sub_result;
            }

            // Libération de la mémoire allouée pour "sub_expression".
            free(sub_expression);
        }
        else if (*operator[index] == ')')
        {
            // Compter le nombre de parenthèses fermantes.
            paren_count--;

            // Si toutes les parenthèses ont été fermées, sortir de la boucle et retourner le résultat.
            if (paren_count == 0)
            {
                return result * ft_atoi(big_buffer[before_index]);
            }
        }
        else if (*operator[index] == '*' || *operator[index] == '/' || *operator[index] == '%')
        {
            // Évaluer l'opération entre les parties.
            int next_num = ft_atoi(big_buffer[index + 1]);
            if (*operator[index] == '*')
            {
                result *= next_num;
            }
            else if (*operator[index] == '/')
            {
                result /= next_num;
            }
            else if (*operator[index] == '%')
            {
                result %= next_num;
            }

            // Si l'opérateur suivant est une parenthèse fermante, on continue à évaluer l'expression à l'intérieur de la parenthèse.
            if (operator[index + 1] != NULL && *operator[index + 1] == ')')
            {
                index++;
                continue;
            }
        }
        else if (*operator[index] == '+' || *operator[index] == '-')
        {
            // Évaluer l'opération entre les parties.
            int next_num = ft_atoi(big_buffer[index + 1]);
            if (*operator[index] == '+')
            {
                result += next_num;
            }
            else if (*operator[index] == '-')
            {
                result -= next_num;
            }
        }

        // Incrémenter "index".
        index++;
    }

    return result;
}

int main()
{
    char buf[200];
    printf("entré la formul a calucler : ");
    fgets(buf, sizeof(buf), stdin);
    
    printf("%d\n", eval_expr(buf));
    
    return 0;
}
