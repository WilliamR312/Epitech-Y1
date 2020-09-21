/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** signal
*/
#include "my.h"
#include "my_navy.h"

int synchro;

void handler(int sig, siginfo_t *info, void *ucontext)
{
    static int i = 0;

    if (i == 0) {
        synchro = info->si_pid;
        i++;
    } else
        synchro = sig;
}

int wait_signal(void)
{
    struct sigaction sa;
    static int i = 0;
    int result = 0;

    synchro = 0;
    sa.sa_sigaction = &handler;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, 0);
    sigaction(SIGUSR2, &sa, 0);
    if (i == 0) {
        i++;
        usleep(8000000);
    }
    result = synchro;
    synchro = 0;
    return (result);
}