/* ***************************************************************************** */
/*                                                                               */
/*       //   // //+## /+| ||+##+\\    //+## /+\              :::      ::::::::  */
/*      //   // //    //|| ||     \\  //    // \\           :+:      :+:    :+:  */
/*     //   // //    // || ||     // //    //   \\        +:+ +:+         +:+    */
/*    //+#+// /+#+  //  || ||    // /+#+  //+##+//      +#+  +:+       +#+       */
/*   //   // //    /+##+|| ||   // //    //\\         +#+#+#+#+#+   +#+          */
/*  //   // //    //    || ||  // //    //  \\             #+#    #+#            */
/* //   // //+## //     || ||#// //+#+ //    \\           ###   ########.fr      */
/*       |10            |25                      |50       nborbiuk.C            |82
/* ***************************************************************************** */

#include <unistd.h>                                                              //
#include <stdlib.h>                                                              //

/*************************/

void    ft_putchar(char c)                                                       //displays a character in the standard output;
{
   write(1, &c, 1);
}

/*************************/

void    ft_putstr(char *str)                                                     //displays string in the standard output;
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

/*************************/

void    ft_putnbr(int nb)                                                        //displays a number as a string;
{
    if (nb < 0)
    {
        ft_putchar('-');
        if (nb == -2147483648)
        {
            ft_putchar('2');
            nb = nb % 1000000000;
        }
        nb = -nb;
    }
    if (nb >= 0 && nb <= 9)
        ft_putchar(48 + nb);
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

/*************************/

int     ft_atoi(char *str)                                                       //returns the number from the string;
{
    int i;
    int minus;
    int res;

    i = 0;
    minus = 0;
    res = 0;
    while (str[i] >= 1 && str[i] <= 32)
        i++;
    if (str[i] == '-')
        minus = 1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10;
        res = res + str[i] - 48;
        i++;
    }
    if (minus)
        return (-res);
    else
        return (res);
}

/*************************/

char    *ft_strcpy(char *dest, char *src)                                        //returns copy of null-terminated string;
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}

/*************************/

char    *ft_strncpy(char *dest, char *src, unsigned int n)                       //returns copy of null-terminated string by n-symbol;
{
	unsigned int i;

	i = 0;
	while (src != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*************************/

char    *ft_strstr(char *str, char *to_find)                                     //returns the pointer to the place of entry "to_find" in "str";
{
    int i;
    int j;
    int k;

    i = 0;
    if (to_find[0] == '\0')
        return (str);
    while (str[i] != '\0')
    {
        k = i;
        j = 0;
        while (str[k] == to_find[j])
        {
            k++;
            j++;
            if (to_find[j] == '\0')
                return (&str[i]);
        }
        i++;
    }
    return (NULL);
}

/*************************/

int     ft_strcmp(unsigned char *s1, unsigned char *s2)                          //returns the difference of not the same characters in the string;
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0')
        i++;
    return (s1[i] - s2[i]);
}

/*************************/

int     ft_strncmp(char *s1, char *s2, unsigned int n)                           //returns the difference of not the same characters in the string to the n-character;
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] != '\0' && n > 0)
    {
        i++;
        n--;
    }
    return (s1[i] - s2[i]);
}

/*************************/

char    *ft_strupcase(char *str)                                                 //the function returns a string in which all upercase letters;
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] = (str[i] - 32);
        i++;
    }
    return (str);    
}

/*************************/

char    *ft_strlowcase(char *str)                                                //the function returns a string in which all lowercase letters;
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = (str[i] + 32);
        i++;
    }
    return (str);
}

/*************************/

char    *ft_strcapitalize(char *str)                                             //the function returns a string in which all words begin with a capital letter;
{
    int i;

    i = 0;
    str = ft_strlowcase(str);    
    if (str[i] >= 97 && str[i] <= 122)
    {
        str[i] = str[i] - 32;
        i++;
    }
    while (str[i] != '\0')
    {
        if ((str[i - 1] >= 1 && str[i - 1] <= 47 || str[i - 1] >= 58 && str[i - 1] <= 64) && str[i] >= 97 && str[i] <= 122)
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

/*************************/

int     ft_str_is_alpha(char *str)                                               //the function checks whether the string contains only alphabetic characters;
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (str[i] >= 48 && str[i] <= 57)
            i++;
        else if (str[i] >= 65 && str[i] <= 90)
            i++;
        else if (str[i] >= 97 && str[i] <= 122)
            i++;
        else
            return (0);
    }
    return (1);
}

/*************************/

int     ft_str_is_numeric(char *str)                                             //the function checks whether the string contains only digits;
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!(str[i] >= 48 && str[i] <= 57))
            return (0);
        i++;
    }
    return (1);
}

/*************************/

int     ft_str_is_lowercase(char *str)                                           //the function checks whether the string contains only lowercase letters;
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (!(str[i] >= 97 && str[i] <= 122))
            return (0);
        i++;
    }
    return (1);
}

/*************************/

int     ft_str_is_uppercase(char *str)                                           //the function checks whether the string contains only upercase letters;
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (!(str[i] >= 65 && str[i] <= 90))
            return (0);
        i++;
    }
    return (1);
}

/*************************/

int     ft_str_is_printable(char *str)                                           //the function checks whether the string contains only printable characters;
{
    int i;

    i = 0;
    if (str[i] == '\0')
        return (1);
    while (str[i] != '\0')
    {
        if (!(str[i] >= 32 && str[i] <= 127))
            return (0);
        i++;
    }
    return (1);
}

/*************************/

int     ft_strlen(char *str)                                                     //returns the length of the string;
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

/*************************/

char    *ft_strcat(char *dest, char *src)                                        //thr function appends source string to the destination string;
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(dest);
    while (src[i] != '\0')
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

/*************************/

char    *ft_strncat(char *dest, char *src, int nb)                               //thr function appends source string to the destination string to n-character;
{
    int i;
    int j;

    i = 0;
    j = ft_strlen(dest);
    while (src[i] != '\0' && i < nb)
    {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

/*************************/
/**FT_PUTNBR_BASE*********/

int     check_base(char *base)                                                   //chaeck a vailad of base in ft_putnbr_base();
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void    ft_putnbr_base(int nbr, char *base)                                      //the function displays a number in a base system onscreen;
{
	int	size_base;
	int	nbr_final[100];
	int	i;

	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[size_base])
			size_base++;
		while (nbr)
		{
			nbr_final[i] = nbr % size_base;
			nbr = nbr / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}

/*************************/
/**FT_ATOI_BASE***********/

int     ft_index(char c, char *str)                                              //chaeck a vailad of base in ft_atoi_base();
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

int		ft_atoi_base(char *str, char *base)                                      //the function returns a number in a base system;
{
	int 	i;
	int		res;
	int		minus;
	int		base_len;

	i = 0;
	res = 0;
	minus = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	while (str[i] >= 1 && str[i] <= 32)
		i++;
	if (str[i] == '-')
		minus = 1;
	if (str[i] == '+' || str[i] == '-')
		str++;
	while (ft_index(str[i], base) < base_len)
	{
		res = res * base_len;
		res = res - ft_index(str[i], base);
		i++;
	}
	if (minus)
		return (res);
	else
		return(-res);
}

/*************************/
/*************************/

void    ft_putstr_non_printable(char *str)                                       //ft_putstr, when character is not printable - display a "\hexnumber";
{
    int i;
    int charecter;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 32 && str[i] <= 127)
        {
            ft_putchar(str[i]);
            i++;
        }
        else if (str[i] >= 1 && str[i] <= 31)
        {
            charecter = str[i];
            ft_putchar('\\');
            ft_putnbr_base(charecter, "0123456789ABCDEF");
            i++;
        }
        else
            i++;
    }
}

/*************************/
void    ft_swap(int *a, int *b)                                                  //the function swaps the value of two integers;
{
    int buf;

    buf = *a;
    *a = *b;
    *b = buf;
}

/*************************/

char    *ft_strdup(char *s1)                                                     //returns identical string;
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*************************/

int     *ft_range(int min, int max)                                              //returns an array of integers from min to max;
{
    int *arr;
    int i;

    if (min >= max)
    {
        return (NULL);
    }
    arr = malloc(sizeof(int) * (max - min));
    i = 0;
    while (min < max)
    {
        arr[i] = min;
        min++;
        i++;
    }
    return (arr);
}

/*************************/


int     ft_ultimate_range(int **range, int min, int max)                         //returns a size of array of integers from min to max;
{
    int *arr;
    int i;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    arr = malloc(sizeof(int) * (max - min));
    i = 0;
    while (min < max)
    {
        arr[i] = min;
        min++;
        i++;
    }
    *range = arr;
    return (i);
}

/*************************/
/**FT_CONCAT_PARAMS*******/

char    *concat_str(int argc, char **argv)                                       //returns the lengths of all arguments;
{
    int i;
    int len;
    char *str;

    i = 1;
    len = 0;
    while(i < argc)
    {
        len += ft_strlen(argv[i]);
        i++;
    }
    str =  malloc(sizeof(char) * (len + 1));
    return (str);
}

char    *ft_concat_params(int argc, char **argv)                                 //the function returns one line what is created from arguments;
{
    char *str;
    int i;
    int j;
    int n;

    str = concat_str(argc, argv);
    i = 1;
    n = 0;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j] != '\0')
        {
            str[n] = argv[i][j];
            j++;
            n++;
        }
        i++;
    }
    str[n] = '\n';
    return str;
}

/*************************/
/**FT_SPLIT)WHITESPACES***/

int     ft_count_words(char *str)                                                //the function counts the number of words in a string;
{
    int i;
    int number;

    i = 0;
    number = 0;
    while (str[i] != '\0')
    {
        while (str[i] >= 1 && str[i] <= 32)
            i++;
        if (str[i] >= 33 && str[i] <= 127)
        {
            while (str[i] >= 33 && str[i] <= 127)
                i++;
            number++;           
        }  
    }
    return (number);
}

int     len_w(char *str, int i)                                                  //returns len of next word;
{
    int len;

    len = 0;
    if (str[i] != '\0' && str[i] >= 33 && str[i] <= 127)
        while (str[i] != '\0' && str[i] >= 33 && str[i] <= 127)
        {
            len++;
            i++;
        }
    return len;
}

char    **ft_split_whitespaces(char *str)                                        //the function returns arrays of words from the string;
{
    char **res;
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    if ((res = malloc(sizeof(char*) * (ft_count_words(str) + 1))) == NULL)
		return (NULL);
    while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] >= 1 && str[i] <= 32)
			i++;
		if (str[i] != '\0')
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * len_w(str, i) + 1)) == NULL)
				return (NULL);
			while (str[i] != '\0' && str[i] >= 33 && str[i] <= 127)
            {
				res[j][k] = str[i];
                k++;
                i++;
            }
			res[j][k] = '\0';
            j++;
		}
	}
	res[j] = NULL;
	return (res);
}

/*************************/
/*************************/

void    ft_print_word_table(char **tab)                                          //the function displays content of the array of words;
{
    int i;

    i = 0;
    while (1)
    {
        if (tab[i] == NULL)
            break;
        ft_putstr(tab[i]);
        ft_putchar('\n');
        i++;
    }
}

/*************************/

void    ft_foreach(int *tab, int length, void(*f)(int))                          //applis a function on all elements of the array;
{
    int i;

    i = 0;
    while(i < length)
    {
        f(tab[i]);
        i++;
    }
}

/*************************/

int     *ft_map(int *tab, int length, int(*f)(int))                              //applis a function on all elements of the array and returns it;
{
    int i;

    i = 0;
    while (i < length)
    {
        tab[i] = f(tab[i]);
        i++;
    }
    return (tab);
}

/*************************/

int     ft_any(char **tab, int(*f)(char*))                                       //returns 1 if, passed to the function f, at least one element returns 1;
{
    while (**tab++)
    {
        if (f(*tab) == 1)
        return (1);
    }
    return (0);
}

/*************************/

int     ft_count_if(char **tab, int(*f)(char*))                                  //returns number of elements that return 1, passed to thr function f;
{
    int i;

    i = 0;
    while (**tab++)
    {
        if(f(*tab) == 1)
            i++;
    }
    return (i);
}

/*************************/
/**FT_SORT_WORDTAB********/

void	ft_swap_tab(char **a, char **b)                                          //the function swaps the pointers on the strings;
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_wordtab(char **tab)                                              //the function sorts array of strings by ascii table;
{
	int	i;

	i = 0;
	while (tab[i + 1] != NULL)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			ft_swap_tab(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

/*************************/
/*************************/

char    *ft_getstr(int size)                                                     //returns an empty string of specified length ("size") including a place for '\0';
{
    char *str;

    str = malloc(sizeof(char) * (size + 1));
    if (size == 0)
        return (NULL);
    return (str);
}

/*************************/

int     ft_putlen_no_spaces(char *str)                                           //returns the length of the string without spaces;
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 1 && str[i] <= 32)
            i++;
        else
        {
            i++;
            j++;
        }
    }
    return (j);
}

/*************************/

char    *ft_strrev(char *str)                                                    //returns the string in reverse order;
{
    int i;
    int j;
    char buf;

    i = 0;
    j = ft_strlen(str) - 1;
    while (i < j)
    {
        buf = str[i];
        str[i] = str[j];
        str[j] = buf;
        i++;
        j--;
    }
    return (str);
}

/*************************/

char    *ft_str_no_spaces(char *str)                                             //returns the string without spaces;
{
    int i;
    int j;
    char *arr;

    arr = malloc(sizeof(char) * (ft_putlen_no_spaces(str) + 1));
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 1 && str[i] <= 32)
            i++;
        else
        {
            arr[j] = str[i];
            i++;
            j++;
        }
    }
    arr[j] = '\0';
    return (arr);
}

/*************************/

char    *ft_sort_char(char *str)                                                 //sorts the string by by ascending order;
{
    int i;
    int j;
    int size;
    char buf;

    i = 0;
    size = ft_strlen(str);
    while (i < size)
    {
        j = 0;
        while (j < size - i)
        {
            if (str[j] < str[j - 1])
            {
                buf = str[j];
                str[j] = str[j - 1];
                str[j - 1] = buf; 
            }
            j++;
        }
        i++;
    }
    return (str);
}

/*************************/

int     ft_check_void(char *str, int i)                                          //the function checks if the line is empty after the index; 
{                                                                                //index = i; i = [1,32];
    while (str[i] != '\0')
    {
        if (!(str[i] >= 1 && str[i] <= 32 && str[i] != '\0'))
            return (0);
        i++;
    }
    return (1);
}

/*************************/

int     ft_factorial(int nb)                                                     //returns the factorial of the specified number;
{
	if(nb < 0)
		return(0);
	if(nb == 0 || nb == 1)
		return(1);
	return nb * ft_factorial(nb - 1);
}

/*************************/

int     ft_itarative_factorial(int nb)                                           //returns the factorial of the specified number;
{
    if (nb < 0)
        return (-1);
    else if (nb == 0)
        return (0);
    else if (nb == 1)
        return (1);
    else
    {
        int i;
        int res;

        i = 0;
        res = 0;
        while (i <= nb)
        {
            res = res * i;
            i++;
        }
        return (res);        
    }
}

/*************************/

int     ft_power(int nb, int power)                                              //returns the number in power;
{
	if (power >= 2)
		return (nb * ft_power(nb, power - 1));
	else if (nb < 0)
        return (-1);
    else
		return (1);
}

/*************************/

int     ft_fibonacci(int nb)                                                     //returns a number from a Fibonacci numbers;
{
	if(nb < 0)
		return(-1);
	if(nb <=2)
		return(nb);
	return ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2);
}

/*************************/

int     ft_sqrt(int nb)                                                          //returns sqrt of number;
{
    if (nb < 0)
        return (-1);
    else
    {
        int i;

        i = 0;
        while (i * i < nb)
            i++;
        if (nb % i == 0)
            return (i);
        else
            return (0);
    }
}

/*************************/

int     ft_is_prime(int nb)                                                      //checks whether the number is prime;
{
    if (nb >= 2)
    {
        int i;

        i = 2;
        while (i < nb)
        {
            if (nb % i == 0)
                return (0);
            else
                i++;
        }
        return (1);
    }
    else
        return (0);
}

/*************************/

int     ft_find_next_prime(int nb)                                               //returns the next prime numbers after "nb";
{
    int i;

    i = nb;
    while (!(ft_is_prime(i)))
        i++;
    return (i);
}

/*************************/

int     ft_add_prime_sum(int nb)                                                 //returns the sum of all primes to "nb" inclusive;
{
    int i;
    int sum;

    i = 2;
    sum = 0;
    while (i <= nb)
    {
        if (ft_is_prime(i))
            sum = sum + i;
        i++;
    }
    return (sum);
}

/*************************/

int     ft_intlen(int *arr)                                                      //returns the length of the array of integers;
{
    int len;

    len = sizeof(arr) / sizeof(int);
    return (len);
}

/*************************/

int     *ft_sort_integer_table(int *tab, int size)                               //sorts the array of integer by ascending order;
{
    int i;
    int buf;
 
    i = 0;
    buf = 0;
    while (i < size)
    {
        while(i < size - 1)
        {
            if (tab[i] > tab[i + 1])
            {
                buf = tab[i + 1];
                tab[i + 1] = tab[i];
                tab[i] = buf;
            }
            i++;
        }
        i = 0;
        size--;
    }
    return tab;
}

/*************************/

char    *ft_bitstr(char *str)                                                    //returns a number in a binary system in string (________'\0');
{
    int oct;
    int div;
    char *arr;
    int i;

    oct = ft_atoi(str);
    if (oct < 0 || oct > 255)
        return (NULL);
    div = 128;
    arr = ft_getstr(8);
    i = 0;
    while (div != 0)
    {
        if (oct >= div)
        {
            arr[i] = '1';
            oct = oct % div;
        }
        else
            arr[i] = '0';
        i++;
        div = div / 2;
    }
    arr[i] = '\0';
    return (arr);
}

/*************************/

int     *ft_atoi_arr(char *str, int size)
{
    int i;
    int n;
    int *res;
    int minus;

    i = 0;
    n = 0;
    res = malloc(sizeof(int) * size);
    minus = 0;
    while (str[i] != '\0')
    {
        while (str[i] >= 1 && str[i] <= 32)
            i++;
        if (str[i] == '-')
            minus = 1;
        if (str[i] == '-' || str[i] == '+')
            i++;
        res[n] = 0;
        while (str[i] >= 48 && str[i] <= 57)
        {
            res[n] = res[n] * 10;
            res[n] = res[n] + str[i] - 48;
            i++;
        }
        if (minus)
            res[n] = -res[n];
        n++;
    }
    return (res);
}