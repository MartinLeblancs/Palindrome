/*
** EPITECH PROJECT, 2020
** display
** File description:
** display
*/

#include "../include/palindrome.h"

void display_not_found(void)
{
    my_putstr("no solution\n");
}

void display_n(struct palindrome *p)
{
    my_put_nbr(p->number);
    my_putstr(" leads to ");
    my_put_nbr(p->find_palindrome);
    my_putstr(" in ");
    my_put_nbr(p->iterations);
    my_putstr(" iteration(s) in base ");
    my_put_nbr(p->b);
    my_putchar('\n');
}

void display_p(struct palindrome *p, int count)
{
    my_put_nbr(count);
    my_putstr(" leads to ");
    my_put_nbr(p->palindrome);
    my_putstr(" in ");
    my_put_nbr(p->iterations);
    my_putstr(" iteration(s) in base ");
    my_put_nbr(p->b);
    my_putchar('\n');
}