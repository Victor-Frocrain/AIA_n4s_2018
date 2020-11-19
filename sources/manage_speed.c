/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** manage_speed.c
*/

#include "need_for_steak.h"

float get_medium_dist(float *datas)
{
    float res = 0;

    for (int i = 10; i < 20; i++)
        res += datas[i];
    return (res / 10);
}

void change_wheels_dir(float dir)
{
    char *str = NULL;

    printf("WHEELS_DIR:%f\n", dir);
    fflush(stdout);
    while (!(str = get_next_line(0)));
    free(str);
}

void manage_speed(float *datas)
{
    char *str = NULL;
    float dist = get_medium_dist(datas);
    float res = dist / 5000;

    if (dist < 100) {
        get_infos(datas);
        return;
    }
    printf("CAR_FORWARD:%f\n", res);
    fflush(stdout);
    while (!(str = get_next_line(0)));
    free(str);
}
