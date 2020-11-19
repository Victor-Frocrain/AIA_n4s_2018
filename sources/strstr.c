/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** find str on str
*/

#include "ai.h"

bool my_strstr(char *src, char *to_find)
{
    int j = 0;
    int i = 0;

    if (!src || !to_find)
        return (false);
    for (; src[i] && to_find[j]; i++)
        (src[i] == to_find[j])?(j++):(j = 0);
    return ((j != 0 && i != 0 && to_find[j - 1] == src[i - 1]) || \
my_strlen(to_find) == 0);
}
