#include <pthread.h>


#define numberOfBoats 3

struct boat
{
    int id;
    int burstTime;
    int position;
    int speed;
    int priority;
    int started;
    pthread_t thread;
};

struct boatFleet
{
    struct boat boats[numberOfBoats];
    int boatsActive;
    int boatsPassed;
};

struct oceans
{
    struct boatFleet boatFleets[2]; // 0 -> Left   1->Right
};