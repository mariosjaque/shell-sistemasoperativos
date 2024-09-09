// comandos.c

#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Función para manejar comandos
void manejar_comando(char **comando) {
    // Contar el número de pipes en el comando
    int num_pipes = 0;
    for (int i = 0; comando[i] != NULL; i++) {
        if (strcmp(comando[i], "|") == 0) {
            num_pipes++;
        }
    }

    // Crear los pipes necesarios
    int pipefds[2 * num_pipes];
    for (int i = 0; i < num_pipes; i++) {
        if (pipe(pipefds + i * 2) < 0) {
            perror("Error al crear pipe");
            exit(1);
        }
    }

    int j = 0;
    // Iterar sobre cada comando separado por pipes
    for (int i = 0; i <= num_pipes; i++) {
        char *cmd[100];
        int k = 0;
        // Separar el comando actual
        while (comando[j] != NULL && strcmp(comando[j], "|") != 0) {
            cmd[k++] = comando[j++];
        }
        cmd[k] = NULL;
        j++;

        // Crear un nuevo proceso para el comando actual
        pid_t pid = fork();
        if (pid == 0) {
            // Si no es el primer comando, redirigir la entrada estándar al pipe anterior
            if (i != 0) {
                if (dup2(pipefds[(i - 1) * 2], 0) < 0) {
                    perror("Error en dup2");
                    exit(1);
                }
            }
            // Si no es el último comando, redirigir la salida estándar al siguiente pipe
            if (i != num_pipes) {
                if (dup2(pipefds[i * 2 + 1], 1) < 0) {
                    perror("Error en dup2");
                    exit(1);
                }
            }
            // Cerrar todos los pipes en el proceso hijo
            for (int j = 0; j < 2 * num_pipes; j++) {
                close(pipefds[j]);
            }
            // Ejecutar el comando
            execvp(cmd[0], cmd);
            perror("Error en execvp");
            exit(1);
        } else if (pid < 0) {
            perror("Error al crear proceso hijo");
            exit(1);
        }
    }

    // Cerrar todos los pipes en el proceso padre
    for (int i = 0; i < 2 * num_pipes; i++) {
        close(pipefds[i]);
    }
    // Esperar a que todos los procesos hijos terminen
    for (int i = 0; i <= num_pipes; i++) {
        wait(NULL);
    }
}

// Función para captar la entrada del usuario
char** captar_entrada() {
    char *entrada = NULL;
    size_t tam = 0;
    // Leer la entrada del usuario
    if (getline(&entrada, &tam, stdin) == -1) {
        free(entrada);
        return NULL;
    }
    char **comandos = NULL;
    char *token = strtok(entrada, " \n");
    int i = 0;
    // Separar la entrada en tokens
    while (token != NULL) {
        comandos = realloc(comandos, (i + 1) * sizeof(char*));
        comandos[i] = strdup(token);
        token = strtok(NULL, " \n");
        i++;
    }
    comandos = realloc(comandos, (i + 1) * sizeof(char*));
    comandos[i] = NULL;
    free(entrada);
    return comandos;
}