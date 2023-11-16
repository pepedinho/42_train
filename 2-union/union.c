#include <unistd.h>


int ft_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}


int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        write(STDOUT_FILENO, "\n", 1);
        return 1;
    }

    int i = 0;
    char buffer = '\0';
    int s = 0;
    char seen[256] = {0};

    while (i < ft_strlen(argv[argc - 2]))
    {
        buffer = argv[argc - 2][i];
        int m = 0;
        int isseen = 0;
        while (m < 256)
        {
            if (argv[argc - 2][i] == seen[m])
            {   
                isseen = 1;
                break;
            }
            m++;
        }
        
        if (isseen == 0)
        {
            seen[s] = argv[argc - 2][i];
            write(STDOUT_FILENO, &buffer, 1);
        }
        
        i++;
        s++;
    }

    i = 0;

    while (i < ft_strlen(argv[argc - 1]))
    {
        buffer = argv[argc - 1][i];

        int m = 0;
        int isseen = 0;
        while (m < 256)
        {
            if (argv[argc - 1][i] == seen[m])
            {   
                isseen = 1;
                break;
            }
            m++;
        }
        
        if (isseen == 0)
        {
            seen[s] = argv[argc - 1][i];
            write(STDOUT_FILENO, &buffer, 1);
        }
        
        i++;
        s++;
    }
    
    return 0;
}
