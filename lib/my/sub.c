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
    int j;
    int k;

    for (j = 0 ; nbr1[j] == '0' ; j++);
    for (k = 0 ; nbr2[k] == '0'; k++);
    if (l1 - j < l2 - k)
        return (1);
    if (l2 - k < l1 - j)
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
    int sub;

    for (int i = diff - 1; i >= 0; i--)
    {
        if (number1[i] == '0' && carry > 0)
            result[i] = '9';
        sub = (ATN(number1[i]) - carry);
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

char *zero_for_nbr2(char *number1, char *number2, int diff)
{
    char *num2 = "";

    num2 = malloc(sizeof(char) * (my_strlen(number1)));
    for (int i = 0; i != my_strlen(number1); i++)
        num2[i] = '0';
    for (int i = my_strlen(number1); i >= my_strlen(number1) - diff; i--)
        num2[i - my_strlen(number2) + diff] = number2[i - my_strlen(number2)];
    return (num2);
}

char *prepare_sub(char *number1, char *number2)
{
    char *empty;
    int diff;
    int neg = 0;
    char *result;
    char *num2 = "";

    if (is_nbr1_smaller(number1, number2) == 1){
        empty = number1;
        number1 = number2;
        number2 = empty;
        neg = 1;
    }
    diff = my_strlen(number1) - my_strlen(number2);
    number2 = zero_for_nbr2(number1, number2, diff);
    diff = my_strlen(number1) - my_strlen(number2);
    result = sub(number1, number2, diff, neg);
    return (result);
}