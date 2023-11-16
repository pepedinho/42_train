#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_strlen(char *src)
{
    int i = 0;
    while (src[i] != '\0')
    {
        i++;
    }

    return i;
}

char *ft_strdup(char *src)//copie la chaine de carcatere entrée en parametre dans une nouvelles chaine et renvoie un pointeur vers la nouvelle chaine
{
    char *dest = malloc(sizeof(char) * ft_strlen(src));

    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    return dest;
}

int *ft_range(int min, int max)
{
    int i = min;
    int j = 0;

    int *tab = malloc(sizeof(int) * (max - min));

    if (min >= max)
    {
        tab = NULL;
        return tab;
    }
    

    while (i < max)
    {
        tab[j] = i;
        i++;
        j++;
    }
    
    return tab;
}

int ft_ultimate_range(int **range, int min, int max)
{
    int i = min;
    int j = 0;

    int *tab = malloc(sizeof(int) * (max - min));


    if (min >= max)
    {
        free(tab);
        tab = NULL;
        *range = tab;
        return 0;
    }
    

    while (i < max && j < (max - min))
    {
        tab[j] = i;
        i++;
        j++;
    }
    
    return (max - min);
}

char *ft_concat_params(int argc, char **argv)
{
    int i = 0;
    int k = 0; 

    while (i < argc)
    {
        int j = 0;
        while (j < ft_strlen(argv[i]))
        {
            k++;
            j++;
        }
        i++;
    }
    
    k += argc;

    char *result = malloc(sizeof(char) * k);

    i = 0;

    int l = 0;
    while (i < argc)
    {
        int j = 0;
        while (j < ft_strlen(argv[i]))
        {
            result[l] = argv[i][j];
            j++;
            l++;
        }
        if (i < argc - 1)
        {
            result[l] = '\n';
            l++;
        }
        i++;
    }

    result[l] = '\0';

    return result;
    
}

int main(int argc, char const *argv[])
{
    char test[] = "hello";
    char *result = ft_strdup(test);

    write(STDOUT_FILENO, result, sizeof(result) - 1);

    int min = 4;
    int max = 20;

    write(STDOUT_FILENO, "\n", 1);

    int *tab = ft_range(min, max);
    int i = 0;
    
    while (i < (max - min))
    {
        if (&tab[i] != NULL)
        {
            char buffer[20];
            sprintf(buffer, "%d ", tab[i]);
            write(STDOUT_FILENO, buffer, ft_strlen(buffer));
            i++;
        }
        else{
            break;
        }
    }
    free(tab);

    int **taab = NULL;
    int size = ft_ultimate_range(taab, min, max);

    for (int i = 0; i < size; i++) {
        free(taab);
    }
    char buffer[20];
    sprintf(buffer, "Size: %d\n", size);
    write(STDOUT_FILENO, buffer, ft_strlen(buffer));

    char **arguv = malloc(sizeof(char *) * argc);
    for (int i = 0; i < argc; i++) {
        arguv[i] = strdup(argv[i]);
    }

    char* params = ft_concat_params(argc, arguv);

    printf("%s", params);

    return 0;
}
