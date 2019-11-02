/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** all functions
*/


#ifndef EVAL_H_
#define EVAL_H_

char *el_divisator(char *numer, char *denom);
int prob_detector(char *denom);
char *divide(char *numer, char *denom);
char *el_cutator(char *numer, char *denom);
int nbr1_smaller(char *nbr1, char *nbr2);
int factor(char **num, char operand, int signes, int pos);
int sum(char **num, char operand, int signes, int pos);
char *calc_fork(char **num, char *op, int signes);
int nbr_signes(char *calc, int *signes);
void padofactor(char **num, char *op, int *signes);
void padosum(char **num, char *op, int *signes);
char *numer_and_or_demon_neg(char *numer, char *denom,
    char *cpy_numer, char *cpy_denom);
char *el_modulator(char *numer, char *denom);
char *modulo(char *numer, char *denom);
char *el_multiplicator(char *num1, char *num2);
char *el_additionator(int l, char **res, char *num1, char *num2);
char *returnator(char *result, char *num1, char *num2);
void my_put_nbr_neg(int *nb, _Bool *over);
int my_put_nbr(int nb); // aussi dans my.h ???
void my_putchar(char c); // aussi dans my.h ???
void fill_calc_poi(int last_open_bra, int first_close_bra,
    char *calc_poi, char *expr);
void fill_expr_w_a(int last_open_bra, int first_close_bra, char *expr);
void calc_num_size(char *calc_poi, char **num);
void fill_num(char *calc_poi, char **num, char *op);
char *pre_clac_fork(char *calc_poi, int signes);
void find_bra(char *str, int *first_close_bra, _Bool *find, int *last_open_bra);
char *brackets(char *expr, int len);
char *parsayaya(char const *av1, char const *av2,
    char const *expr, unsigned int size);
char *eval_expr(char const *av1, char const *av2,
    char const *expr, unsigned int size);
void fill_new_str(char *str, char *res, char *new_str, int res_size);
char *replace_expr(char *str, char *res);
void find_a(char *str, int *last_a_pos, int *num_a);
char *l1_smaller_than_l2(char *tmp_num, char *num1, int l1, int l2);
char *el_soustractor(char *num1, char *num2);
char *el_soureturnator(char *num1, char *num2, char *result);
char *substraction(char *num1, char *num2);
char *num1_and_num2_neg(char *num1, char *num2, char *result);
char *make_tmp_n1(char *num1);
char *make_tmp_n2(char *num2);
char *num1_smaller_than_num2(int i, char *result);
char *el_sumator(char *num1, char *num2);
char *addsum(char *num1, char *num2);
char *sum_result(char *num1, char *num2, char *result);

/*
char *brackets(char *str, int len);
int parser_comme_jaja(const char *str);
int isnum_neg(char *calc, int *num, int pos);
char *pre_clac_fork(char *calc_poi, int signes);
int factor(char **num, char operand, int signes, int pos);
int sum(char **num, char operand, int signes, int pos);
char *calc_fork(char **num, char *op, int signes);
int nbr_signes(char *calc, int *signes);
void fill_new_str(char *str, char *res, char *new_str, int res_size);
int size_of_res(int res);
char *replace_expr(char *str, char *res);
void my_putchar(char c);
int my_put_nbr(int nb);
void fill_calc_poi(int last_open_bra, int first_close_bra,
        char *calc_poi, char *expr);
char *parsayaya(char const *av1, char const *av2,
        char const *expr, unsigned int size);
void fill_expr_w_a(int last_open_bra, int first_close_bra, char *expr);
void calc_num_size(char *calc_poi, char **num);
void fill_num(char *calc_poi, char **num, char *op);
void put_zero(char **num, int signes);
void padofactor(char **num, char *op, int *signes);
void padosum(char **num, char *op, int *signes);
void find_a(char *str, int *last_a_pos, int *num_a);
char *el_multiplicator(char *num1, char *num2);
char *el_additionator(int l, char **res, char *num1, char *num2);
char *returnator(char *result, char *num1, char *num2);
char *eval_expr(char const *av1, char const *av2,
    char const *expr, unsigned int size);
void find_bra(char *str, int *first_close_bra,
        _Bool *find, int *last_open_bra);
int nbr1_smaller(char *nbr1, char *nbr2);
char *divide(char *numer, char *denom);
char *el_cutator(char *numer, char *denom);
char *el_divisator(char *numer, char *denom);
int prob_detector(char *denom);
char *el_soustractor(char *num1, char *num2);
char *substraction(char *num1, char *num2);
char *el_soureturnator(char *num1, char *num2, char *result);
char *numer_and_or_demon_neg(char *numer, char *denom,
        char *cpy_numer, char *cpy_denom);
char *el_modulator(char *numer, char *denom);
char *modulo(char *numer, char *denom);
char *el_sumator(char *num1, char *num2);
char *addsum(char *num1, char *num2);
char *sum_result(char *num1, char *num2, char *result);
char *num1_and_num2_neg(char *num1, char *num2, char *result);
char *make_tmp_n1(char *num1);
char *make_tmp_n2(char *num2);
char *num1_smaller_than_num2(int i, char *result);
*/
#endif
