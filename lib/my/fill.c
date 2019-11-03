/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** just put 0 LOL
*/

#include "eval_expr.h"

int factor(char **num, char operand, int signes, int pos)
{
    int i;

    if (operand == '*')
        num[pos] = el_multiplicator(num[pos], num[(pos + 1)]);
    else if (operand == '/')
        num[pos] = el_divisator(num[pos], num[(pos + 1)]);
    else
        num[pos] = el_modulator(num[pos], num[(pos + 1)]);
}

int sum(char **num, char operand, int signes, int pos)
{
    if (operand == '+')
        num[0] = el_sumator(num[(0)], num[1]);
    else if (operand == '-')
        num[0] = el_soustractor(num[(0)], num[1]);
}

char *calc_fork(char **num, char *op, int signes)
{
    int i;
    int j;
    int si = signes;

    padofactor(num, op, &signes);
    padosum(num, op, &signes);
    if (op[0] != '\0')
        calc_fork(num, op, signes);
    return num[0];
}

int nbr_signes(char *calc, int *signes)
{
    int i;

    for (i = 0 ; calc[i] != '\0'; i++) {
        if (calc[i] == '+' || calc[i] == '-'
            || calc[i] == '*' || calc[i] == '/' || calc[i] == '%')
            *signes += 1;
    }
}