/*
** EPITECH PROJECT, 2020
** convert_base
** File description:
** convert_base
*/

#include <stdlib.h>
#include "../include/palindrome.h"

int ctoi(char c)
{
    return (c - 48);
}

int convert_base(int nbr, int base)
{
    int i = 0;
    int final_nbr = 0;
    char *string = malloc(sizeof(char) * my_strlen(my_itoa(nbr)) + 1);
    char base_10[11] = "0123456789";

    for (i = 0; nbr != 0; i++) {
        string[i] = base_10[nbr % base];
        nbr = nbr / base;
    }
    string[i] = '\0';
    string = my_revstr(string);
    final_nbr = my_getnbr(string);
    free(string);

    return (final_nbr);
}

int convert_to_decimal(char *nbr, int base)
{
    int len = my_strlen(nbr) - 1;
    int len_nbr = len;
    int final_nbr = 0;
    int tmp = 1;

    if (base == 10)
        return (my_getnbr(nbr));
    for (; len_nbr >= 0; len_nbr--) {
        if (ctoi(nbr[len_nbr]) >= base)
            return (-1);
        final_nbr += ctoi(nbr[len_nbr]) * tmp;
        tmp *= base;
    }
    return (final_nbr);
}