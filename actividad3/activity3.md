#### Sistemas Operativos 1 - Manuel Ricardo Chávez Ambrosio - 199616754.

# Actividad 3

> Operaciones con usuarios, grupos y permisos en Linux.

## Gestión de Usuarios
### Creacion de Usuarios
> Creación de usuario1, usuario2 y usuario3.

    $     sudo useradd usuario1
    $     sudo useradd usuario2
    $     sudo useradd usuario3

### Asignación de Contraseñas
> Asignación de contraseaña a usuario1, usuario2 y usuario3.

    $     sudo passwd usuario1
          Nueva contraseña:
          Vuelva a escribir la contraseña:
          passwd: contraseña actualizada correctamente.

     $    sudo passwd usuario2
          Nueva contraseña:
          Vuelva a escribir la contraseña:
          passwd: contraseña actualizada correctamente.
         
    $     sudo passwd usuario3
          Nueva contraseña:
          Vuelva a escribir la contraseña:
          passwd: contraseña actualizada correctamente.

### Información de Usuarios
> Mostrar información de usuario1 usando el comando id.

    $     id usuario1
          uid=1001(usuario1) gid=1001(usuario1) grupos=1001(usuario1)

### Eliminación de Usuarios
> Eliminar usuario3 conservando su directorio principal.

    $     sudo userdel usuario3
          contraseña para mchavez:

## Gestión de Grupos
### Creación de Grupos
> Crear grupo1 y grupo2

    $     sudo groupadd grupo1
          contraseña para mchavez:
          sudo groupadd grupo2

### Agregar Usuarios a Grupos
> Agregar usuario1-grupo1 y usuario2-grupo2

    $     sudo usermod -a -G grupo1 usuario1
    $     sudo usermod -a -G grupo2 usuario2

### Verificar Membresía
> Verificar asignación de usuarios a grupos con el comando groups

    $     groups usuario1
          usuario1 : usuario1 grupo1
          groups usuario2
          usuario2 : usuario2 grupo2

### Eliminar Grupo
> Eliminar grupo2.

    $     sudo groupdel grupo2
          contraseña para mchavez:

## Gestión de Permisos

### Creación de Archivos y Directorios
> Creación de archivo1.txt como usuario1.

    $      su usuario1
           Contraseña:
    $      cd ..
    $      cd usuario1
    $      echo "Actividad 3 SO1" > archivo1.txt

> Crear directorio directorio1 y dentro crear archivo2.txt

    $      mkdir directorio1
    $      cd directorio1
    $      echo "File in directorio1" > archivo2.txt

### Verificar Permisos
> Verificar permiso de archivos usando ls -l.

    $      ls -l
           -rw-r--r--. 1 usuario1 usuario1 20 ago  4 22:59 archivo2.txt
> Verificar permiso de directorio usando ls -ld.

    $      ls -ld
           drwxr-xr-x. 1 usuario1 usuario1 24 ago  4 22:59

### Modificar Permisos - Modo Numérico
> Cambiar permisos sobre archivo1.txt de tal forma que usuario1 puede leer y escribir; el grupo puede leer y otros no pueden hacer nada.

    $      chmod 640 archivo1.txt
    $      ls -l
           -rw-r-----. 1 usuario1 usuario1 16 ago  4 22:56 archivo1.txt

### Modificar Permisos - Modo Simbólico
> Agregar permiso de ejecución al propietario del archivo2.txt

    $      chmod u+r+w+x archivo2.txt
           -rwx------. 1 usuario1 usuario1 20 ago  4 22:59 archivo2.txt

### Cambiar el Grupo Propietario
> Cambiar grupo propietario de archivo2.txt a grupo1.

    $      chown :grupo1 archivo2.txt
    $      ls -l
           -rwx------. 1 usuario1 grupo1 20 ago  4 22:59 archivo2.txt

### Configurar Permisos de Directorio
### Comprobación de Acceso
### Verificación Final
> Verificar permisos finales.

    $      ls -l
    $      ls -ld
    
## Reflexión
### ¿Porqué es importante gestionar correctamente los usuarios y permisos en un sistema operativo?
> Principalmente por la seguridad y estabilidad del sistema así como la confidencialidad de datos.
### ¿Qué otros comandos o técnicas conocen para gestionar permisos en linux?
> En caso de linux y las diferentes distribuciones ofrece también la gestión de usuarios desde el modo gráfico; teniendo en cuenta que no es tan general. 



