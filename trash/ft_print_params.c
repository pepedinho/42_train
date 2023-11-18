#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 1;
    while (argv[i] != NULL)
    {
        printf("%s", argv[i]);
        i++;
    }
    return 0;
}
