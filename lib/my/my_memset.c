/*
** EPITECH PROJECT, 2019
** my_memset.c
** File description:
** Setup the memory
*/

#include "my.h"

void my_memset(char *str, char c)
{
    for (int i = 0; str && str[i]; i++)
        str[i] = c;
}
