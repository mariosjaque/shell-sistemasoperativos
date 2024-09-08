// favoritos.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "favoritos.h"


typedef struct { // El struct que almacena los favoritos
    int id;
    char comando[256];
} Favorito;

#define MAX_FAVS 100

Favorito favoritos[MAX_FAVS];
int num_favoritos = 0;
char archivo_favoritos[256];


void crear_favs(const char *ruta) {
    strcpy(archivo_favoritos, ruta);
    FILE *archivo = fopen(ruta, "w");
    if (archivo) {
        fclose(archivo);
        printf("Archivo de favoritos creado: %s\n", ruta);
    } else {
        perror("Error al crear archivo de favoritos");
    }
}


void mostrar_favs() {
    if (num_favoritos == 0) {
        printf("No hay comandos favoritos.\n");
        return;
    }
    printf("Comandos Favoritos:\n");
    for (int i = 0; i < num_favoritos; i++) {
        printf("%d: %s\n", favoritos[i].id, favoritos[i].comando);
    }
}


void eliminar_favs(const char *nums) { // Se eliminan los favs por sus id´s
    char *num = strtok((char *)nums, ",");
    while (num != NULL) {
        int id = atoi(num);
        for (int i = 0; i < num_favoritos; i++) {
            if (favoritos[i].id == id) {
                for (int j = i; j < num_favoritos - 1; j++) {
                    favoritos[j] = favoritos[j + 1];
                }
                num_favoritos--;
                printf("comando con ID %d eliminado.\n", id);
                break;
            }
        }
        num = strtok(NULL, ",");
    }
}


void buscar_favs(const char *cmd) { //busca comandos que contengan un substring
    bool encontrado = false;
    for (int i = 0; i < num_favoritos; i++) {
        if (strstr(favoritos[i].comando, cmd)) {
            printf("%d: %s\n", favoritos[i].id, favoritos[i].comando);
            encontrado = true;
        }
    }
    if (!encontrado) {
        printf("No se encontraron comandos que coincidan con \"%s\".\n", cmd);
    }
}


void borrar_favs() { //reinicia la lista borrando todos los favs
    num_favoritos = 0;
    printf("Todos los comandos favoritos han sido eliminados.\n");
}


void ejecutar_fav(int id) {
    for (int i = 0; i < num_favoritos; i++) {
        if (favoritos[i].id == id) {
            system(favoritos[i].comando);
            return;
        }
    }
    printf("No se encontro un comando con el ID %d.\n", id);
}


void cargar_favs() {
    FILE *archivo = fopen(archivo_favoritos, "r");
    if (!archivo) {
        perror("Error al abrir el archivo de favorits");
        return;
    }

    num_favoritos = 0;
    while (fgets(favoritos[num_favoritos].comando, sizeof(favoritos[num_favoritos].comando), archivo) != NULL) {
        favoritos[num_favoritos].comando[strcspn(favoritos[num_favoritos].comando, "\n")] = 0;
        favoritos[num_favoritos].id = num_favoritos + 1;
        num_favoritos++;
    }
    fclose(archivo);
    printf("Comandos favoritos cargados desde %s\n", archivo_favoritos);
}

// Función para guardar favoritos en el archivo
void guardar_favs() {
    FILE *archivo = fopen(archivo_favoritos, "w");
    if (!archivo) {
        perror("Error al guardar el archivo de favoritps");
        return;
    }
    for (int i = 0; i < num_favoritos; i++) {
        fprintf(archivo, "%s\n", favoritos[i].comando);
    }
    fclose(archivo);
    printf("Comandos favoritos guardados en %s\n", archivo_favoritos);
}

void agregar_fav(const char *cmd) { //con esto se agrega un favorito si no se encuentra yaen la lista
    for (int i = 0; i < num_favoritos; i++) {
        if (strcmp(favoritos[i].comando, cmd) == 0) {
            return;  // y si el comando ya está en favoritos, no lo agrega.
        }
    }
    if (num_favoritos < MAX_FAVS) {
        favoritos[num_favoritos].id = num_favoritos + 1;
        strncpy(favoritos[num_favoritos].comando, cmd, sizeof(favoritos[num_favoritos].comando) - 1);
        num_favoritos++;
    }
}
