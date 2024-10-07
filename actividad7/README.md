#### SISTEMAS OPERATIVOS 1
###### 199616754 - Manuel Ricardo Chávez Ambrosio
---
# Actividad 7 - Completely Fair Scheduler (CFS) de Linux

## Definición
Es el planificador predeterminado en el kernel de Linux, y su diseño se centra en repartir el tiempo de CPU de manera justa entre todos los procesos que compiten por él.

## Principio Equidad
El objetivo central del CFS es que el tiempo de CPU se distribuya equitativamente entre los procesos, en proporción a sus prioridades. El CFS intenta que los procesos que han usado menos tiempo de CPU reciban más en futuras ejecuciones, de forma que todos los procesos obtengan el mismo tiempo de ejecución a lo largo del tiempo.

## Árbol
El CFS organiza los procesos listos para ejecutarse en una estructura de datos eficiente en formaa de árbol. Esta estructura permite insertar, eliminar y encontrar el proceso que debe ejecutarse a continuación de manera eficiente.

## Tiempo Virtual ejecución

* **Tiempo virtual:** Cada proceso tiene un contador llamado *vruntime*, que representa el tiempo virtual de ejecución del proceso.  Este tiempo aumenta mientras el proceso se ejecuta y lo hace más lentamente para procesos con mayor prioridad.

* Los procesos que han utilizado menos tiempo de CPU tienen un valor de vruntime menor, y por tanto CFS les dará prioridad para ejecutarse.

## Asignación Basada en prioridades
Las prioridades de los procesos influyen en el cálculo del tiempo de ejecución justo.  Los procesos con mayor prioridad (menor valor de nice) avanzan su vruntime más lentamente, lo que les permite ejecutar por más tiempo. Por otro lado, los procesos con menor prioridad incrementan su vruntime más rápidamente, limitando su tiempo de ejecución efectivo.

## Contexto de Conmutación
CFS determina cuándo realizar el cambio de contexto basándose en el vruntime. El cambio de contexto ocurre cuando el proceso en ejecución acumula más tiempo de CPU en comparación con el resto de los procesos, es decir, cuando su vruntime supera a otros procesos listos.

## Características Principales
* Selección de procesos - Selección del proceso con el menor vruntime para ejecutarse.
* Ejecución - Proceso se ejecuta hasta que vruntime alcanza el de los otros procesos listos.
* Actualización del vruntime - Mientras se ejecuta, el vruntime del proceso aumenta.
* Equidad Asignación CPU - Garantiza que todos los procesos reciban su parte justa de tiempo de CPU.
* Capacidad de Respuesta - Los procesos interactivos reciben tiempo de CPU rápidamente, mejorando la experiencia del usuario.
* Flexibilidad - Funciona bien con una variedad de cargas de trabajo, desde sistemas en tiempo real hasta servidores de gran carga.





