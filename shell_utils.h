#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int Asignar_argumentos(char entrada[],char *args[]){
    int i,k=0,contador=0,contador2 = 0;
    int largo_cadena = strlen(entrada);
    char string[100];
    for(i=0;i<largo_cadena;i++){
        contador++;
        if(entrada[i] == ' '){
            args[k] = (char *)malloc((contador + 1) * sizeof(char));
            strncpy(args[k], string, contador);
            k++;
            contador = 0;
            contador2 = 0;
            memset(string, 0, 99);
            continue;
        }
        if(entrada[i] == '|'){
            i +=2;
            continue;
        }
        if(entrada[i] == '\0'){
            break;
        }
        string[contador2] = entrada[i];
        contador2 ++;
    }
    return 0;
    
}

int Ejecucion_comando(char *argumentos[]){
    int cantidad_de_argumentos = 0,i;
    for(i=0;i<10;i++){
        if(argumentos[i] == NULL){
            break;
        }
        cantidad_de_argumentos ++;
    }
    char *args_copia[cantidad_de_argumentos];

    for(i=0;i<cantidad_de_argumentos;i++){
        args_copia[i] = (char *)(malloc(strlen(argumentos[i] +1)*sizeof(char)));
        strncpy(args_copia[i],argumentos[i],strlen(argumentos[i]));
        args_copia[i][strlen(argumentos[i])] = '\0';
    }
    execvp(args_copia[0],args_copia);

    for(i=0;i<cantidad_de_argumentos;i++){
        free(args_copia[i]);
    }
    return 0;
}
