/*
** EPITECH PROJECT, 2019
** divisator
** File description:
** Ceci va probablement gérer les divisions
*/

#include <stdlib.h>
#include "eval_expr.h"
#include "my.h"

char *numer_and_or_demon_neg(char *numer, char *denom,
        char *cpy_numer, char *cpy_denom)
{
    char *rest;

    my_strcpy(cpy_numer, numer);
    my_strcpy(cpy_denom, denom);
    cpy_numer[0] = '0';
    cpy_denom[0] = '0';
    rest = modulo(cpy_numer, cpy_denom);
    if (denom[0] == '-' && numer[0] != '-') {
        rest = el_soustractor(rest, cpy_denom);
    } else {
        rest[0] = '-';
        return (rest);
    }
}

char *el_modulator(char *numer, char *denom)
{
    char *rest;
    char *cpy_numer = malloc(sizeof(char) * my_strlen(numer) + 1);
    char *cpy_denom = malloc(sizeof(char) * my_strlen(denom) + 1);
    char *tmp_num;

    if (denom[0] == '-' && numer[0] != '-' ||
        numer[0] == '-' && denom[0] == '-') {
        rest = numer_and_or_demon_neg(numer, denom, cpy_numer, cpy_denom);
        return (rest);
    } else if (numer[0] == '-' && denom[0] != '-') {
            my_strcpy(cpy_numer, numer);
            my_strcpy(cpy_denom, denom);
            cpy_numer[0] = '0';
            cpy_denom[0] = '0';
            rest = modulo(cpy_numer, cpy_denom);
            rest = el_soustractor(rest, cpy_denom);
            rest[0] = '0';
    } else return (modulo(numer, denom));
}

char *modulo(char *numer, char *denom)
{
    int cpt = 0;
    int c = 1;
    int j = 0;
    int k = 0;
    char *dif = el_cutator(numer, denom);
    char *tmp, *quotient;

    quotient = malloc(sizeof(char) * my_strlen(numer) + 2), quotient[0] = '0';
    for (int j = my_strlen(dif) - 1 ; numer[j] != '\0' ; j++, c++) {
        tmp = malloc(sizeof(char) * my_strlen(denom) * my_strlen(numer) + 2);
        for (int i = 0 ; tmp[0] != '-' ; i++) {
            tmp = el_soustractor(dif, denom);
            if (tmp[0] != '-')
                dif = tmp, cpt++;
        } quotient[c] = cpt + '0', cpt = 0;
        if (quotient[c] == 'b')
            quotient[c] = '0';
        k = my_strlen(dif);
        dif[k] = numer[j + 1];
    } return (dif);
}