/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "need_for_steak.h"

char *send_info(char *str)
{
    char *res;

    my_putstr(str);
    while (!(res = get_next_line(0)));
    return (res);
}

int main(void)
{
    return (need_for_steak());
}
