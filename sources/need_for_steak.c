/*
** EPITECH PROJECT, 2019
** need_for_steak
** File description:
** need_for_steak
*/

#include "need_for_steak.h"
#include <stdio.h>

void get_infos(float *datas)
{
    char *lidar = NULL;
    int i = my_strlen("1:OK:No errors so far:");
    char **info;

    lidar = send_info("GET_INFO_LIDAR\n");
    info = str_to_word(lidar + i, ':');
    for (int j = 0; info[j] && j < 32; j++) {
        datas[j] = strtof(info[j], NULL);
    }
    free(lidar);
    free(info);
}

float find_object_road(float *datas)
{
    float max = 0;
    int b_min = 0;
    int b_max = 31;

    for (int i = 0; i < 32; i++) {
        if (datas[i] > max) {
            max = datas[i];
            b_max = i;
            b_min = i;
        } else if (datas[i] == max)
            b_max = i;
    }
    return (b_min + (b_max - b_min) / 2);
}

void manage_turn(float *datas)
{
    float res = find_object_road(datas);
    char *str;

    if (res != 0) {
        res = is_turn(datas);
    }
    printf("WHEELS_DIR:%f\n", res);
    fflush(stdout);
    while (!(str = get_next_line(0)));
    free(str);
}

int need_for_steak(void)
{
    float datas[32];
    char *info;

    for (int i = 0; i < 32; i++)
        datas[i] = 3000;
    info = send_info("START_SIMULATION\n");
    free(info);
    info = send_info("CAR_FORWARD:0.1\n");
    do {
        free(info);
        get_infos(datas);
        manage_speed(datas);
        manage_turn(datas);
        info = send_info("GET_INFO_SIMTIME\n");
    } while (!my_strstr(info, "Track Cleared"));
    free(info);
    my_putstr("STOP_SIMULATION\n");
    return (MY_SUCCESS);
}
