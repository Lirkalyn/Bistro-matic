/*
** EPITECH PROJECT, 2019
** divisator
** File description:
** Ceci va probablement gérer les divisions
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char *el_modulator(char *numer, char *denom)
{
    char *rest;
    char *cpy_numer = malloc(sizeof(numer));
    char *cpy_denom = malloc(sizeof(denom));
    if (prob_detector(denom) == 84) {
        rest = "Can't divide by 0";
        return (rest);
    } if (denom[0] == '-' && numer[0] != '-' ||
          numer[0] == '-' && denom[0] == '-') {
        my_strcpy(cpy_numer, numer);
        my_strcpy(cpy_denom, denom);
        cpy_numer[0] = '0';
        cpy_denom[0] = '0';
        rest = el_calc(cpy_numer, cpy_denom);
        rest[0] = '-';
        return (rest);
    } else return (el_calc(numer, denom));
}

char *modulo(char *numer, char *denom)
{
    int cpt = 0, c = 1, j = 0, k = 0;
    char *dif = el_cutator(numer, denom);
    char *tmp, *quotient;
    quotient = malloc(sizeof(numer) + 2), quotient[0] = '0';
    for (int j = my_strlen(dif) - 1 ; numer[j] != '\0' ; j++, c++) {
        tmp = malloc(sizeof(char) * my_strlen(denom) * my_strlen(numer) + 1);
        for (int i = 0 ; tmp[0] != '-' ; i++) {
            tmp = el_prepstractor(dif, denom);
            if (tmp[0] != '-')
                dif = tmp, cpt++;
        }
        quotient[c] = cpt + '0', cpt = 0;
        if (quotient[c] == 'b')
            quotient[c] = '0';
        k = my_strlen(dif);
        dif[k] = numer[j + 1];
    }
    return (dif);
}
