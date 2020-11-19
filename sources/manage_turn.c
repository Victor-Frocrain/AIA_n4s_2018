/*
** EPITECH PROJECT, 2019
** n4s
** File description:
** manage_turn.c
*/

#include "need_for_steak.h"

float detect_direction(float *datas)
{
    float left = 0;
    float right = 0;
    float ratio = 0;

    for (int i = 0; i < 16; i++) {
        left += datas[i];
        /*if (datas[i] >= 3000)
            return (0);*/
    }
    for (int i = 16; i < 32; i++) {
        right += datas[i];
        /*if (datas[i] >= 3000)
            return (0);*/
    }
    ratio = left - right;
    if (left < 2000 && ratio <= 0)
        return (-1.0);
    if (right < 2000 && ratio >= 0)
        return (1.0);
    if (right > 3010 * 4 && left > 3010 * 4)
        return (0);
    /*if (ratio == 0 && left > right)
        return (1.0);
    if (ratio == 0 && right > left)
        return (-1.0);*/
    return (ratio);
}

/*float get_speed(void)
{
    char *str = NULL;
    float speed = 0;
    int j = my_strlen("1:OK:No errors so far:");

    my_putstr("GET_CURRENT_SPEED\n");
    str = get_next_line(0);
    for (int i = j; str && str[i]; i++)
        if (str[i] == ':') {
            str[i] = 0;
            break;
        }
    speed = strtof(str + j, NULL);
    return (speed);
}*/

float is_turn(float *datas)
{
    float left = detect_direction(datas);
    /*float speed = get_speed();

    if (speed < 0)
        return ((left < 0)?-1:1);*/
    while (left < -1.0 || left > 1.0)
        left /= 10;
    return (left);
}
