/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** all functions
*/


#ifndef EVAL_H_
#define EVAL_H_

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
int is_nbr1_smaller(char *nbr1, char *nbr2);
char *sub_remain_dig_of_ayaya(char *number1, char *result, int diff, int carry);
char *sub_my_ayaya(char *number1, char *number2, int diff, int neg);
char *prepare_sub_my_ayaya(char * number1, char * number2);
char *el_multiplicator(char *num1, char *num2);
char *el_additionator(int l, char **res, char *num1, char *num2);
char *returnator(char *result, char *num1, char *num2);
int eval_expr(char const *av1, char const *av2,
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

#endif
