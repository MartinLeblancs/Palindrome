/*
** EPITECH PROJECT, 2020
** my_factrec_synthesis
** File description:
** my_factrec_synthesis
*/

int	my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb > 12)
        return (0);
    else if (nb == 0)
        return (1);
    else
        return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int i = 1;

    if (nb < 0)
        return (-1);
    if (nb == 0)
        return (0);
    else if (nb == 1)
        return (1);
    else
    {
        for (i = 1; i * i != nb; i++) {
            if (i > nb)
                return (-1);
        }
    }
    return (i);
}
