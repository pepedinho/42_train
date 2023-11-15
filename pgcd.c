#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    int i = 1, taille = 1, index = 0;

    double result = 0;
    int running = 0;

    int val = atoi(argv[argc - 2]);

    int *tab = (int *)malloc(sizeof(int) * taille);
    while (running != 1)
    {
        result = val % i;
        running = val / i;

        if (result == 0 && running != 0)
        {
            taille++;
            int *nouveautableau = (int*)malloc(taille * sizeof(int));

            // Vérification si l'allocation a réussi
            if (nouveautableau == NULL) {
                printf("Erreur d'allocation de mémoire\n");
                free(tab);
                return 1;  // Quitter le programme en cas d'erreur
            }

            int j = 0;
            while (j < taille)
            {
                nouveautableau[j] = tab[j];
                j++;
            }

            free(tab);

            tab = nouveautableau;

            tab[index] = i;
            index++;
            
        }
        i++;
    }
    
    int k = 1;

    int result2 = 0, running2 = 0;
    int resSize = 1;
    int *resTab = (int *)malloc(sizeof(int) * resSize);
    index = 0;
    int value = atoi(argv[argc - 1]);

    while (k < taille)
    {   
        result2 = value % k;
        running2 = value / k;
        

        if(result2 == 0 && running2 !=0)
        {
            int l = 0;
            while (l < taille)
            {
                if (tab[l] == k)
                {
                    resSize++;
                    int *resTab2 = (int*)malloc(resSize * sizeof(int));

                    // Vérification si l'allocation a réussi
                    if (resTab2 == NULL) {
                        printf("Erreur d'allocation de mémoire\n");
                        free(resTab);
                        return 1;  // Quitter le programme en cas d'erreur
                    }
                    int j = 0;
                    while (j < taille)
                    {
                        resTab2[j] = resTab[j];
                        j++;
                    }

                    free(resTab);

                    resTab = resTab2;

                    resTab2[index] = k;
                    index++;
                }
                
                l++;
            }
        }
        k++;
    }

    int m = 0;
    int max = resTab[0];

    while (m < resSize)
    {
        if (resTab[m] > max)
        {
            max = resTab[m];
        }
        m++;
    }

    printf("%d", max);
    
    

    return 0;
}
