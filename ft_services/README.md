# Introdução

## * O que é Docker e Kubernetes

### Docker é um Software que permite aos usuários executar máquinas virtuais leves. Você pode construir "contêiners" do Docker com base em imagens, que por sua vez podem ser geradas a partir de um arquivo chamado Dockerfile.
### Um contêiner é como uma única máquina virtual leve executando um sistema operacional, com um seu próprio espaço de memória e armazenamento. Ele é criado com base em uma "imagem", que nesse projeto será gerada por sua vez por um arquivo chamado Dockerfile.
### O arquivo Dockerfile é na verdade o passo a passo da construção da nossa imagem que no futuro gerará nosso container.
### A diferença entre uma máquina virtual e um contêiner é que a máquina virtual possui seu próprio Kernel, já o container utiliza o kernel do computador host.

## ** Orquestrando Contêiners

### Para administrar grandes números de contêiners e por sua vez seus serviços, precisaremos de uma maneira adequada, do contrário corremos o risco de perder algum serviço, ou se algum serviço cair, de não repormos o mesmo de forma adequada. Para isso utilizamos o Kubernetes.

## * Kubernetes

### ** O Kubernetes is a it solution for orquestration conteneires, for deploy, services and pod.
### Deployment: A object who execute and manages X instances of given Docker Image. 4 Example, you can have a deployment that will launch and manage 10 Servers Apache.
### Service: an object that links a deployment externally or to other containers. 4 example, a deployment that will link the IP 192.168.0.1 to the 10 Servers Apache and pick th one that has the least work load. 
### POD: a POD is a running instance of a deployment. You can run a shell into it. It has its own IP and its own memory space.

### All the above objects are described in YAML files.

## Minikube

### Minikube is a software that we use to create a virtual machine, that runs Kubernetes and insures compatibily with VirtualBox. It features many tools, such as a dashboard to see how are you'r pods going.







# Docker basics command

#### # Build a docker image from a Dockerfile
#### docker build -t <name image> <path Dockerfile>

#### # Start an instance of a docker image
#### docker run -it <your image name>
#### # Quando precisamos vincular portas do nosso contêiner ao computador precisamos especifica-las, nesse projeto usamos a porta 443 (ssl) e 80(standard)
#### docker run -it -p 80:80 -p 443:443
#### # Ainda sobre portas quando formos especificá-las podemos especificar o serviço que utilizará, ex: uma imagem Apache usando a  porta 80 no contêiner como nossa porta 80
#### docker run -it debian: apache -p80: 80

#### # Ver todas as Imagens
#### docker imagens

#### # Ver todos os contêiners em execução
#### docker ps
#### # Para visualizar a lista completa de conteineres incluindo os conteiners que foram executados anteriormente
#### docker ps -a

#### # Interromper um contêiner
#### docker kill <ID container>

#### # Deletar toda as imagens Docker que não estão sendo usadas e libera space no pc
#### docker system prune
#### # Deletar imagens apenas
#### docker images prune
#### # Deletar contêiners
#### docker container prune

# Gerenciar pods com Kubernetes

#### # Crie um Pod a partir de um arquivo YAML
#### kubectl create -f <file YAML>

#### # Excluir um POD
#### kubectl delete deployment < your deployment>
#### kubectl delete service <your service>

#### # Obtenha um shell em um pod
#### kubectl get pods # em seguida, o nome do pod deve ser semelhante a "grafana-5bb569f68-svdnz"
#### kubectl exec -it < nome do pod > - / bin / sh 

#### # Copiar dados para o pod ou para nosso computador
#### kubectl cp < nome do pod > : < file > < para >
#### # ou ao contrário
#### kubectl cp < de > < nome do pod > : < para >

#### # Reinicializar uma implantação
#### kubectl rollout reiniciar implantação < nome >

#### # Iniciar minikube painel
#### minikube painel

#### # Obter um cluster IP externo
#### minikube ip

#### # Redefinir Minikube VM
#### minikube delete
