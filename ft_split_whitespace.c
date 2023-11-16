#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char* str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

char *ft_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    return dest;
}

char **ft_split_whitespace(char* str)
{
    int i = 0;
    int num_whitespace = 0;
    char **result = NULL;
    
    while (str[i] != '\0')
    {
        if(str[i] == ' ')
        {
            num_whitespace++;
        }
        i++;
    }

    int j = 0;
    int k = 0;
    int word_count = 0;
    result = (char**)malloc((num_whitespace + 1) * sizeof(char*));
    while (j <= num_whitespace)
    {
        char *buffer = malloc(sizeof(char) * ft_strlen(str));
        int l = 0;
        while (str[k] != ' ' && str[k] != '\0')
        {
            buffer[l] = str[k];
            k++;
            l++;
        }
        result[word_count] = malloc(ft_strlen(buffer) + 1);
        ft_strcpy(result[word_count], buffer);
        word_count++;

        free(buffer);
        
        if (str[k] != '\0')
        { 
            k++;
        }
        j++;
    }
    result[word_count] = NULL;
    return result;
}


void ft_print_words_tables(char** tab)
{
    int i = 0;
    
    while (tab[i] != NULL)
    {
        write(STDOUT_FILENO, tab[i], ft_strlen(tab[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
    
}


int main(int argc __attribute__((unused)), char const *argv[] __attribute__((unused)))
{

    char testStr[] = "Hello World from ChatGPT";

    ft_print_words_tables(ft_split_whitespace(testStr));

    return 0;
}
