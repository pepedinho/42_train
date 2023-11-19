#include "print_memory.h"

int main(void)
{
    int	tab[10] = {0, 231, 150, 235, 12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
