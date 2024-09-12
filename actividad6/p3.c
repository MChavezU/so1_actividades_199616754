#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Función que ejecutarán los hilos
void* thread_func(void* arg) {
    printf("Hilo creado con PID: %d\n", getpid());
    pthread_exit(NULL);
}

int main() {
    pid_t pid;
    pthread_t thread;

    pid = fork();
    if (pid == 0) {
        fork();
        // Crear un hilo proceso hijo
        if (pthread_create(&thread, NULL, thread_func, NULL) != 0) {
            perror("Error al crear el hilo");
            exit(1);
        }

        // Esperar el hilo termine
        pthread_join(thread, NULL); 
    }
    
    fork();

    sleep(1);
    return 0;
}