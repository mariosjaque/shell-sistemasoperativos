#include <stdio.h>
#include <stdlib.h>
#include "command_parser.h"
#include "executor.h"
#include "error_handler.h"
#include "shell_utils.h"

int main() {
    char *input;

    while(1) {
        print_prompt();  // Función para mostrar el prompt

        input = read_input();  // Leer la entrada del usuario

        if (input == NULL) {
            continue;  // Si solo se presionó "enter"
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            break;  // Salir de la shell
        }

        // Parsear la entrada
        command_t *command = parse_command(input);

        if (command == NULL) {
            print_error("Comando no válido");
        } else {
            execute_command(command);  // Ejecutar el comando
            free_command(command);  // Liberar memoria
        }

        free(input);  // Liberar la entrada
    }

    return 0;
}
