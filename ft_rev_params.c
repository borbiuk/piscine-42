// A program that displays all parameters in reverse order

#include "piscine.h"

int main(int argc, char **argv)
{
    int i;

    i = (argc - 1);
    while (i >= 1)
    {
        ft_putstr(argv[i]);
        if (i != 1)
            ft_putchar('\n');
        i--;
    }
    return (0);
}