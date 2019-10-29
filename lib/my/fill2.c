/*
** EPITECH PROJECT, 2019
** bistro
** File description:
** wesh
*/

#include "eval_expr.h"

void padofactor(char **num, char *op, int *signes)
{
    int i;
    int j;
    int si = *signes;

    for (i = 0; i < si; i++) {
        if (op[i] == '*' || op[i] == '/' || op[i] == '%') {
            factor(num, op[i], *signes, i);
            for (j = i; j < *signes; j++) {
                op[j] = op[(j + 1)];
            }
            for (j = (i + 1); j < *signes; j++) {
                num[j] = num[(j + 1)];
            }
            *signes -= 1;
        i = 0;
        }
    } // op, num, signes, 
}

void padosum(char **num, char *op, int *signes)
{
    int i;
    int j;
    int si = *signes;

    for (i = 0; i < si; i++) {
        if (op[0] == '+' || op[0] == '-') {
            sum(num, op[0], *signes, i);
            for (j = 0; j < *signes; j++) {
                op[j] = op[(j + 1)];
            }
            for (j = 1; j < *signes; j++) {
                num[j] = num[(j + 1)];
            }
            *signes -= 1;
            i = 0;
        }
    }
}