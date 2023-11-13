#include <unistd.h>


int main(int argc, char const *argv[])
{   
    int i = 0;
    while (argv[argc - 1][i] != '\0')
    {
        i++;
    }
    
    write(1, argv[argc - 1], i);
    write(1, "\n", 1);
    
    return 0;
}
