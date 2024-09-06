// comandos.c

#include "comandos.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Función para manejar comandos
void manejar_comando(char **comando) {
    pid_t pid = fork(); // Crea un nuevo proceso bifurcando el proceso actual.
    if (pid == 0) { // Si pid es 0, estamos en el proceso hijo.
        execvp(comando[0], comando); // Reemplaza el proceso hijo con el comando especificado.
        perror("Error en execvp"); // Si execvp falla, imprime un mensaje de error.
        exit(1); // Termina el proceso hijo con un código de error.
    } else { // Si pid no es 0, estamos en el proceso padre.
        int status; // Variable para almacenar el estado del proceso hijo.
        wait(&status); // Espera a que el proceso hijo termine y obtiene su estado.
    }
}

// Función para captar la entrada del usuario
char** captar_entrada() {
    char *entrada = NULL; // Variable para almacenar la entrada del usuario.
    size_t tam = 0; // Variable para almacenar el tamaño de la entrada.
    if(getline(&entrada, &tam, stdin) == -1) {
        free(entrada);
        return NULL;
    } // Lee la entrada del usuario desde la consola.
    char **comandos = NULL; // Variable para almacenar los comandos separados.
    char *token = strtok(entrada, " \n"); // Separa la entrada en tokens usando el espacio como delimitador.
    int i = 0; // Variable para almacenar el índice de los comandos.
    while (token != NULL) { // Mientras haya tokens en la entrada.
        comandos = realloc(comandos, (i + 1) * sizeof(char*)); // Reasigna memoria para almacenar un nuevo comando.
        comandos[i] = strdup(token); // Almacena el token como un nuevo comando.
        token = strtok(NULL, " \n"); // Obtiene el siguiente token de la entrada.
        i++; // Incrementa el índice de los comandos.
    }
    comandos = realloc(comandos, (i + 1) * sizeof(char*)); // Reasigna memoria para almacenar un puntero nulo al final.
    comandos[i] = NULL; // Establece el último comando como nulo.
    free(entrada); // Libera la memoria utilizada para almacenar la entrada.
    return comandos; // Devuelve los comandos separados.
}