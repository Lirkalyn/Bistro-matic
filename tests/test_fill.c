/*
** EPITECH PROJECT, 2019
** bisro
** File description:
** test_fill.c
*/

#include <criterion/criterion.h>
#include "../lib/my/eval_expr.h"

Test(nbr_signes, normal_nbr_signes)
{
    char *calc = "3+6/42*8%7-7";
    int signes = 0;

    nbr_signes(calc, &signes);
    cr_assert(signes == 5);
}