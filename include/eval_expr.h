/*
** EPITECH PROJECT, 2019
** eval_expr
** File description:
** all functions to make work eval_expr
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
int parsayaya(char const *av1, char const *av2,
        char const *expr, unsigned int size);
void fill_expr_w_a(int last_open_bra, int first_close_bra, char *expr);
void calc_num_size(char *calc_poi, char **num);
void fill_num(char *calc_poi, char **num, char *op);
void put_zero(char **num, int signes);
void padofactor(char **num, char *op, int *signes);
void padosum(char **num, char *op, int *signes);
void find_a(char *str, int *last_a_pos, int *num_a);
int is_nbr1_smaller(char *nbr1, char *nbr2);
char *sub_remain_dig(char *number1, char *result, int diff, int carry);
char *sub(char *number1, char *number2, int diff, int neg);
char *prepare_sub(char *number1, char *number2);
char *el_multiplicator(char *num1, char *num2);
char *el_additionator(int l, char **res, char *num1, char *num2);
char *returnator(char *result, char *num1, char *num2);

#endif