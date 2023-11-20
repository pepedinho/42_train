#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    
    return i;
}

int main(void)
{
    int i = 0; 
    int open_par = 0;
    int close_par = 0;
    int open_bracket = 0;
    int close_bracket = 0;
    int open_cbrace = 0;
    int close_cbrace = 0;

    int temp_open = 0;
    int temp_close = 0;
    char str[] = "{(([]))}";
    int len = ft_strlen(str);
    
    int open = open_bracket + open_cbrace + open_par;
    int close = close_bracket + close_cbrace + close_par;

    while (str[i] != '\0' )
    {
        if (open != close)
        {
            int j = i - 1;
            int reg = j;
            char buf = str[j];
            while (j < len - reg)
            {
               if (str[j] == '(' || str[j] == '{' || str[j] == '[')
               {
                    if (str[j] == '(')
                    {
                        open_par++;
                    }
                    else if (str[j] == '{')
                    {
                        open_cbrace++;
                    }
                    else
                    {
                        open_bracket++;
                    }
                    temp_open++;
               }
               else if (str[j] == ')' || str[j] == '}' || str[j] == ']')
               {
                    if (str[j] == ')')
                    {
                        close_par++;
                    }
                    else if (str[j] == '}')
                    {
                        close_cbrace++;
                    }
                    else
                    {
                        close_bracket++;
                    }
                    temp_close++;
               }

               if (buf == '(' && str[j] == ')' && temp_open != temp_close) //a finir !!!
               {
                    write(1, "Error", 5);
                    return 0;
               }
               else if (buf == '[' && str[j] == ']' && temp_open != temp_close)
               {
                    write(1, "Error", 5);
                    return 0;
               }
               else if (buf == '{' && str[j] == '}' && temp_open != temp_close)
               {
                    write(1, "Error", 5);
                    return 0;
               }
               
               
               
               
                j++;
            }
            if (buf == '(' && close_par == open_par && temp_close == temp_open)
            {
                //write(1,"OK", 2);
                open_bracket = 0;
                open_cbrace = 0;
                open_par = 0;
                close_bracket = 0;
                close_cbrace = 0;
                close_par = 0;
                temp_close = 0;
                temp_open = 0;
            }
            else if (buf == '[' && close_bracket == open_bracket && temp_close == temp_open)
            {
                open_bracket = 0;
                open_cbrace = 0;
                open_par = 0;
                close_bracket = 0;
                close_cbrace = 0;
                close_par = 0;
                temp_close = 0;
                temp_open = 0;
            }
            else if (buf == '{' && close_cbrace == open_cbrace && temp_open == temp_close)
            {
                open_bracket = 0;
                open_cbrace = 0;
                open_par = 0;
                close_bracket = 0;
                close_cbrace = 0;
                close_par = 0;
                temp_close = 0;
                temp_open = 0;
            }
            else
            {
                write(1, "Error", 5);
                return 0;
                temp_close = 0;
                temp_open = 0;
            }
            
        }

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            open++;
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            close = open;
        }


        if ((str[i - 1] == '(' && str[i] == ')') || (str[i - 1] == '[' && str[i] == ']') || (str[i - 1] == '{' && str[i] == '}'))
        {
            if (open == close)
            {
                write(1, "OK", 2);
                return 0;
            }
            
        }
        

        i++;
    }

    write(1, "OK", 2);
    
    return 0;
}
