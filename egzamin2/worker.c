#include "worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    switch (sig) {
        case SIGHUP:
            printf("Odpoczywam\n");
            break;
        case SIGUSR1:
            printf("Startuję!\n");
            break;
        case SIGINT:
            printf("Kończę\n");
            exit(0);
        default:
            break;
    }
}

void worker(const char *name) {
    signal(SIGHUP, signal_handler);
    signal(SIGUSR1, signal_handler);
    signal(SIGINT, signal_handler);

    printf("%s: Gotowy do pracy\n", name);
    while (1) {
        char command[100];
        read(0, command, sizeof(command));

        if (strncmp(command, "Podaj imię", 11) == 0) {
            printf("My name is %s\n", name);
        } else if (strncmp(command, "PID?", 5) == 0) {
            printf("%s: My PID is %d\n", name, getpid());
        }
    }
}

