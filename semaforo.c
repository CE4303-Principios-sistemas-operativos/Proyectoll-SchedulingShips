#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#define constante 100000
int contador=0; // Share resource. Used in SUma and Resta method. Two threads use this methods.
sem_t semaforo;

static void * Suma(void * arg){
    for (int i=0; i<constante; i++){
        sem_wait(&semaforo); //Down
        contador++;
        sem_post(&semaforo); //Up
    }
}


static void * Resta(void * arg){
    for (int i=0; i<constante; i++){
        sem_wait(&semaforo); //Down
        contador--;
        sem_post(&semaforo); //Up
    }
}

// Compilation command: 
// gcc semaforo.c -o semaforo -lpthread
int main(){
    sem_init(&semaforo,0,1); // Last param is the resource amount.

    pthread_t hilo1, hilo2;

    pthread_create(&hilo1, NULL, *Suma, NULL);
    pthread_create(&hilo2, NULL, *Resta, NULL);

    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);
    printf("El valor del contador es: %d \n", contador);

    return 0;
}
