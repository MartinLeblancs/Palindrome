/*
** EPITECH PROJECT, 2020
** execute_palindrome
** File description:
** execute_palindrome
*/

#include <stdlib.h>
#include "../include/palindrome.h"

int check_numbers(struct palindrome *p, int current_number_rev)
{
    if (current_number_rev < 0)
        return (-1);
    if (p->find_palindrome < 0)
        return (-1);

    return (0);
}

int check_for_n(struct palindrome *p, char *str, char *rev_str, int nbr_rev)
{
    if (my_strlen(str) > 10 || my_strlen(rev_str) > 10)
        return (-1);
    if ((p->find_palindrome + nbr_rev) > 2147483647
        || p->find_palindrome < 0)
        return (-1);
    if (check_palindrome(p, convert_base(p->find_palindrome, p->b)) == 0)
        return (0);

    return (2);
}

int algo_palindrome_n(struct palindrome *p)
{
    char *string = NULL;
    char *reverse_string = NULL;
    int current_number_rev = 0;

    p->find_palindrome = p->number;
    if (check_palindrome(p, convert_base(p->find_palindrome, p->b)) == 0)
        return (0);
    while (1) {
        if (p->iterations > 100)
            return (-1);
        string = my_itoa(convert_base(p->find_palindrome, p->b));
        reverse_string = my_revstr(string);
        current_number_rev = convert_to_decimal(reverse_string, p->b);
        p->find_palindrome = p->find_palindrome + current_number_rev;
        p->iterations++;
        if (check_for_n(p, string, reverse_string, current_number_rev) != 2)
            return (check_for_n(p, string, reverse_string, current_number_rev));
    }
}

void execute_palindrome(struct palindrome *p)
{
    if (p->number != -1) {
        if (algo_palindrome_n(p) == 0)
            display_n(p);
        else
            display_not_found();
    }
    if (p->palindrome != -1) {
        if (algo_palindrome_p(p) == -1)
            display_not_found();
    }
}