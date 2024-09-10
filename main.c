// main.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "comandos.h"
#include "signals.h"
#include "customCom.h"
#include "favs.h"

// Función principal
void main() {
    // Configura los manejadores de señales
    signal(SIGINT, signal_handler);
    signal(SIGCHLD, signal_handler);
    signal(SIGTERM, signal_handler);

    favs_init();

    // Bucle principal
    while(1) {
        // Imprime el prompt
        printf("\033[1;34mNos echamos el proyecto\033[0;32m~$: \033[0m");
        // Captura la entrada del usuario
        char **comando = captar_entrada();
        if (comando == NULL || comando[0] == NULL) continue;
        // Maneja comandos personalizados
        if (customs(comando)) continue;
        // Maneja otros comandos
        manejar_comando(comando);
        //Agrega el comando a la lista de favoritos
        if (strcmp(comando[0], "favs") != 0) {
            favs_add(comando[0]);
        }
    }
}
