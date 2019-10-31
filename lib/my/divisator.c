/*
** EPITECH PROJECT, 2019
** divisator
** File description:
** Ceci va probablement gérer les divisions
*/

#include <stdlib.h>
#include "include/eval_expr.h"
#include "include/my.h"

char *el_divisator(char *numer, char *denom)
{
    char *quotient;
    char *cpy_numer = malloc(sizeof(numer));
    char *cpy_denom = malloc(sizeof(denom));
    if (numer[0] == '-' && denom[0] == '-') {
        my_strcpy(cpy_numer, numer);
        my_strcpy(cpy_denom, denom);
        cpy_numer[0] = '0';
        cpy_denom[0] = '0';
        return (el_calculator(cpy_numer, cpy_denom));
    } else if (numer[0] == '-' || denom[0] == '-') {
        my_strcpy(cpy_numer, numer);
        my_strcpy(cpy_denom, denom);
        cpy_numer[0] = '0';
        cpy_denom[0] = '0';
        quotient = el_divisator(cpy_numer, cpy_denom);
        quotient[0] = '-';
        return (quotient);
    } else return (el_calculator(numer, denom));
}

char *el_calculator(char *numer, char *denom)
{
    int cpt = 0, c = 1, j = 0, k = 0;
    char *dif = el_cutator(numer, denom);
    char *tmp, *quotient;
    quotient = malloc(sizeof(numer) + 2), quotient[0] = '0';
    for (int j = my_strlen(dif) - 1 ; numer[j] != '\0' ; j++, c++) {
        tmp = malloc(sizeof(char) * my_strlen(denom) * my_strlen(numer) + 1);
        for (int i = 0 ; tmp[0] != '-' ; i++) {
            tmp = prepare_sub(dif, denom);
            if (tmp[0] != '-')
                dif = tmp, cpt++;
        }
        quotient[c] = cpt + '0', cpt = 0;
        k = my_strlen(dif);
        dif[k] = numer[j + 1];
    }
    return (quotient);
}

char *el_cutator(char *numer, char *denom)
{
    char *nbr_cut;
    nbr_cut = malloc(sizeof(char) * my_strlen(denom) * my_strlen(numer) + 1);
    if (my_strlen(numer) < my_strlen(denom)) {
        nbr_cut[0] = '0';
    } else if (nbr1_smaller(numer, denom) == 1) {
        for (int i = 0 ; i != (my_strlen(denom) + 1) ; i++)
            nbr_cut[i] = numer[i];
    } else if (nbr1_smaller(numer, denom) == 0) {
        for (int i = 0 ; i != my_strlen(denom) ; i++)
            nbr_cut[i] = numer[i];
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
