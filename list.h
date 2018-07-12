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

#include <stdlib.h>                                                              //
#include "ft_list.h"                                                             //structure of the list;

/*************************/

void print_list(t_list *list)                                                    //the function display the list;
{
    while (list)
    {
        ft_putstr(list->data);
        list = list->next;
    }
}

/*************************/

t_list  *add_link(t_list *begin_list, void *data)
{
    t_list *list;

    list = malloc(sizeof(t_list));
    if (list)
    {
        list->data = data;
        list->next = begin_list;
    }
    return (list);
}

/*************************/

t_list *ft_create_elem(void *data)                                               //the function create new element of the list;
{
    t_list *list;

    list = NULL;
    list = malloc(sizeof(t_list));
    if (list)
    {
        list->data = data;
        list->next = NULL;
    }
    return (list);
}

/*************************/

void    ft_list_push_back(t_list **begin_list, void *data)                       //the function add new end of the list;
{
    t_list *list;

    list = *begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        list->next = ft_create_elem(data);
    }
    else
        *begin_list = ft_create_elem(data);
}

/*************************/

void	ft_list_push_front(t_list **begin_list, void *data)                      //the function add new begin of the list;
{
    t_list *list;

    if (*begin_list)
    {
        list = ft_create_elem(data);
        list->next = *begin_list;
        *begin_list = list;
    }
    else
        *begin_list = ft_create_elem(data);
}

/*************************/

int     ft_list_size(t_list *begin_list)                                          //the function returns number of elements in the list;
{
    t_list *list;
    int i;

    list = begin_list;
    i = 0;
    while (list)
    {
        list = list->next;
        i++;
    }
    return (i);
}

/*************************/

t_list	*ft_list_last(t_list *begin_list)                                        //the function returns last element of the list;
{
    t_list *list;

    list = begin_list;
    if (list)
    {
        while (list->next)
            list = list->next;
        return (list);
    }
    return (NULL);
}

/*************************/

t_list	*ft_list_push_params(int argc, char **argv)                              //the function returns the list whith params;
{
    t_list *list;
    t_list *tmp;
    int i;
 
    if (argc == 1)
        return (NULL);
    i = 2;
    list = ft_create_elem(argv[1]);
    while (i < argc)
    {
        tmp = list;
        list = ft_create_elem(argv[i]);
        list->next = tmp;
        i++;
    }
    return (list);
}

/*************************/

void    ft_list_clear(t_list **begin_list)                                       //the function clears list;
{
    t_list *list;
    t_list *temp;

    list = *begin_list;
    while (list)
    {
        if (list->next)
            temp = list->next;
        else
            temp = NULL;
        free(list);
        list = temp;
    }
}

/*************************/

t_list  *ft_list_at(t_list *begin_list, unsigned int nbr)                        //the function returns nbr-element of the list;
{
    t_list *list;

    list = begin_list;
    while (nbr >= 0 && list)
    {
        nbr--;
        if (nbr == 0)
            return (list);
        list = list->next;
    }
    return (NULL);
}

/*************************/

void    ft_list_reverse(t_list **begin_list)                                     //the function reverses the list;
{
    t_list *first;
    t_list *rest;

    if (*begin_list == NULL)
        return;
    first = *begin_list;
    rest = first->next;
    if (rest == NULL)
        return;
    ft_list_reverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *begin_list = rest;
}

/*************************/

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    t_list *list;

    list = begin_list;
    while (list)
    {
        (*f)(list->data);
        list = list->next;
    }
}

/*************************/

void    ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp))
{
    t_list *list;

    list = begin_list;
    while (list)
    {
        if ((*cmp)(list->data, data_ref))
            (*f)(list->data);
        list = list->next;
    }
}

/*************************/

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp))
{
    t_list *list;

    list = begin_list;
    while (list)
    {
        if ((*cmp)(list->data, data_ref));
            return (list);
        list = list->next;
    }
}

/*************************/

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp))
{
    t_list *curr_list;
    t_list *last_list;

    curr_list = *begin_list;
    last_list = *begin_list;
    while (curr_list && curr_list->next)
    {
        if ((*cmp)(curr_list->data, data_ref))
        {
            last_list->next = curr_list->next;
            last_list = curr_list;
            curr_list = curr_list->next;
            free(last_list);
        }
        else
        {
            last_list = curr_list;
            curr_list = curr_list->next;
        }
    }
}

/*************************/

void    ft_list_merge(t_list *begin_list1, t_list *begin_list2)
{
    t_list *list;

    list = begin_list1;
    while (list)
        list = list->next;
    list->next = begin_list2;
}

/*************************/

void    ft_list_sort(t_list **begin_list, int (*cmp)())
{
    t_list  *list;
    void    *buf;

    list = *begin_list;
    while (begin_list->next)
    {
        if ((*cmp)(begin_list->data, begin_list->next->data))
        {
            buf = begin_list->data;
            begin_list->data =begin_list->next->data;
            begin_list->next->data = buf;
            begin_list = list;
        }
        else
            begin_list = begin_list->next;
    }
    begin_list = list;
}

/*************************/
/*************************/