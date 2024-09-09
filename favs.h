// favs.h

#ifndef FAVS_H
#define FAVS_H

#include <stdbool.h>

typedef struct {
    int id;
    char *command;
} Favorite;

extern char favs_file[256];

void favs_crear(const char *path);
void favs_mostrar();
void favs_eliminar(const char *nums);
void favs_buscar(const char *cmd);
void favs_borrar();
void favs_ejecutar(int num);
void favs_cargar(const char *path);
void favs_guardar(const char *path);
bool favs_add(const char *cmd);
void favs_init();
void favs_cleanup();

#endif //FAVS_H
