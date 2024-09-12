#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Crea un nuevo proceso
    pid = fork();

    if (pid < 0) {
        // Si fork() falla
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        // Proceso hijo
        printf("Proceso hijo. PID: %d.\n", getpid());
        exit(0);  // El proceso hijo termina aquí
    } 
    else {
        // Proceso padre
        printf("Proceso padre - Proceso hijo PID: %d.\n", pid);

        // El padre duerme durante 60 segundos, mientras proceso hijo está en zombie
        sleep(60);

        // Después de 60 segundos, el padre recoge el estado del hijo para eliminar el proceso zombie
        wait(NULL);
        printf("El proceso zombie eliminado.\n");
    }

    return 0;
}
