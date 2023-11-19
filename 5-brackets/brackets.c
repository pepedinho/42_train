#include <unistd.h>



int main(int argc, char const *argv[])
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
    
    int open = open_bracket + open_cbrace + open_par;
    int close = close_bracket + close_cbrace + close_par;

    while (argv[argc - 1][i] != '\0' )
    {
        if (open != close)
        {
            int j = i - 1;
            while (argv[argc - 1][j] != '\0')
            {


               if (argv[argc - 1][j] == '(' || argv[argc - 1][j] == '{' || argv[argc - 1][j] == '[')
               {
                    temp_open++;
               }
               else if (argv[argc - 1][j] == ')' || argv[argc - 1][j] == '}' || argv[argc - 1][j] == ']')
               {
                    temp_close++;
               }
               

                if (temp_open == temp_close)
                {
                    
                }
                else
                {
                    write(1, "Error", 5);
                }
            
                j++;
            }
            
        }

        if (argv[argc - 1][i] == '(' || argv[argc - 1][i] == '{' || argv[argc - 1][i] == '[')
        {
            if (argv[argc - 1][i] == '(')
            {
                open_par++;
            }
            else if (argv[argc - 1][i] == '{')
            {
                open_cbrace++;
            }
            else
            {
                open_bracket++;
            }
            open = open_bracket + open_cbrace + open_par;
        }
        else if (argv[argc - 1][i] == ')' || argv[argc - 1][i] == '}' || argv[argc - 1][i] == ']')
        {
            if (argv[argc - 1][i] == ')')
            {
                close_par++;
            }
            else if (argv[argc - 1][i] == '}')
            {
                close_cbrace++;
            }
            else
            {
                close_bracket++;
            }
            close = open_bracket + open_cbrace + open_par;
        }


        if ((argv[argc - 1][i] == '(' && argv[argc - 1][i + 1] == ')') || (argv[argc - 1][i] == '[' && argv[argc - 1][i + 1] == ']') || (argv[argc - 1][i] == '{' && argv[argc - 1][i + 1] == '}'))
        {
            if (open == close)
            {
                write(1, "OK", 2);
                return 0;
            }
            
        }
        

        i++;
    }
    
    return 0;
}
