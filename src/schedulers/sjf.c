#include "sjf.h"

void sjf_sch(Ship* bridge_ship, int current_max){

    for (size_t i = 0; i <= current_max - 1; ++i)
    {
        
        for (size_t j = (i + 1); j <= current_max; ++j)
        {

            // If aj->speed > ai->speed
            if(bridge_ship[j].speed > bridge_ship[i].speed){
               // Create a temporary copy of bridge_ship + j in aj
                Alien tmp = bridge_ship[j]; 
                // Overwrite bridge_ship + j with bridge_ship + i
                bridge_ship[j] = bridge_ship[i];
                // Move the contents in aj into bridge_ship + i
                bridge_ship[i] = tmp;
            }
            
        }
        
    }

}