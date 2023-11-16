#include <unistd.h>


int main(int argc, char* argv[])
{

    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    
    while (argv[argc - 1][i] != '\0')
    {
        int j = 0;
        while (j <= 26)
        {
            if (argv[argc - 1][i] == alpha[j])
            {
                int k = 0;
                while (k <= j)
                {
                    write(STDOUT_FILENO, &argv[argc - 1][i], 1);
                    k++;
                }
            }
            j++;
        }
        i++;
    }
    
    return 0;
}
