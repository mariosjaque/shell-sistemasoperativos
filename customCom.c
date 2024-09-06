// customCom.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include "customCom.h"

// Función para manejar comandos personalizados
bool customs(char **comando) {
    if (strcmp(comando[0], "exit") == 0) {
        exit(0);
    }
    if (strcmp(comando[0], "cd") == 0) {
        if (comando[1] == NULL) {
            fprintf(stderr, "Error: Se esperaba un argumento para cd.\n");
        } else {
            if (chdir(comando[1]) != 0) {
                perror("Error");
            }
        }
        return true;
    }
    if (strcmp(comando[0], "set") == 0) {
        if (comando[1] == NULL || comando[2] == NULL || comando[3] == NULL) {
            fprintf(stderr, "Error: Se esperaban dos argumentos para set.\n");
        } else {
            if (strcmp(comando[1], "recordatorio") == 0) {
                int aux = atoi(comando[2]);
                if (aux > 0) {
                    pid_t pid = fork();
                    if (pid == 0) { // Proceso hijo
                        printf("\nSe ha establecido el recordatorio en %d segundos.\n", aux);
                        sleep(aux);
                        printf("\n\033[1;31mRecordatorio: \033[0m");
                        for (int i = 3; comando[i] != NULL; i++) {
                            printf("%s ", comando[i]);
                        }
                        printf("\n");
                        exit(0);
                    } if (pid < 0) {
                        perror("Error al crear el proceso hijo");
                    }
                } else {
                    fprintf(stderr, "Error: El tiempo del recordatorio debe ser mayor a 0.\n");
                }
            }
        }
        return true;
    }
    /*
    if (strcmp(comando[0], "favs") == 0) {

    }
    */
    return false;
}