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
int pre_clac_fork(char *calc_poi, int len, int signes);
int factor(int *num, char operand, int signes, int pos);
int sum(int *num, char operand, int signes, int pos);
int calc_fork(int *num, char *op, int signes);
int nbr_signes(char *calc, int *signes);
void fill_new_str(char *str, int res, char *new_str, int res_size);
int size_of_res(int res);
char *replace_str(char *str, int res);
void my_putchar(char c);
int my_put_nbr(int nb);
void fill_calc_poi(int last_open_bra, int first_close_bra,
        char *calc_poi, char *expr);
int parsayaya(char const *av1, char const *av2,
        char const *expr, unsigned int size);
void fill_expr_w_a(int last_open_bra, int first_close_bra, char *expr);
void calc_num_size(char *calc_poi, char **num);
void fill_num(char *calc_poi, char **num, char *op);
void put_zero(char **num);
void padosum(int *num, char *op, int *signes);
void padofactor(int *num, char *op, int *signes);

#endif
