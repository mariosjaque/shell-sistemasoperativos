// favoritos.c

#include "favoritos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FAVS 1000
#define MAX_CMD_LEN 256

typedef struct {
    int num;
    char comando[MAX_CMD_LEN];
} Favorito;

static Favorito favoritos[MAX_FAVS];
static int num_favoritos = 0;
static char archivo_favoritos[MAX_CMD_LEN] = "favoritos.txt";


void favs_crear(const char *ruta) {
    FILE *file = fopen(ruta, "w");
    if (file) {
        fclose(file);
        strncpy(archivo_favoritos, ruta, MAX_CMD_LEN);
        archivo_favoritos[MAX_CMD_LEN - 1] = '\0';
        printf("Archivo de favoritos creado: %s\n", ruta);
    } else {
        perror("Error al crear el archivo");
    }
}

// Muestra la lista de comandos favoritos
void favs_mostrar() {
    for (int i = 0; i < num_favoritos; i++) {
        printf("%d: %s\n", favoritos[i].num, favoritos[i].comando);
    }
}

// Elimina comandos de la lista de favoritos
void favs_eliminar(const char *nums) {
    char *token = strtok((char *)nums, ",");
    while (token != NULL) {
        int num = atoi(token);
        for (int i = 0; i < num_favoritos; i++) {
            if (favoritos[i].num == num) {
                for (int j = i; j < num_favoritos - 1; j++) {
                    favoritos[j] = favoritos[j + 1];
                }
                num_favoritos--;
                break;
            }
        }
        token = strtok(NULL, ",");
    }
}

// Busca comandos en la lista de favoritos
void favs_buscar(const char *cmd) {
    for (int i = 0; i < num_favoritos; i++) {
        if (strstr(favoritos[i].comando, cmd) != NULL) {
            printf("%d: %s\n", favoritos[i].num, favoritos[i].comando);
        }
    }
}

// Borra todos los comandos favs
void favs_borrar() {
    num_favoritos = 0;
}

// Ejecuta un comando favorito
void favs_ejecutar(int num) {
    for (int i = 0; i < num_favoritos; i++) {
        if (favoritos[i].num == num) {
            char *args[] = {strdup(favoritos[i].comando), NULL};
            execvp(args[0], args);
            perror("Error al ejecutar el comando");
            exit(1);
        }
    }
    printf("Comando favorito no encontrado: %d\n", num);
}

// Carga comandos desde el archivo de favoritos
void favs_cargar(const char *ruta) {
    FILE *file = fopen(ruta, "r");
    if (file) {
        while (fgets(favoritos[num_favoritos].comando, MAX_CMD_LEN, file) && num_favoritos < MAX_FAVS) {
            favoritos[num_favoritos].comando[strcspn(favoritos[num_favoritos].comando, "\n")] = '\0'; // Elimina el salto de línea
            favoritos[num_favoritos].num = num_favoritos + 1;
            num_favoritos++;
        }
        fclose(file);
        printf("Comandos favoritos cargados desde: %s\n", ruta);
    } else {
        perror("Error al cargar el archivo");
    }
}

// Guarda comandos en el archivo de favoritos
void favs_guardar() {
    FILE *file = fopen(archivo_favoritos, "w");
    if (file) {
        for (int i = 0; i < num_favoritos; i++) {
            fprintf(file, "%d %s\n", favoritos[i].num, favoritos[i].comando);
        }
        fclose(file);
        printf("Comandos favoritos guardados en: %s\n", archivo_favoritos);
    } else {
        perror("Error al guardar el archivo");
    }
}

// Agrega un nuevo comando a la lista de favoritos
void favs_agregar(const char *comando) {
    for (int i = 0; i < num_favoritos; i++) {
        if (strcmp(favoritos[i].comando, comando) == 0) {
            return; // El comando ya está en la lista
        }
    }
    if (num_favoritos < MAX_FAVS) {
        favoritos[num_favoritos].num = num_favoritos + 1;
        strncpy(favoritos[num_favoritos].comando, comando, MAX_CMD_LEN - 1);
        favoritos[num_favoritos].comando[MAX_CMD_LEN - 1] = '\0';
        num_favoritos++;
    }
}
