/*
** EPITECH PROJECT, 2019
** soustractor
** File description:
** Ceci va probablement gérer les soustractions
*/

#include <stdlib.h>
#include "my.h"
#include "eval_expr.h"

char *el_prepstractor(char *num1, char *num2)
{
    int l1 = my_strlen(num1);
    int l2 = my_strlen(num2);
    char *tmp_num;
    if (l1 < l2) {
        tmp_num = malloc(sizeof(num2));
        my_strcpy(tmp_num, num1);
        my_revstr(tmp_num);
        for (int i = l1 ; i != l2 ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (el_soureturnator(num1, num2, el_soustractor(tmp_num, num2)));
    } else if (l2 < l1) {
        tmp_num = malloc(sizeof(num1));
        my_strcpy(tmp_num, num2);
        my_revstr(tmp_num);
        for (int i = l2 ; i != l1 ; i++)
            tmp_num[i] = '0';
        my_revstr(tmp_num);
        return (el_soureturnator(num1, num2, (el_soustractor(tmp_num, num1))));
    } else {
        if (isit_smaller(num1, num2) == 1)
            return (el_soureturnator(num1, num2, el_soustractor(num1, num2)));
        else return el_soureturnator(num1, num2, el_soustractor(num2, num1));
    }
}

char *el_soureturnator(char *num1, char *num2, char *result)
{
    int i = my_strlen(result);
    if (isit_smaller(num1, num2) == 1 && my_strlen(num1) <= my_strlen(num2)) {
        if (result[i - 1] != '0')
            result[i] = '-';
        else result[i - 1] = '-';
        return (my_revstr(result));
    } else {
        if (result[i - 1] != '0')
            result[i] = '0';
        return (my_revstr(result));
    }
}

char *el_soustractor(char *num1, char *num2)
{
    int tmp;
    int c = 0;
    int carry = 0;
    int i = my_strlen(num1) - 1;
    char *result;
    result = malloc(sizeof(num1) + 1);
    for (i ; i != 0 ; i--, c++) {
        tmp = (num2[i] - '0') - ((num1[i] - '0') + carry);
        carry = 0;
        if (tmp < 0) {
            tmp = tmp +10;
            carry = 1;
        }
        result[c] = tmp + '0';
    }
    return (result);
}

int isit_smaller(char *nbr1, char *nbr2)
{
    int l1 = my_strlen(nbr1);
    int l2 = my_strlen(nbr2);
    int i;

    if (l1 < l2)
        return (1);
    for (i = 0; i < l1; i++) {
        if (nbr1[i] - '0' < nbr2[i] - '0')
            return (1);
        else if (nbr1[i] - '0' > nbr2[i] - '0')
            return (0);
    }
    return (0);
}
