#include <unistd.h>


int main(int argc, char const *argv[])
{
    int len = 0;

    while (argv[argc - 1][len] != '\0')
    {
        len++;
    }

    int j = 0;

    int isASpace = 0;

    while (j < len)
    {
        if (argv[argc - 1][j] == ' ' && argv[argc - 1][j + 1] != ' ' && j == 0)
        {
            isASpace = 2;
        }
        else if (argv[argc - 1][j] == ' ' && argv[argc - 1][j + 1] != ' ')
        {
            isASpace = 1;
        }
        else if (argv[argc - 1][j] == ' ')
        {
            isASpace = 2;
        }
        
        
        


        if (isASpace == 0)
        {
            write(STDOUT_FILENO, &argv[argc - 1][j], 1);
        }
        else if (isASpace == 1)
        {
            write(STDOUT_FILENO, " ", 1);
        }
        
        isASpace = 0;
        j++;
    }
    
    
    return 0;
}
