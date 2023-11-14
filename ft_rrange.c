#include <stdlib.h>
#include <stdio.h>


int *ft_rrange(int start, int end)
{   
    int range = (end - start);

    if (range < 0) {
        int temp = start;
        start = end;
        end = temp;
        range = -range;
    }
    range ++;

    int i = 0;

    int *tab = malloc(sizeof(int) * range);

    if (end < start)
    {
        while (i < range)
        {   
            tab[i] = start + i;
            i++;
        }
    }
    else
    {
        while (i < range)
        {   
            tab[i] = end - i;
            i++;
        }
    }
    
    
    return tab;
}

int main()
{

    int start = 0, end = -3;
    int *resultat = ft_rrange(start, end);
    int i = 0;

    int range = (end - start);

    if (range < 0) {
        int temp = start;
        start = end;
        end = temp;
        range = -range;
    }

    range++;

    while (i < range)
    {
        printf("[%d] ", resultat[i]);
        i++;
    }
    
    free(resultat);
    
    return 0;
}
