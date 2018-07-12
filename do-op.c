// Calculator for one mathematical operation with integers (+,-,*,/,%)
// here are the functions described in the header "pisice.h"

#include "piscine.h"

void    plus(int a, int b){
    ft_putnbr(a + b);
}

void    minus(int a, int b){
    ft_putnbr(a - b);
}

void    mult(int a, int b){
    ft_putnbr(a * b);
}

void    divis(int a, int b){
    if (b == 0)
    {
        ft_putstr("Stop: division by zero");
    }
    else
    {
        int res;

        res = a / b;
        ft_putnbr(res);
    }
}

void    mod(int a, int b){
    if (b == 0)
    {
        ft_putstr("Stop: modul by zero");
    }
    else
        ft_putnbr(a % b);
}

void    maker(int a, char action, int b)
{
    if (!a || !b || !action)
        action = '0';
    switch (action)
    {
        case ('+'):
            plus(a, b);
            break;
        case ('-'):
            minus(a, b);
            break;
        case ('*'):
            mult(a, b);
            break;
        case ('/'):
            divis(a, b);
            break;
        case ('%'):
            mod(a, b);
            break;
        default:
            ft_putnbr(0);
            break;
    }
}

void    ft_mathematical_action(char **argv)
{
    int a;
    int b;
    char action;

    action = argv[2][0];
    a = ft_atoi(argv[1]);
    b = ft_atoi(argv[3]);
    maker (a, action, b);
}

int     main (int argc, char **argv)
{
    if (argc != 4){
        return (0);
    }
    ft_mathematical_action(argv);
}