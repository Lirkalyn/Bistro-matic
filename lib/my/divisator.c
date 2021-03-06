/*
** EPITECH PROJECT, 2019
** divisator
** File description:
** Ceci va probablement gérer les divisions
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char *el_divisator(char *num, char *denom)
{
    char *quotient = "0";
    char *cpy_num = malloc(sizeof(char) * my_strlen(num) + 1);
    char *cpy_denom = malloc(sizeof(char) * my_strlen(denom) + 1);

    if (nbr1_smaller(num, denom) == 1 && my_strlen(num) <= my_strlen(denom))
        return (quotient);
    else if (num[0] == '-' && denom[0] == '-') {
        my_strcpy(cpy_num, num);
        my_strcpy(cpy_denom, denom);
        cpy_num[0] = '0';
        cpy_denom[0] = '0';
        return (divide(cpy_num, cpy_denom));
    } else if (num[0] == '-' || denom[0] == '-') {
        my_strcpy(cpy_num, num);
        my_strcpy(cpy_denom, denom);
        cpy_num[0] = '0';
        cpy_denom[0] = '0';
        quotient = divide(cpy_num, cpy_denom);
        quotient[0] = '-';
        return (quotient);
    } else return (divide(num, denom));
}

char *divide(char *num, char *denom)
{
    int cpt = 0;
    int c = 1;
    int j = 0;
    int k = 0;
    char *dif = el_cutator(num, denom);
    char *tmp, *quotient;

    quotient = malloc(sizeof(char) * my_strlen(num) + 2), quotient[0] = '0';
    for (int j = my_strlen(dif) - 1 ; num[j] != '\0' ; j++, c++) {
        tmp = malloc(sizeof(char) * my_strlen(denom) * my_strlen(num) + 1);
        for (int i = 0 ; tmp[0] != '-' ; i++) {
            tmp = el_soustractor(dif, denom);
            if (tmp[0] != '-')
                dif = tmp, cpt++;
        } quotient[c] = cpt + '0', cpt = 0;
        if (quotient[c] == 'b')
            quotient[c] = '0';
        k = my_strlen(dif);
        dif[k] = num[j + 1];
    } return (quotient);
}

char *el_cutator(char *num, char *denom)
{
    char *nbr_cut;

    nbr_cut = malloc(sizeof(char) * my_strlen(denom) * my_strlen(num) + 1);
    if (my_strlen(num) < my_strlen(denom)) {
        nbr_cut[0] = '0';
    } else if (nbr1_smaller(num, denom) == 1) {
        for (int i = 0 ; i != (my_strlen(denom) + 1) ; i++)
            nbr_cut[i] = num[i];
    } else if (nbr1_smaller(num, denom) == 0) {
        for (int i = 0 ; i != my_strlen(denom) ; i++)
            nbr_cut[i] = num[i];
    }
    return (nbr_cut);
}

int nbr1_smaller(char *nbr1, char *nbr2)
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