/*
** EPITECH PROJECT, 2020
** revstr
** File description:
** revstr
*/

#include <stdlib.h>

int  my_strlen(char *str);

char *my_revstr(char *str)
{
    char temp = '\0';
    int idx = 0;
    int	lenght = my_strlen(str) - 1;

    while (idx <= lenght / 2) {
        temp = str[idx];
        str[idx] = str[lenght - idx];
        str[lenght - idx] = temp;
        idx += 1;
    }
    return (str);
}
