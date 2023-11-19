#ifndef LIBFT
#define LIBFT
#include <unistd.h>

int ft_atoi(char *str);
void ft_div_mod(int a, int b, int *div, int *mod);
int ft_fibonacci(int index);
int ft_find_next_prime(int nb);
int ft_is_prime(int nb);
int ft_islower(int car);
int isupper(int car);
int ft_itterative_factorial(int nb);
void ft_putnbr_base(int nbr, char *base);
void ft_putnbr(int nb);
void ft_putstr(char *str);
void ft_sort_integer_table(int *tab, int size);
int ft_sqrt(int nb);
int ft_str_is_alpha(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_printable(char *str);
int ft_str_is_uppercase(char *str);
char *ft_strcapitalize(char *str);
char *ft_strcat(char *dest, char *src);
int ft_strcmp(char *s1, char *s2);
char *ft_strcpy(char *dest, char *src);
char *ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
int ft_strlen(char *str);
char *ft_strlowcase(char *str);
char *ft_strncat(char *dest, char *src, int nb);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strncpy(char *dest, char *src, int size);
char *ft_strrev(char *str);
char *ft_strstr(char *str, char *to_find);
char *ft_strupcase(char *str);
void ft_swap(int *a, int *b);
int ft_tolower(int car);
int ft_isprint(int car);
int ft_toupper(int car);
void ulstr(char *str);
void ft_ultimate_div_mod(int *a, int *b);
void print_memory(const void *addr, size_t size);

#endif