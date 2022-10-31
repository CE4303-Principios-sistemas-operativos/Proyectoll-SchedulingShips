#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "Scheduler/scheduler.h"

#define numberOfBoats 3
#define canalLen 2
#define W 1

// Control de flujo
int equidad = 1;
int timer = 0;
int tico = 0;

int scheduler = 3;

typedef struct
{
    int ocean;
    int threaId;
} threadArgs;

int turn;

struct oceans oceans;

pthread_mutex_t mutex[canalLen];

void *threadRoutine(void *arg)
{

    threadArgs *args = arg;

    int threadId = args->threaId;
    int ocean = args->ocean;
    int finished = 0;

    while (finished != 1)
    {
        if ((turn == ocean) && oceans.boatFleets[ocean ^ 1].boatsActive == 0 && oceans.boatFleets[ocean].boats[threadId].started == 1)
        {

            printf("El barco %d del oceano %d entra\n", oceans.boatFleets[ocean].boats[threadId].id, ocean);
            oceans.boatFleets[ocean].boatsActive += 1;
            oceans.boatFleets[ocean].boatsPassed += 1;
            if (equidad == 1 && oceans.boatFleets[ocean].boatsPassed == W)
            {
                turn = turn ^ 1;
                oceans.boatFleets[ocean].boatsPassed = 0;
            }

            for (int i = 0; i < canalLen; i++)
            {
                pthread_mutex_lock(&mutex[i]);
                oceans.boatFleets[ocean].boats[threadId].position += 1;
                printf("El barco %d, oceano %d, ejecutando etapa %d\n", oceans.boatFleets[ocean].boats[threadId].id, ocean, i);
                sleep(oceans.boatFleets[ocean].boats[threadId].speed);
                pthread_mutex_unlock(&mutex[i]);
                if (threadId < (numberOfBoats - 1))
                    oceans.boatFleets[ocean].boats[threadId + 1].started = 1;
            }

            oceans.boatFleets[ocean].boatsActive -= 1;
            finished = 1;
        }
    }
    free(args);
}

void *changeTurn(void *arg)
{
    while (1)
    {
        turn = 1;
        printf("-- Turno del oceano %d --\n", turn);
        oceans.boatFleets[1].boats[0].started = 1;
        sleep(1);

        turn = 2;
        printf("-- En amarillo --\n");
        sleep(2);

        turn = 0;
        printf("-- Turno del oceano %d --\n", turn);
        oceans.boatFleets[0].boats[0].started = 1;
        sleep(1);

        turn = 2;
        printf("-- En amarillo --\n");
        sleep(2);
    }
}

int main()

{
    turn = 0;

    for (int i = 0; i < canalLen; i++)
    {
        pthread_mutex_init(&mutex[i], NULL);
    }

    for (int ocean = 0; ocean < 2; ocean++)
    {
        for (int i = 0; i < numberOfBoats; i++)

        {
            printf("Enter type of boat for Boat %d of Ocean %d: ", i + 1, ocean + 1); 
            scanf("%d", &oceans.boatFleets[ocean].boats[i].speed);

            if (scheduler == 1)  //Prioridad
            {
                printf("Enter Priority Value for Boat %d of Ocean %d: ", i + 1, ocean + 1);

                scanf("%d", &oceans.boatFleets[ocean].boats[i].priority);                
            }

            oceans.boatFleets[ocean].boats[i].id = i + 1;
            oceans.boatFleets[ocean].boats[i].position = 0;
        }

        if (scheduler == 1) oceans = priority(oceans, ocean);
        if (scheduler == 3) oceans = sjf(oceans, ocean, canalLen);
    }

    // Printing scheduled process

    for (int ocean = 0; ocean < 2; ocean++)
    {
        printf("\nOceano %d\n", ocean);
        for (int a = 0; a < numberOfBoats; a++)
        {
            printf("Barco %d, ", oceans.boatFleets[ocean].boats[a].id);
        }

        printf("\n");
    }

    printf("\n--Procesando--\n");
    for (int ocean = 0; ocean < 2; ocean++)
    {
        for (int a = 0; a < numberOfBoats; a++)
        {
            threadArgs *args = malloc(sizeof *args);
            args->ocean = ocean;
            args->threaId = a;
            pthread_create(&(oceans.boatFleets[ocean].boats[a].thread), NULL, threadRoutine, args);
            // sleep(1);
        }
    }

    pthread_t changingTurn;
    if (timer == 1)
        pthread_create(&(changingTurn), NULL, changeTurn, NULL);

    oceans.boatFleets[0].boats[0].started = 1;
    oceans.boatFleets[1].boats[0].started = 1;

    for (int ocean = 0; ocean < 2; ocean++)
    {

        for (int i = 0; i < numberOfBoats; i++)
        {
            pthread_join(oceans.boatFleets[ocean].boats[i].thread, NULL);
        }
    }

    return 0;
}