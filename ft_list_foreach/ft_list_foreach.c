#include "ft_list_foreach.h"
#include <stdio.h>


void ft_list_foreach(t_list *beggin_list, void (*f)(void *))
{

    t_list *list_ptr = beggin_list;

    while (list_ptr != NULL)
    {
        (f)(list_ptr->data);
        list_ptr = list_ptr->next;
    }
}

void print_me(void* ptr)
{
    int *int_ptr = (int *)ptr;
    printf("%d\n", *int_ptr);
}


int main()
{
    t_list mylist[7];
    //t_list *current = &mylist;

    int tab[] = {1, 2, 3, 4, 5, 6, 7};
    int i = 0;
    
    while (i < 7)
    {
        mylist[i].data = &tab[i];

        if (i < 6)
        {
            mylist[i].next = &mylist[i + 1];
        }else
        {
            mylist[i].next = NULL;
        }

        i++;
    }
    
    ft_list_foreach(mylist, print_me);

    return 0;
}
