#### 9616754 - Manuel Ricardo Chávez Ambrosio - SISTEMAS OPERATIVOS 1
#### Actividad 4

# Creación de un systemd tipo servicio Linux
## Descripción
    Ejecutar un script que imprima un saludo y la fecha actual infinitamente con una pausa de un segundo; posteriormente habilitar el servicio para que se inicie con el sistema.

## Creación Script Bash
    El script bash debe crearse en /usr/local/bin/saludar.sh

    Asignar permisos de ejecución al script saludar.sh con el comando siguiente:

    sudo chmod +x /usr/local/bin/saludar.sh

## Creación del archivo de unidad systemd
    El archivo para el systemd debe crearse en /etc/systemd/system/saludar.service

## Habilitar Servicio
    Para habilitar el servicio y que éste se inicio automáticamente con el sistema utilizar el siguiente comando:

    sudo systemctl enable saludar.service

## Iniciar Servicio
    Iniciar el servicio manualmente para verificar su funcionamiento:

    sudo systemctl start saludar.service

## Verificar Status del Servicio
    Puede verificar que el servicio está funcionando correctamente con el comando:

    sudo systemctl status saludar.service

## Verificar logs del Servicio
    Puede utilizar el siguiente comando para verficar los logs del servicio:

    sudo journalctl -u saludar.service

