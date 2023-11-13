#include <unistd.h>

int main()
{
    int i = 26;

    char alpha[] = "abcdefghijklmnopqrstuvwxyz";

    while (i >= 0)
    {
        if(i % 2 == 0)
        {
            alpha[i] -= 32;
        }

        if ((alpha[i] >= 'a' && alpha[i] <= 'z') || (alpha[i] >= 'A' && alpha[i] <= 'Z'))
        {
            write(1, &alpha[i], 1);
        }
        i--;
    }
    

    return 0;
}
