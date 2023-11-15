#include <unistd.h>


int ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }
    
    return i;
}


//0123456789abcdef
int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        write(STDOUT_FILENO, '\n', 1);
        return 0;
    }

    int running = 1;

    int i = 0, result = 0;



    while (running == 1)
    {
        // result = 
    }
    



    
    return 0;
}
