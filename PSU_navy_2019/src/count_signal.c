/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** count_signal
*/
#include "my.h"
#include "my_navy.h"

int count_signal(void)
{
    int i = 0;
    int sig = 0;
    int tmp = 0;

    for (;tmp != 12; i++, sig = 0) {
        while (sig == 0)
            sig = wait_signal();
        tmp = sig;
    }
    return (i-1);
}

int wait_result_sig(void)
{
    int i = 0;

    while (i == 0)
        i = wait_signal();
    return (i);
}