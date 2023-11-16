#include <stdio.h>


int max(int* tab, unsigned int len)
{
    unsigned int i = 0;
    int result = 0;

    if(tab == NULL)
    {
        return 0;
    }

    while (i < len)
    {
        if ((tab[i] > tab[i + 1] && tab[i] > tab[i - 1] && tab[i] > result) || (i == 0 && tab[i] > tab[i + 1])) 
        {
            result = tab[i];
        }
        i++;
    }
    return result;
}


int main()
{
    int tab[7] = {10, 25, 5, 20, 11, 30, 23};


    printf("%d", max(tab, 7));

    return 0;
}
