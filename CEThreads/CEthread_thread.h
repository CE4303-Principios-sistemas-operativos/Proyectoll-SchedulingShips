#ifndef PROJECT2_LIB_CETHREAD_THREAD_H
#define PROJECT2_LIB_CETHREAD_THREAD_H


#include <stdlib.h>


// Define thread attributes
static const int STACK_SIZE = 65536;

typedef struct CEthread_attr 
{
	int	    flags;
	void*   stackaddr_attr;
	size_t  stacksize_attr;
} CEthread_attr_t;


// Define posible stated of the thread
enum CEthread_state
{
    RUNNING,
    FINISHED,
    DETACHED
};

// Define CEthread structure
typedef struct CEthread
{
    pid_t                   thread_id;
    enum CEthread_state     state;
    CEthread_attr_t*        attributes;
} CEthread_t;

#endif /* PROJECT2_LIB_CETHREAD_THREAD_H */
