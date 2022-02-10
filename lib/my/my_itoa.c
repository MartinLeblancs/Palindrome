/*
** EPITECH PROJECT, 2020
** my_itoa
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int nb)
{
    int	len = 0;
    char *str = NULL;
    int	tmp = 0;

    tmp = nb;
    len = 0;
    while (tmp > 0) {
        tmp = tmp / 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = nb % 10 + '0';
        nb /= 10;
    }
    return (str);
}