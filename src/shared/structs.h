#ifndef PROJECT2_SHARED_STRUCTS_H
#define PROJECT2_SHARED_STRUCTS_H



#include "../lib/CE.h"


/**
 * This struct represents a generic alien.
 * 
 * short position[2] - starting position.
 * float speed - alien speed.
 *     - Normal:    x.
 *     - A-Alien:   1.2x.
 *     - B-Alien:   1.5x to 2x.
 *     - I-Alien:   2x.
 * short priority - priority to cross the bridge.
 *     - Normal:    2
 *     - A-Alien:   2
 *     - B-Alien:   1
 *     - I-Alien:   0
 * float execution_time - since creation to destruction.
 * short type - alien type.
 *     - Normal:    0
 *     - A-Alien:   1
 *     - B-Alien:   2
 *     - I-Alien:   3
 * short status
 *     - creation:  0
 *     - running:   1
 *     - completed: 2
 *     - waiting:   3
 *     - locked:    4
 *     - dead:      5
 *     - free:      6
 * float weight - alien weight.
 * short direction - alien direction.
 *     - up:    0
 *     - down:  1
 *     - left:  2
 *     - right: 3
 * short ticks - indicates how many ticks have passed since creation.
 * short origin - indicates if the alien is from A or B community.
 */
struct alien {
    // (x, y)
    short position[2];
    float speed;
    short priority;
    float execution_time;
    short type;
    short status;
    int weight;
    short direction;
    short ticks;
    short community;
} typedef Alien;

/**
 * Struct used to represent an Alien Data.
 * 
 * float speed - alien speed.
 * float execution_time - since creation to destruction.
 * float weight - alien weight.
 * 
 */
struct alien_data {
    float speed;
    float execution_time;
    int weight;
} typedef AlienData;

enum cardinals
{
    NORTH,
    SOUTH
};

enum schedulers
{
    ROUND_ROBIN,
    PRIORITY,
    SJF,
    FIFO,
    LOTTERY
};

/**
 * Struct used to represent a Bridge.
 * 
 * int position[2] - bridge position.
 * float current_weight - current weight on the bridge.
 * float max_weight - max weight supported by the bridge.
 * int length
 * Alien* south_aliens - array of alien in the south.
 * Alien* north_aliens - array of aliens in the north.
 * int south_aliens_number - current number of alien in the south.
 * int north_aliens_number - current number of aliens in the north.
 * int max_south_aliens - max number of alien in the south.
 * int max_north_aliens - max number of aliens in the north
 * void* algorithm - calendarization algorithm.
 * void* calendar - calendar type.
 * short direction - current bridge direction.
 *      north to south: 0
 *      south to north: 1
 * 
 */
struct bridge {
    // (x, y)
    short position[2];
    lpthread_mutex_t* curren_weight_mutex;
    int current_weight;
    int max_weight;
    int length;
    Alien* south_aliens;
    lpthread_mutex_t* south_mutex;
    Alien* north_aliens;
    lpthread_mutex_t* north_mutex;
    int south_aliens_number;
    int north_aliens_number;
    int max_south_aliens;
    int max_north_aliens;
    enum schedulers calendar;
    short direction;
    int y;
    double north_waiting_seconds;
    double south_waiting_seconds;
} typedef Bridge;

/**
 * Struct to represent a Bridge Data.
 * 
 * float max_weight - max weight supported by the bridge.
 * int max_south_aliens - max number of alien in the south.
 * int max_north_aliens - max number of aliens in the north.
 * char* algorithm - name of the calendarization algorithm.
 * char* calendar - calendar type name.
 * 
 */
struct bridge_data {
    int length;
    int max_weight;
    int max_south_aliens;
    int max_north_aliens;
    char* algorithm;
    enum schedulers calendar;
} typedef BridgeData;

/**
 * Struct to represen a Alien Spawner.
 *
 * float mean - distribution mean.
 * float alpha - percentage of alpha aliens.
 * float beta - percentage of beta aliens.
 * float normal - percentage of normal aliens.
 * short mode - execution order.
 *      - automatic: 1.
 *      - manual:    0.
 * AlienData* alien_data: loaded alien settings.
 * 
 */
struct alien_spawner {
    float mean;
    float alpha;
    float beta;
    float normal;
    short mode;
    AlienData* alien_data;
} typedef AlienSpawner;

struct thread_args_alien {
    Alien* alien;
    int pos;
} typedef thread_args_alien_t;


#endif /* PROJECT2_SHARED_STRUCTS_H */
