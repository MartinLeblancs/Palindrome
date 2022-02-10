/*
** EPITECH PROJECT, 2020
** execute_palindrome_p.c
** File description:
** execute_palindrome_p.c
*/

#include "../include/palindrome.h"
#include <stdlib.h>

int check_if_can_print_p(struct palindrome *p, int count_display, int count)
{
    if (p->find_palindrome == p->palindrome) {
        if (check_palindrome(p, convert_base(p->find_palindrome, p->b)) == 0) {
            display_p(p, count);
            count_display++;
        }
    }

    return (count_display);
}

int algo_palindrome_p(struct palindrome *p)
{
    char *string = NULL;
    char *reverse_string = NULL;
    int current_number_rev = 0;
    int count = 1;
    int count_display = 0;

    for (count = 1; count <= p->palindrome; count++) {
        p->find_palindrome = count;
        for (p->iterations = 0; p->find_palindrome < p->palindrome;
        p->iterations++) {
            string = my_itoa(convert_base(p->find_palindrome, p->b));
            reverse_string = my_revstr(string);
            current_number_rev = convert_to_decimal(reverse_string, p->b);
            p->find_palindrome = p->find_palindrome + current_number_rev;
        }
        count_display = check_if_can_print_p(p, count_display, count);
    }
    if (count_display == 0)
        return (-1);
    return (0);
}