#include "../include/libft.h"

// fonction qui trie un tableau d'entier dans l'ordre croissant
void ft_sort_integer_table(int *tab, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (tab[i] > tab[j])
      {
        int temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
      }
    }
  }
}