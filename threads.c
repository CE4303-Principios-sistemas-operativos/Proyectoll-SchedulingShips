#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <stdbool.h>

#include <unistd.h>

//Se declaran las variables globales que se usan para simular el acceso a una posición del canal o segmento del cpu
//En este caso los leds simulan las posiciones
static int led1 = 0;
static int led2 = 0;
static int led3 = 0;
static int led4 = 0;
static int led5 = 0;

//Se inicializan los mutex, se utiliza uno para cada variable global o posición/led

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex3 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex4 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex5 = PTHREAD_MUTEX_INITIALIZER;

//Función o rutina que estará ejecutando el hilo 1
//Lo que hace es ir "encendiendo" cada led secuencialmente (cambia el valor de la variable global ledn a 1 y se espera 2s)
void *thread11_routine(void *unused){
    //Se bloquea el acceso a la variable led1 con el mutex, se cambia su valor a 1 y esta se desbloquea despues de pasados 2s
    pthread_mutex_lock(&mutex1);
    led1=1;
    printf("hilo 1. Estado led 1: %d\n",led1); 
    sleep(2);
    pthread_mutex_unlock(&mutex1);
    //Se repite el mismo proceso para el acceso a las demás variables
    pthread_mutex_lock(&mutex2);
    led2=1;
    printf("hilo 1. Estado led 2: %d\n",led2); 
    sleep(2);
    pthread_mutex_unlock(&mutex2);
    
    pthread_mutex_lock(&mutex3);
    led3=1;
    printf("hilo 1. Estado led 3: %d\n",led3); 
    sleep(2);
    pthread_mutex_unlock(&mutex3);

    pthread_mutex_lock(&mutex4);
    led4=1;
    printf("hilo 1. Estado led 4: %d\n",led4); 
    sleep(2);
    pthread_mutex_unlock(&mutex4);

    pthread_mutex_lock(&mutex5);
    led5=1;
    printf("hilo 1. Estado led 5: %d\n",led5); 
    sleep(2);
    pthread_mutex_unlock(&mutex5);

}

//Función o rutina que estará ejecutando el hilo 2
//Lo que hace es ir "apagando" cada led secuencialmente (cambia el valor de la variable global ledn a 0 y se espera 1s)
//Es decir, simularía un barco que avanza más rapido durante el canal que el barco del hilo 1

void *thread22_routine(void *unused){
    //Se bloquea el acceso a la variable led1 con el mutex, se cambia su valor a 0 y esta se desbloquea despues de pasado 1s
    pthread_mutex_lock(&mutex1);
    led1=0;
    printf("hilo 2. Estado led 1: %d\n",led1); 
    sleep(1);
    pthread_mutex_unlock(&mutex1);
     //Se repite el mismo proceso para el acceso a las demás variables
    pthread_mutex_lock(&mutex2);
    led2=0;
    printf("hilo 2. Estado led 2: %d\n",led2); 
    sleep(1);
    pthread_mutex_unlock(&mutex2);
    
    pthread_mutex_lock(&mutex3);
    led3=0;
    printf("hilo 2. Estado led 3: %d\n",led3); 
    sleep(1);
    pthread_mutex_unlock(&mutex3);

    pthread_mutex_lock(&mutex4);
    led4=0;
    printf("hilo 2. Estado led 4: %d\n",led4); 
    sleep(1);
    pthread_mutex_unlock(&mutex4);

    pthread_mutex_lock(&mutex5);
    led5=0;
    printf("hilo 2. Estado led 5: %d\n",led5); 
    sleep(1);
    pthread_mutex_unlock(&mutex5);

}
/*

void *thread1_routine(void *unused){

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);
        leds[i]=1;
        printf("hilo 1. Estado led %d: %d\n",i,leds[i]); 
        sleep(2);
        pthread_mutex_unlock(&mutex);
    }
    

    //pthread_mutex_lock(&mutex);
    //posicion_barco1 = posicion_canal;
    //pthread_mutex_unlock(&mutex);

}

void *thread2_routine(void *unused){

    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&mutex);
        leds[i]=0;
        printf("Estado led %d: %d\n",i,leds[i]); 
        sleep(1);
        pthread_mutex_unlock(&mutex);
    }
    
}
*/

//Imprime el error que se presenta
void errorExit(char *sterr)
{
    perror(sterr);
    exit(1);
}

//Se crean los 2 hilos a usar y se les asigna la función o rutina que ejecutarán
void hilos(){

    pthread_t thread1, thread2;

    if( 0!= pthread_create(&thread1, NULL, thread11_routine, NULL)){
        errorExit("thread1 cannot be created");
    }

     if( 0!= pthread_create(&thread2, NULL, thread22_routine, NULL)){
        errorExit("thread2 cannot be created");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);


}

int main(int argc, char *argv[]){

    hilos();

    return 0;
}
// gcc threads.c -o t -lpthread
// ./t