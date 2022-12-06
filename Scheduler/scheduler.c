
#include "scheduler.h"


struct oceans priority(struct oceans oceans, int ocean)
{
    for (int i = 0; i < numberOfBoats; i++)

        {
            int a = oceans.boatFleets[ocean].boats[i].priority;
            int m = i;

            // Finding out highest priority element and placing it at its desired position

            for (int j = i; j < numberOfBoats; j++)

            {

                if (oceans.boatFleets[ocean].boats[j].priority < a)

                {

                    a = oceans.boatFleets[ocean].boats[j].priority;

                    m = j;
                }
            }
            // Swapping processes
            struct boat temp = oceans.boatFleets[ocean].boats[i];
            oceans.boatFleets[ocean].boats[i] = oceans.boatFleets[ocean].boats[m];
            oceans.boatFleets[ocean].boats[m] = temp;
        }
        
    return oceans;
};

struct oceans sjf(struct oceans oceans, int ocean, int canalLen)
{
    for (int i = 0; i < numberOfBoats; i++)

        {
            double a = (double) canalLen / oceans.boatFleets[ocean].boats[i].speed;
            int m = i;

            // Finding out highest priority element and placing it at its desired position

            for (int j = i; j < numberOfBoats; j++)

            {
                double cmp = (double) canalLen / oceans.boatFleets[ocean].boats[j].speed;
                if (cmp < a)

                {

                    a = (double) canalLen / oceans.boatFleets[ocean].boats[j].speed;

                    m = j;
                }
            }
            // Swapping processes
            struct boat temp = oceans.boatFleets[ocean].boats[i];
            oceans.boatFleets[ocean].boats[i] = oceans.boatFleets[ocean].boats[m];
            oceans.boatFleets[ocean].boats[m] = temp;
        }
        
    return oceans;
};


