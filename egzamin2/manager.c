#include "manager.h"
#include "worker.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_processes() {
    char *names[] = {"Alice", "Bob", "Eve", "Tom"};
    pid_t pid;
    for (int i = 0; i < 4; i++) {
        pid = fork();
        if (pid == 0) {
            worker(names[i]);
            exit(0);
        }
    }
}

