#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

int choice; //opción del menú

int finished[10], //Se indica con un 1 si el proceso ya ha finalizado
process_name[10], //Identificador de cada proceso
arrival_time[10], //Tiempo de llegada de cada proceso
burst_time[10], //Tiempo de ejecución que necesita cada proceso
waiting_time[10], //Tiempo que se ha mantenido el proceso esperando su turno
turn_around_time[10]; // Tiempo total para que se concluyera la ejecución de cada proceso
//int avg_wait_time, avg_turn_around_time;
int n, //número de procesos a calendarizar
pending, //número de procesos pendientes
remain_burst_time[10], //tiempo de espera
time, //simula el paso del tiempo
count; // numero de proceso con el que se trabaja




void input()
{
    int i;
    printf("\nEnter number of processes");
    scanf( "%d",&n) ; 
    for(i=0;i<n;i++) 
    { 
        process_name[i]=i;
        printf("\n Enter Burst Time of Process %d:",process_name[i]); 
        scanf("%d",&burst_time[i]); 
        remain_burst_time[i]=burst_time[i];
        printf("\n Enter arrival time of Process %d:",process_name[i]); 
        scanf("%d",&arrival_time[i]);
    }
}

void menu(){

    printf( "\n\n\n\n*********MENU*********" );
    printf("\n 1. Round Robin"); 
    printf("\n 2. exit"); 
    printf("\n Enter your choice"); 
    scanf("%d",&choice);
}

/*Función que muestra los datos de cada proceso al terminar la ejecución*/
void output(){
    int i;
    printf("\n\n\nProcess   A.T.    B.T.    W.T.    T.A.T"); 
    for(i=0;i<n;i++) 
    {
    printf("\n P%d \t %d \t %d \t %d \t %d",process_name[i],arrival_time[i],burst_time[i],waiting_time[i],turn_around_time[i]);
    } 
}

/*Función que implementa el algoritmo RR para simular la calendarización de procesos en un sistema operativo*/
void round_robin()
{

    int time_quantum,i; 
    input();
    pending=n;

    printf("\n Enter time Quantum"); 
    scanf("%d",&time_quantum); 
    printf("\n\n\nGantt Chart==>");

    //Se inicializa en 0 el array de procesos finalizados y de tiempo de espera para todos los procesos
    for(i=0;i<n;i++) 
    {
        finished[i]=0; 
        waiting_time[i]=0;
    }

    //Inicio de la ejecución 
    
    for(time=0,count=0;pending>0;)
    {

        //Caso en que el tiempo restante de ejecución sea menor o igual que el quantum dado
        if(finished[count]!=1 && arrival_time[count]<=time && remain_burst_time[count]<=time_quantum)
        {
            time+=remain_burst_time[count];
            //Se completa el proceso y se indica como finalizado 
            pending--;
            finished[count]=1;
            waiting_time[count]-=arrival_time[count]; 
            turn_around_time[count]=waiting_time[count]+burst_time[count];
            
            //Print gant chart
            for(i=0;i<remain_burst_time[count];i++) 
                printf("P%d ",process_name[count]); 
            for(i=0;i<n;i++) 
            {
                if(i==count || finished[i]==1) 
                    continue;
                waiting_time[i]+=remain_burst_time[count];
            }

            remain_burst_time[count]=0;

        }
        
        //Caso en el que el tiempo de ejecución es más grande que el quantum dado
        else if(finished[count]!=1 && arrival_time[count]<=time && remain_burst_time[count]>=time_quantum)
        {

            remain_burst_time[count]-=time_quantum; 
            time+=time_quantum;
            for(i=0;i<n;i++) 
            {

                if(i==count || finished[i]==1) 
                    continue; 
                waiting_time[i]+=time_quantum;
            }

            //Gant chart
            for(i=0;i<time_quantum;i++) 
                printf("P%d ",process_name[count]);

        }

        count=(count+1)%n;
         
    }
output();
}


int main() 
{
    while(1) 
    {
        menu();
        switch(choice)
        {
            case 1: round_robin(); 
                break;
            case 2: exit(0); 
                break;
        }

    }
    return 0;
}