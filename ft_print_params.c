// The program that displays all parameters

#include "piscine.h"

int main(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        ft_putstr(argv[i]);
        if (i != argc - 1)
            ft_putchar('\n');
        i++;
    }
    return (0);
}