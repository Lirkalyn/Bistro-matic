/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** all functions
*/


#ifndef EVAL_H_
#define EVAL_H_

char *el_divisator(char *num, char *denom);
char *divide(char *num, char *denom);
char *el_cutator(char *num, char *denom);
int nbr1_smaller(char *nbr1, char *nbr2);
int factor(char **num, char operand, int signes, int pos);
int sum(char **num, char operand, int signes, int pos);
char *calc_fork(char **num, char *op, int signes);
int nbr_signes(char *calc, int *signes);
void padofactor(char **num, char *op, int *signes);
void padosum(char **num, char *op, int *signes);
char *num_and_or_demon_neg(char *num, char *denom,
    char *cpy_num, char *cpy_denom);
char *el_modulator(char *num, char *denom);
char *modulo(char *num, char *denom);
char *el_multiplicator(char *num1, char *num2);
char *el_additionator(int l, char **res, char *num1, char *num2);
char *returnator(char *result, char *num1, char *num2);
void my_put_nbr_neg(int *nb, _Bool *over);
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
int clean(char *str);
char *complete_res(char const *expr, char *res, unsigned int size);
char *l1_smaller_than_l2(char *tmp_num, char *num1, char *num2);
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
char *operator_in_the_base(char *base);
char *two_identical_digits(char *base);
char *invalid_expression(char *str);
char *unknown_digit(char *str);
char *not_enought_brackets(char *str);

#endif

