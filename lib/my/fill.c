/*
** EPITECH PROJECT, 2019
** bootstrap-evalexpr
** File description:
** first file to make work eval_expr
*/

#include "eval_expr.h"

int factor(char **num, char operand, int signes, int pos)
{
    int i;
/*
    if (operand == '*')
        num[pos] = (num[pos] * num[(pos + 1)]);
    else if (operand == '/')
        num[pos] = (num[pos] / num[(pos + 1)]);
    else
        num[pos] = (num[pos] % num[(pos + 1)]);*/
}

int sum(char **num, char operand, int signes, int pos)
{/*
    if (operand == '+')
        num[0] = (num[(0)] + num[1]);
    else if (operand == '-')
        num[0] = (num[(0)] - num[1]);*/
}

char *calc_fork(char **num, char *op, int signes)
{
    int i;
    int j;
    int si = signes;

    printf("op = %s\n", op);
//    padofactor(*num, *op, &signes);
//    padosum(*num, *op, &signes);
/*    for (i = 0; i < si; i++) {
        if (op[i] == '*' || op[i] == '/' || op[i] == '%') {
            factor(num, op[i], signes, i);
            for (j = i; j < signes; j++) {
                op[j] = op[(j + 1)];
            }
            for (j = (i + 1); j < signes; j++) {
                num[j] = num[(j + 1)];
            }
            signes--;
        i = 0;
        }
    } // op, num, signes, 
    for (i = 0; i < si; i++) {
        if (op[0] == '+' || op[0] == '-') {
            sum(num, op[0], signes, i);
            for (j = 0; j < signes; j++) {
                op[j] = op[(j + 1)];
            }
            for (j = 1; j < signes; j++) {
                num[j] = num[(j + 1)];
            }
            signes--;
            i = 0;
        }
    }*/
//    if (op[0] != '\0')
//        calc_fork(num, op, signes);
//    return num[0];
    return "14";
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