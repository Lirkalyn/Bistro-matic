/*
** EPITECH PROJECT, 2019
** sub
** File description:
** Make substraction
*/

#include <stdlib.h>

#include "my.h"

#define ATN(c) (c - '0')

#define NTA(d) (d + '0')

int is_nbr1_smaller(char *nbr1, char *nbr2)
{
    int l1 = my_strlen(nbr1);
    int l2 = my_strlen(nbr2);
    int i;

    if (l1 < l2)
        return (1);
    if (l2 > l1)
        return (0);
    for (i = 0; i < l1; i++) {
        if (ATN(nbr1[i]) < ATN(nbr2[i]))
            return (1);
        else if (ATN(nbr1[i]) > ATN(nbr2[i]))
            return (0);
    }
    return (0);
}

char *sub_remain_dig(char *number1, char *result, int diff, int carry)
{
    for (int i = diff - 1; i >= 0; i--)
    {
        if (number1[i] == '0' && carry > 0)
            result[i] = NTA(9);
        int sub = (ATN(number1[i]) - carry);
        if (i > 0 || sub > 0)
            result[i] = NTA(sub);
        carry = 0;
    }
}

char *sub(char *number1, char *number2, int diff, int neg)
{
    int carry = 0;
    int sub;
    int i;
    char *result = malloc(sizeof(char) * (my_strlen(number1) + 2));

    for (i = my_strlen(number2) - 1; i >= 0; i--) {
        sub = (ATN(number1[i + diff]) - ATN(number2[i])) - carry;
        if (sub < 0) {
            sub += 10;
            carry = 1;
        }
        else
            carry = 0;
        result[i] = NTA(sub);
    }
    sub_remain_dig(number1, result, diff, carry);
    if (neg == 1)
        result[0] = '-';
    return (result);
}

char *prepare_sub(char *number1, char *number2)
{
    char *empty;
    int diff;
    int neg = 0;
    char *result;

    if (is_nbr1_smaller(number1, number2) == 1){
        empty = number1;
        number1 = number2;
        number2 = empty;
        neg = 1;
    }
    diff = my_strlen(number1) - my_strlen(number2);
    result = sub(number1, number2, diff, neg);
    return (result);
}