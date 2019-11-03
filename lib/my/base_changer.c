/*
** EPITECH PROJECT, 2019
** base and operand changer
** File description:
** change custom base and operand to have a clean base and operand
*/

void string_changer(char *str, char *operand, int size)
{
    int i;
    int j;
    char *normal_operand = "()+-*/%";

    for (i = 0; i < size; i++) {
        for (j = 0; j < 7; j++) {
            if (str[i] == operand[j]) {
                str[i] = normal_operand[j];
            }
        }
    }
}

void base_changer(char *str, char *base, int size)
{
    int i;
    int j;
    char *normal_base = "0123456789";

    for (i = 0; i < size; i++) {
        for (j = 0; j < 10; j++) {
            if (str[i] == base[j]) {
                str[i] = normal_base[j];
            }
        }
    }
}