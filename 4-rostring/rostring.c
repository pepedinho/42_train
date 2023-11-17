#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{


    //allocation dynamique pour les tableaux
    int nbMot = 0;
    


    int j = 0;

    while (argv[argc - 1][j] != '\0')
    {
        if (argv[argc - 1][j] == ' ' && argv[argc - 1][j - 1] != ' ' && argv[argc - 1][j + 1] != ' ')
        {
            nbMot++;
        }
        j++;
    }

    if (nbMot == 1)
    {
        printf("%s", argv[argc - 1]);
        return 0;
    }
    

    nbMot++;

    int k = 0, l = 0, buff = 0;

    int *nbChar = malloc(j * sizeof(int)); 

    while (argv[argc - 1][k] != '\0')
    {
        if (argv[argc - 1][k] == ' ' && buff > 0)
        {
            nbChar[l] = buff;
            printf("debug : nbChar[%d] = %d \n", l, nbChar[l]);
            buff = 0;
            l++;
            k++;
        }

        if (argv[argc - 1][k] != ' ')
        {
            buff++;
        }
        k++;
    }

    nbChar[l] = buff;

    printf("debug : nbChar[l] = %d \n", nbChar[l]);
    
    printf("DEBUG NB MOTS : %d\n", nbMot);

    if (nbMot == 1)
    {

        int len = 0;
        while (argv[argc - 1][len] != '\0')
        {
            len++;
        }
        
        char *temp = malloc(sizeof(char) * len);

        len = 0;

        if (len == 0 && argv[argc - 1][len] == ' ')
        {
            while (argv[argc - 1][len] != '\0')
            {
                if (argv[argc - 1][len] != ' ')
                {
                    break;
                }
                len++;
                //printf("debug len : %d", len);
            }
        }
        
        int snake = 0;
        while (argv[argc - 1][len] != ' ')
        {
            temp[snake] = argv[argc - 1][len];
            len++;
            snake++;
        }

        temp[len] = '\0';
        
        printf("%s", temp);
        free(temp);
        return 0;
    }
    //allocation dynamique du tableau principal

    char **tab = (char**)malloc(nbMot * sizeof(char*));
    int i = 0;
    while (i < nbMot)
    {
        if(i == nbMot - 1)
        {
            tab[i] = (char*)malloc((nbChar[0] + 1) * sizeof(char));
            printf("/!\\debbug alloc (last word) : nbChar[%d + 1] = %d\n", i, nbChar[0] + 1 );
        }
        else
        {
            tab[i] = (char*)malloc((nbChar[i + 1] + 1) * sizeof(char));
            printf("/!\\debbug alloc : nbChar[%d + 1] = %d\n", i, nbChar[i + 1] + 1);
        }
        i++;
    }

    i = 0, j = 0;


    j = 0;
    char *buffer = malloc(sizeof(char) * nbChar[0]);
    //rearganisation des mots
    while (i < nbMot)
    {   
        printf("tant que i(%d) < nbMot(%d)\n", i, nbMot);
        int index = 0;
        if (i == 0)
        {
            while (index < nbChar[0] && argv[argc - 1][j] != ' ' && argv[argc - 1][j] != '\0') 
            {
                printf("    debug if : %c\n", argv[argc - 1][j + nbChar[0]]);
                buffer[index] = argv[argc - 1][j];
                tab[i][index] = argv[argc - 1][j + nbChar[0]];
                printf("        (if)tab[%d][index(%d)] = argv[argc - 1][%d + %d](%c)(+1 = '%c')\n", i, index, j, nbChar[0], argv[argc - 1][j + nbChar[0]], argv[argc - 1][j + nbChar[0] + 1]);
                j++;
                index++;
            }
            printf("\n");
            buffer[index] = '\0';
            tab[0][index] = '\0';
        }
        else if (i == nbMot - 1)
        {
            printf("    debug(else if) : index = %d, nbChar[%d + 1] = %d,buffer[%d] = %c\n", index, i, nbChar[i], index, buffer[index] );
            while (index < nbChar[i] && buffer[index] != '\0') 
            {
                printf("debug if i(%d)\n", i);
                tab[i][index] = buffer[index];
                printf("DEBUG BUFFER : %c", buffer[index]);
                j++;
                index++;
            }
            printf("\n");
            tab[i][index] = '\0';
        }
        else
        {
            printf("    debug(else) : index = %d, nbChar[%d + 1] = %d, argv[argc - 1][%d] = %c (+1 ='%c')\n", index, i, nbChar[i + 1], j, argv[argc - 1][j + nbChar[0]], argv[argc - 1][j + nbChar[0] + 1]);
            while (index < nbChar[i + 1] && argv[argc - 1][j + nbChar[0]] != ' ' && argv[argc - 1][j + nbChar[0]] != '\0')
            {
                tab[i][index] = argv[argc - 1][j + nbChar[0]];
                printf("        (else)tab[%d][index(%d)] = argv[argc - 1][%d](%c)(+1 = '%c')\n", i, index, j, argv[argc - 1][j + nbChar[0]], argv[argc - 1][j + nbChar[0] + 1]);
                j++;
                index++;
            }
            printf("\n");
            tab[i][index] = '\0';
        }
        

        if (argv[argc - 1][j + nbChar[0]] == ' ')
        {
            while (argv[argc - 1][j + nbChar[0]] == ' ')
            {
                j++;
            }
        }
        
        i++;
    }
    
    
    printf("\ni = %d j = %d \n", i, j);

    printf("nb mots : %d\n", nbMot);
    printf("resultat : ");

    i = 0; 
    j = 0;


    while (i < nbMot)
    {
        j = 0;
        while (tab[i][j] != 0)
        {
            printf("%c", tab[i][j]);
            j++;
        }
        printf(" ");
        i++;
    }

    // while (tab[i][j] != '\0')
    // {
    //     printf("%c", tab[i][j]);
    //     j++;
    // }
    


    return 0;
}
