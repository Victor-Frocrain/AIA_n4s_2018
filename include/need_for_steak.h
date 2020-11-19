/*
** EPITECH PROJECT, 2018
** xyz.h
** File description:
** xyz.h
*/

#ifndef XYZ_H_
#define XYZ_H_

#include "my.h"
#include "my_printf.h"
#include "get_next_line.h"

#define SLEEP (200000)

bool my_strstr(char *src, char *to_find);
int need_for_steak(void);
char *send_info(char *str);
char **str_to_word(char *str, char c);
float is_turn(float *datas);
void manage_speed(float *datas);
void get_infos(float *datas);

#endif /* XYZ_H_ */
