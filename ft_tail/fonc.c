#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "fonc.h"


int ft_tail(int argc, char const *argv[])
{
    char buff[100];
    int fd; //descripteur de fichier a lire
    int nb_read; //nombre de caractere lu

    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return (1);
    }
    fd = open(argv[argc - 1], O_RDONLY);

    if (fd == -1)
        return (1);

    nb_read = - 1;

    while (nb_read != 0)
    {
        nb_read = read(fd, buff, 100);

        if (nb_read == -1){
            printf("Erreur de lecture\n");
            return (1);
        }

        buff[nb_read] = '\0';

        printf("%s\n", buff);
    }
    
    close(fd);

    return 0;
}
