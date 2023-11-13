#include <unistd.h>


int main(int argc, char* argv[])
{

    if (argc - 1 > 1)
    {
        write(1, "\n", 1);
        return 0;
    }

    char alpha[] = "abcdefghijklmnopqrstuvwxyz";
    char maj_alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    
    while (argv[argc - 1][i] != '\0')
    {
        int j = 0;
        char buffer = '\0';
        while (j < 26)
        {
            if (argv[argc - 1][i] == alpha[j])
            {
                if (j + 13 > 26)
                {
                    j = (j + 13) % 26;
                }
                else
                {
                    j += 13;
                }
                buffer = alpha[j];
                break;
            }
            else if (argv[argc - 1][i] == maj_alpha[j])
            {
                if (j + 13 > 26)
                {
                    j = (j + 13) % 26;
                }
                else
                {
                    j += 13;
                }
                buffer = maj_alpha[j];
                break;
            }
            j++;
        }
        if ((buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z'))
        {
            write(STDOUT_FILENO, &buffer, 1);
        }
        else
        {
            write(STDOUT_FILENO, &argv[argc - 1][i], 1);
        }
        i++;
    }

    
    
    return 0;
}
