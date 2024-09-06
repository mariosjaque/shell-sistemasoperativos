// signals.c

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "signals.h"

// Manejador de señales
void signal_handler(int signal) {
    switch(signal) {
        case SIGINT: // Señal de interrupción (Ctrl + C)
            printf("\nTerminando programa...\n");
        exit(0);
        case SIGCHLD: // Señal cuando un proceso hijo termina
            while (1) {
                int status;
                pid_t pid = waitpid(-1, &status, WNOHANG); // Espera a que cualquier proceso hijo termine
                if (pid <= 0) {
                    break;
                }
                if (WIFEXITED(status)) {
                    printf("Proceso hijo con PID %d terminó con código de salida %d.\n", pid, WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("Proceso hijo con PID %d terminó debido a la señal %d.\n", pid, WTERMSIG(status));
                }
            }
        break;
        case SIGTERM: // Señal de terminación (kill)
            printf("\nTerminando proceso...\n");
        exit(0);
        default: // Señal desconocida
            printf("\nSe ha recibido una señal desconocida.\n");
        break;
    }
}