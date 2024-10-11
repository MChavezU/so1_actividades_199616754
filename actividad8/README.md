##### SISTEMAS OPERATIVOS 1
#### 199616754- Manuel Ricardo Chávez Ambrosio
---
# Actividad 8
### Instalar ambiente local Kubernetes utilizando minikube

* Descargar e instalar Minikube
    
        curl -LO https://storage.googleapis.com/minikube/releases/latest/minikube-linux-amd64

        sudo install minikube-linux-amd64 /usr/local/bin/minikube

* Iniciar Minikube

        minikube start --driver=kvm2

* Verificar que Minikube está en ejecución

        minikube status

### Desplegar Contenedor NGINX en Clúster kibernetes

* Crear Deployment NGINX

        kubectl create deployment nginx --image=nginx

* Exponer Servicio NGINX

        kubectl expose deployment nginx --type=NodePort --port=80

* Verificar el estado de pod NGINX

        kubectl get pods

* Obtener la URL para acceder a NGINX usando Minikube

        minikube service nginx --url

* Acceder a NGINX desde el navegador

        Copia y pega la URL en tu navegador para ver la página por defecto de NGINX

### ¿En un ambiente local de Kubernetes existen los nodos masters y workers, como es que esto funciona?

En un entorno de Kubernetes local, como Minikube; los tipos de nodos master-worker normalmente están simulados en una sola máquina.  La máquina local actúa como un clúster de Kubernetes, aunque todo se ejecuta en la máquina.

Minikube utiliza una máquina virtual para ejecutar un clúster Kubernetes de un solo nodo, donde están los roles de master y worker.

Este tipo de cofiguración permite probar con Kubernetes en entorno local.

