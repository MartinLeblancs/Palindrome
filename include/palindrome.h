/*
** EPITECH PROJECT, 2020
** palindrome.h
** File description:
** palindrome.h
*/

#ifndef PALINDROME_H
#define PALINDROME_H

struct palindrome{
    int number;
    int palindrome;
    int i_min;
    int i_max;
    int b;
    int iterations;
    int find_palindrome;
};

int	my_factrec_synthesis(int nb);
int my_squareroot_synthesis(int nb);
int my_getnbr(char const *str);
int  my_strlen(char *str);
int my_strcmp (const char *s1, const char *s2);
int check_args(int ac, char **av);
int check_struct(struct palindrome *p);
char *my_itoa(int nb);
int check_palindrome(struct palindrome *p, int number);
char *my_revstr(char *str);
char my_putstr(char *str);
int my_put_nbr(int nb);
int algo_palindrome_n(struct palindrome *p);
void execute_palindrome(struct palindrome *p);
void my_putchar(char c);
char *my_strcpy(char *dest, char *src);
void display_not_found(void);
void display_n(struct palindrome *p);
void display_p(struct palindrome *p, int count);
int algo_palindrome_p(struct palindrome *p);
int check_imin_p(struct palindrome *p);
int check_imin(struct palindrome *p, char *original_string, char *rev_string);
int check_p_arg(struct palindrome *p);
char *my_itoa(int nb);
int convert_base(int nbr, int base);
int convert_to_decimal(char *nbr, int base);
int check_max_min(struct palindrome *p, char *orgn_string, char *rev_str);
int check_palindrome_p(struct palindrome *p, int number);
int check_palindrome_n(struct palindrome *p, int number);


#endif