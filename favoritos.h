//
// Created by santi on 07-09-2024.
//

#ifndef FAVORITOS_H
#define FAVORITOS_H

#include <stdbool.h>

void favs_crear(const char *ruta);
void favs_mostrar();
void favs_eliminar(const char *nums);
void favs_buscar(const char *cmd);
void favs_borrar();
void favs_ejecutar(int num);
void favs_cargar(const char *ruta);
void favs_guardar();
void favs_agregar(const char *comando);
#endif //FAVORITOS_H
