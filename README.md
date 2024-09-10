# Sistemas Operativos - Proyecto 1
Integrantes del grupo: Benjamín Eduardo Martínez Quijada, Luis Ignacio Martínez Neira, Mario Andrés Salgado Jaque, Santiago Alexander Díaz Barra

## Instrucciones para compilación
El proyecto se desarrolló utilizando CLion, pero es posible compilarlo en cualquier instalación de Linux utilizando CMake y make.

Es recomendable clonar el repositorio, abrir una terminal en la carpeta local de este e ingresar los siguientes comandos:
```
mkdir build
cd build
cmake ..
make
```
Se construirá un solo archivo, el cual se puede ejecutar de la siguiente forma:
```
./Shell_V2
```

## Instrucciones para ejecutar comandos
La shell, al abrirse, se mantiene en espera de comandos. Estos se deben ingresar con el teclado o cualquier dispositivo de entrada que sea capaz de enviar instrucciones al equipo.

Es posible ejecutar cualquier programa disponible en el sistema anfitrión, así como usar comandos que dependan de pipes (separados con el carácter "|"), los comandos personalizados "favs" y "set".

Para salir de la shell basta con usar el comando "exit".

### Uso del comando "set"
El comando "set" acepta dos argumentos: la cantidad de tiempo en la que desea un recordatorio en segundos (un entero), y el mensaje que desea desplegar (una cadena de texto).

Ejemplo: set recordatorio 10 “hacer pausa activa” mostrará en 10 segundos el mensaje "hacer pausa activa".

### Uso del comando "favs" según el enunciado original
favs crear ruta/misfavoritos.txt: Crea archivo donde se almacenan los comandos favoritos dada la ruta y nombre de archivo. Note que la ruta puede ser cualquiera, incluyendo directorio actual.

Cada vez que el usuario ejecuta un comando en su shell se agrega automáticamente si y solo si no está en la lista de favoritos, exceptuando los comandos asociados al manejo de favoritos.

favs mostrar: despliega la lista comandos existentes en la lista con su respectivo número.

favs eliminar num1,num2: Eliminar comandos asociados a los números entregados entre comas.

favs buscar cmd: Busca comandos que contengan substring cmd en la lista de favoritos y los despliega en pantalla junto con su número asociado.

favs borrar: Borra todos los comandos en la lista de favoritos.

favs num ejecutar: Ejecuta el comando cuyo número en la lista es num.

favs cargar: Lee comandos de archivo de favoritos, los mantiene en memoria y los despliega en pantalla.

favs guardar: Guarda comandos agregados en sesión de shell actual.
