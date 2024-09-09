// favs.c

#include "favs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_FAVS 100

static Favorite favs[MAX_FAVS];
static int fav_count = 0;
char favs_file[256] = "";

void favs_crear(const char *path) {
    strncpy(favs_file, path, sizeof(favs_file) - 1);
    FILE *file = fopen(favs_file, "w");
    if (file) {
        fclose(file);
        printf("Archivo de favoritos creado: %s\n", favs_file);
    } else {
        perror("Error al crear archivo de favoritos");
    }
}

void favs_mostrar() {
    for (int i = 0; i < fav_count; i++) {
        printf("%d: %s\n", favs[i].id, favs[i].command);
    }
}

void favs_eliminar(const char *nums) {
    char *num_str = strdup(nums);
    char *token = strtok(num_str, ",");
    while (token) {
        int num = atoi(token);
        for (int i = 0; i < fav_count; i++) {
            if (favs[i].id == num) {
                free(favs[i].command);
                for (int j = i; j < fav_count - 1; j++) {
                    favs[j] = favs[j + 1];
                }
                fav_count--;
                break;
            }
        }
        token = strtok(NULL, ",");
    }
    free(num_str);
}

void favs_buscar(const char *cmd) {
    for (int i = 0; i < fav_count; i++) {
        if (strstr(favs[i].command, cmd)) {
            printf("%d: %s\n", favs[i].id, favs[i].command);
        }
    }
}

void favs_borrar() {
    for (int i = 0; i < fav_count; i++) {
        free(favs[i].command);
    }
    fav_count = 0;
}

void favs_ejecutar(int num) {
    for (int i = 0; i < fav_count; i++) {
        if (favs[i].id == num) {
            system(favs[i].command);
            return;
        }
    }
    fprintf(stderr, "Error: Comando no encontrado.\n");
}

void favs_cargar(const char *path) {
    strncpy(favs_file, path, sizeof(favs_file) - 1);
    FILE *file = fopen(favs_file, "r");
    if (file) {
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            line[strcspn(line, "\n")] = 0;
            favs_add(line);
        }
        fclose(file);
        favs_mostrar();
    } else {
        perror("Error al cargar archivo de favoritos");
    }
}

void favs_guardar(const char *path) {
    FILE *file = fopen(path, "w");
    if (file) {
        for (int i = 0; i < fav_count; i++) {
            fprintf(file, "%s\n", favs[i].command);
        }
        fclose(file);
    } else {
        perror("Error al guardar archivo de favoritos");
    }
}

bool favs_add(const char *cmd) {
    for (int i = 0; i < fav_count; i++) {
        if (strcmp(favs[i].command, cmd) == 0) {
            return false;
        }
    }
    if (fav_count < MAX_FAVS) {
        favs[fav_count].id = fav_count + 1;
        favs[fav_count].command = strdup(cmd);
        fav_count++;
        return true;
    }
    return false;
}

void favs_init() {
    fav_count = 0;
}

void favs_cleanup() {
    favs_guardar(favs_file);
    favs_borrar();
}
