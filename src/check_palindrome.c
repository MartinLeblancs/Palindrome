/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** palindrome
*/

#include <stdlib.h>
#include "../include/palindrome.h"

int check_imax(struct palindrome *p, char *original_string, char *rev_str)
{
    if (my_strcmp(original_string, rev_str) == 0
        && p->iterations <= p->i_max)
        return (0);
    else if (my_strcmp(original_string, rev_str) != 0
    && p->iterations > p->i_max)
        return (-1);
    else
        return (2);
}

int check_imin(struct palindrome *p, char *original_string, char *rev_string)
{
    if (my_strcmp(original_string, rev_string) == 0
        && p->iterations < p->i_min)
        return (2);
    if (my_strcmp(original_string, rev_string) == 0
        && p->iterations >= p->i_min)
        return (0);

    return (2);
}

int check_max_min(struct palindrome *p, char *orgn_string, char *rev_str)
{
    int return_value = 0;
    int return_value2 = 0;

    if (p->i_max != -1 && p->i_min == -1)
        return (check_imax(p, orgn_string, rev_str));
    else if (p->i_min != -1 && p->i_max == -1)
        return (check_imin(p, orgn_string, rev_str));
    else if (p->i_min != -1 && p->i_max != -1) {
        return_value = check_imin(p, orgn_string, rev_str);
        return_value2 = check_imax(p, orgn_string, rev_str);
        if (return_value == 0 && return_value2 == 0)
            return (0);
        return (-1);
    }
    else if (my_strcmp(orgn_string, rev_str) == 0)
        return (0);

    return (2);
}

int check_palindrome(struct palindrome *p, int number)
{
    char *string = NULL;
    char *original_string = NULL;
    char *reverse_string = NULL;

    if (number < 0)
        return (-1);
    string = my_itoa(number);
    original_string = malloc(sizeof(char) * my_strlen(string));
    my_strcpy(original_string, string);
    reverse_string = my_revstr(string);
    return (check_max_min(p, original_string, reverse_string));
}