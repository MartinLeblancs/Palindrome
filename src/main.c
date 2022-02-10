/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/palindrome.h"

int put_strcmp(struct palindrome *p, char *string, char **av, int y)
{
    if (my_strcmp("-b", string) == 0)
        p->b = my_getnbr(av[y + 1]);
    if (my_strcmp("-n", string) == 0)
        p->number = my_getnbr(av[y + 1]);
    if (my_strcmp("-p", string) == 0)
        p->palindrome = my_getnbr(av[y + 1]);
    if (my_strcmp("-imax", string) == 0)
        p->i_max = my_getnbr(av[y + 1]);
    if (my_strcmp("-imin", string) == 0)
        p->i_min = my_getnbr(av[y + 1]);

    return (0);
}

void initialize_struct(int ac, char **av, struct palindrome *p)
{
    int count = 0;
    char *string = NULL;

    for (int y = 1; y != ac; y++) {
        string = malloc(sizeof(char) * 6);
        for (int x = 0; x != my_strlen(av[y]); x++, count++)
            string[count] = av[y][x];
        count = 0;
        put_strcmp(p, string, av, y);
        free(string);
    }
    if (p->b == -1)
        p->b = 10;
}

void set_struct(struct palindrome *p)
{
    p->palindrome = -1;
    p->number = -1;
    p->i_max = -1;
    p->i_min = -1;
    p->b = -1;
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 9) {
        write(2, "Invalid number of arguments\n", 29);
        return (84);
    }
    if (ac % 2 == 0) {
        write(2, "Invalid number of arguments\n", 29);
        return (84);
    }
    struct palindrome *p = malloc(sizeof(struct palindrome));
    set_struct(p);
    initialize_struct(ac, av, p);
    if (check_args(ac, av) == 84)
        return (84);
    if (check_struct(p) == 84)
        return (84);
    execute_palindrome(p);
    free(p);

    return (0);
}