/*
** EPITECH PROJECT, 2020
** check.c
** File description:
** check.c
*/

#include <unistd.h>
#include "../include/palindrome.h"

int check_p_arg(struct palindrome *p)
{
    char *string = NULL;
    char *reverse_string = NULL;
    int number_reverse = 0;
    int palindrome_converted = convert_base(p->palindrome, p->b);

    if (palindrome_converted !=  -1) {
        string = my_itoa(palindrome_converted);
        reverse_string = my_revstr(string);
        number_reverse = my_getnbr(reverse_string);
        if (number_reverse != palindrome_converted) {
            return (-1);
        }
    }
    return (0);
}

int check_number_arg(int ac, char **av)
{
    for (int y = 1; y != ac; y++) {
        for (int x = 0; x != my_strlen(av[y]); x++) {
            if (y % 2 == 0)
                if (av[y][x] < 48 || av[y][x] > 57) {
                    write(2, "Invalid argument\n", 18);
                    return (84);
                }
        }
    }
    return (0);
}

int check_max_min_arg3(char **av)
{
    if (my_strcmp(av[3], "-imin") != 0 && my_strcmp(av[3], "-imax") != 0)
        return (84);
    else
        return (0);
}

int check_args(int ac, char **av)
{
    if (my_strcmp(av[1], "-n") != 0 && my_strcmp(av[1], "-p") != 0)
        return (84);
    if (ac >= 5)
        if (my_strcmp(av[3], "-b") != 0 && check_max_min_arg3(av))
            return (84);
    if (ac >= 7)
        if (my_strcmp(av[5], "-imin") != 0 && my_strcmp(av[5], "-imax") != 0)
            return (84);
    if (ac >= 9)
        if (my_strcmp(av[7], "-imin") != 0 && my_strcmp(av[7], "-imax") != 0)
            return (84);
    if (check_number_arg(ac, av) == 84)
        return (84);

    return (0);
}

int check_struct(struct palindrome *p)
{
    if ((p->b <= 1 || p->b > 10) && p->b != -1) {
        write(2, "Error in 'b' arg\n", 18);
        return (84);
    }
    if (p->number < 0 && p->number != -1) {
        write(2, "Error in 'n' arg\n", 18);
        return (84);
    }
    if ((p->palindrome != -1 && p->palindrome < 0) || check_p_arg(p) == -1) {
        write(2, "Error in 'p' arg\n", 18);
        return (84);
    }
    if ((p->i_min < 0 || p->i_max < 0 || p->i_min > p->i_max)
        && p->i_min != -1 && p->i_max != -1)
        return (84);
    if (p->palindrome == -1 && p->number == -1)
        return (84);
    return (0);
}