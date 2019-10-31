/*
** EPITECH PROJECT, 2019
** divisator
** File description:
** Ceci va probablement gérer les divisions
*/

#include <stdlib.h>
#include "include/eval_expr.h"
#include "include/my.h"

int el_ignorator(char *nbr1, char *nbr2)
{
    int i, j, k;
    int l1 = my_strlen(nbr1);
    int l2 = my_strlen(nbr2);

    for (j = 0 ; nbr1[j] == '0' ; j++);
    for (k = 0 ; nbr2[k] == '0'; k++);
    printf("k = %d \n", k);
    if (l1 - j < l2 - k)
        return (1);
    if (l2 - k < l1 - j)
        return (0);
    for (i = l1 - j; i < l1; i++) {
    if ((nbr1[i] - '0') < (nbr2[i] - '0'))
        return (1);
    else if ((nbr1[i] - '0') > (nbr2[i]- '0'))
        return (0);
    }
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

char *el_divisator(char *numer, char *denom, char *quotient)
{
    int cpt = 0, c, j = 0;
    char *result_sub = el_cutator(numer, denom);
    char *tmp , *cpy_res_sub;
    tmp = malloc(sizeof(char) * my_strlen(denom) * my_strlen(numer) + 1);
    for (int i = 0 ; tmp[0] != '-' ; i++) {
        tmp = prepare_sub(result_sub, denom);
        if (tmp[0] != '-') {
            result_sub = tmp, cpt++;
        }
    }
    for (c = 0 ; quotient[c] >= 48 && quotient[c] <= 57 ; c++ );
    quotient[c] = cpt + '0';
    j =  my_strlen(result_sub);
    cpy_res_sub = malloc(sizeof(char) * j + 1);
    my_strcpy(cpy_res_sub, result_sub);
    cpy_res_sub[j] = numer[j];
    if (el_ignorator(cpy_res_sub, denom) == 1)
        return (quotient);
    el_divisator(cpy_res_sub, denom, quotient);
}

int main(void)
{
    char *quotient, *test;
    char *numer = "0500";
    char *denom = "02";
    quotient = malloc(sizeof(char) * my_strlen(numer) + 1);
    test = el_divisator(numer, denom, quotient);
    my_putstr(test);
}