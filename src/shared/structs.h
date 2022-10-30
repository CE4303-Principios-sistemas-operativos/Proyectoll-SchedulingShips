#ifndef PROJECT2_SHARED_STRUCTS_H
#define PROJECT2_SHARED_STRUCTS_H



#include "../lib/CEThread.h"


/**
 * This struct represents a generic ship.
 * 
 * short position[2] - starting position.
 * float speed - ship speed.
 *     - Normal:    x.
 *     - A-ship:   1.2x.
 *     - B-ship:   1.5x to 2x.
 *     - I-ship:   2x.
 * short priority - priority to cross the bridge.
 *     - Normal:    2
 *     - A-ship:   2
 *     - B-ship:   1
 *     - I-ship:   0
 * float execution_time - since creation to destruction.
 * short type - ship type.
 *     - Normal:    0
 *     - A-ship:   1
 *     - B-ship:   2
 *     - I-ship:   3
 * short status
 *     - creation:  0
 *     - running:   1
 *     - completed: 2
 *     - waiting:   3
 *     - locked:    4
 *     - dead:      5
 *     - free:      6
 * float weight - ship weight.
 * short direction - ship direction.
 *     - up:    0
 *     - down:  1
 *     - left:  2
 *     - right: 3
 * short ticks - indicates how many ticks have passed since creation.
 * short origin - indicates if the ship is from A or B community.
 */
struct Ship {
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
} typedef Ship;

/**
 * Struct used to represent an ship Data.
 * 
 * float speed - ship speed.
 * float execution_time - since creation to destruction.
 * float weight - ship weight.
 * 
 */
struct ship_data {
    float speed;
    float execution_time;
    int weight;
} typedef shipData;

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
 * ship* south_ships - array of ship in the south.
 * ship* north_ships - array of ships in the north.
 * int south_ships_number - current number of ship in the south.
 * int north_ships_number - current number of ships in the north.
 * int max_south_ships - max number of ship in the south.
 * int max_north_ships - max number of ships in the north
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
    ship* south_ships;
    lpthread_mutex_t* south_mutex;
    ship* north_ships;
    lpthread_mutex_t* north_mutex;
    int south_ships_number;
    int north_ships_number;
    int max_south_ships;
    int max_north_ships;
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
 * int max_south_ships - max number of ship in the south.
 * int max_north_ships - max number of ships in the north.
 * char* algorithm - name of the calendarization algorithm.
 * char* calendar - calendar type name.
 * 
 */
struct bridge_data {
    int length;
    int max_weight;
    int max_south_ships;
    int max_north_ships;
    char* algorithm;
    enum schedulers calendar;
} typedef BridgeData;

/**
 * Struct to represen a ship Spawner.
 *
 * float mean - distribution mean.
 * float alpha - percentage of alpha ships.
 * float beta - percentage of beta ships.
 * float normal - percentage of normal ships.
 * short mode - execution order.
 *      - automatic: 1.
 *      - manual:    0.
 * shipData* ship_data: loaded ship settings.
 * 
 */
struct ship_spawner {
    float mean;
    float alpha;
    float beta;
    float normal;
    short mode;
    shipData* ship_data;
} typedef shipSpawner;

struct thread_args_ship {
    ship* ship;
    int pos;
} typedef thread_args_ship_t;


#endif /* PROJECT2_SHARED_STRUCTS_H */
