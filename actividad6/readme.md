###### SISTEMAS OPERATIVOS 1 - Actividad 6
###### 199616754 - Manuel Ricardo Chávez Ambrosio
---
# Actividad 6
### Problema 1
---
¿ Incluyendo el proceso inicial, cuántos procesos son creados por el siguiente programa? Razone su respuesta.
    
    #include <stdio.h>
    #include <unistd.h>

    int main()
    {
    /*fork a child process*/
    fork();

    /*fork another child process*/
    fork();

    /*and fork another*/
    fork();

    return 0;
    }

Razonamiento:

1. **Primera fork()**.  Cuando se llama a fork() por primera vez, ya existe un proceso inicial que ejecuta el programa.  Después de ésta primera llamada se duplica el proceso.

2. **Segundo fork()**.  Cada uno de los 2 procesos anteriores llama a fork(), quedando ahora 4 procesos.

3. **Tercer fork()**.  Cada uno de los 4 procesos anteriores vuelve a llamar a fork() quedando ahora 8 procesos.

En Resumen

    Se crean 7 procesos nuevos, pero tomando en cuenta el proceso inicial que ejecuta el programa hace un total de 8 PROCESOS.

### Problema 2
---
Utilizando un sistema Linux, escriba un programa en C que cree un proceso hijo (fork)
que finalmente se convierta en un proceso zombie. Este proceso zombie debe
permanecer en el sistema durante al menos 60 segundos.
Mostrar procesos zombi con el comando siguiente en bash:

    ps aux | grep Z

![Proceso en ejecución](/proczombi.png)

    Implementación en p2.c

### Problema 3
---
Usando el siguiente código como referencia, completar el programa para que sea ejecutable y responder las siguientes preguntas: ¿Cuántos procesos únicos son creados? y ¿Cuántos hilos únicos son creados?

    pid_t pid;
    pid = fork();
    if (pid == 0) {
        fork();
        thread_create( ... );
    }
    fork();

    Implementación completa en p3.c

RAZONAMIENTO:

+ Existe un proceso inicial cuando se ejecuta el programa, antes del primer fork()
+ En el primer fork() se crea 1 proceso hijo; ahora hay 2 procesos.
+ El segundo fork(dentro del hijo) crea otro proceso; ahora hay 3 procesos.
+ pthread_create() crea 1 hilo adicional.
+ Tercer fork() se ejecuta en todos los procesos, duplicando la cantidad; es decir para cada proceso existente se crea uno nuevo.
+ **¿Cuántos procesos únicos son creados?**

        En total se crean 6 PROCESOS.

+  **¿Cuántos hilos únicos son creados?**

        Se crea 1 HILO original, hilo único.

