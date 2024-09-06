#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell_utils.h"
#include "Limpiar_stdin.h"
//#include "command_parser.h"
//#include "executor.h"
//#include "error_handler.h"
int main() {
    char string[100];
    
    while(1) {
        char *args[10] = {0};
        scanf("%[^\n]s",string);
        if(strcmp(string,"exit")==0){
            break;
        }
        Asignar_argumentos(string,args);
        Ejecucion_comando(args);
        limpiar_stdin();
        for(int i = 0;i<10;i++){
            free(args[i]);
        }
        

        /*if (input == NULL) {
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

        free(input);  // Liberar la entrada*/
    }

    return 0;
}
