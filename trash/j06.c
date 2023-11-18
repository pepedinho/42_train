#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{

    int len = 0;
    char result[50];
    char link[100];

    while (argv[0][len] != '\0')
    {
        link[len] = argv[0][len];
        len++;
    }

    int i = len;
    printf("%d\n", len);

    while (link[i] != 92)
    {
        result[len - i] = link[i];
        printf("debug 1 = %c\n", result[len - i]);
        printf("debug 2 = %c\n", link[i]);
        i--;
    }

    result[len - i] = '\0';
    char r[60];
    int j = 0;

    while (j < len - i)
    {
        r[strlen(result) - j] = result[j];
        j++;
    }

    printf("result : '%s'\n", r);
    printf("debug 3 = %c\n", result[2]);
    printf("%s\n", link);
    printf("%d\n", i);
    return 0;
}
