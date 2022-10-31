#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "linked_list.h"


int userMenu(){
    int userOption;

    printf("-------Menu---------\n");
    printf("1 ----> Add node\n");
    printf("2 ----> Remove last node\n");
    printf("3 ----> Exit\n");
    printf("4 ----> Get n node\n");
    printf("-------Menu---------\n");

    printf("Option > ");
    scanf("%d",&userOption);
    printf("\n");

    return userOption;
}



int main(){
    int userOption = 3; // Exit por default
    int value;

    node_t * head = new_list(1);

    do
    {
        userOption = userMenu();
        if(userOption == 1){
            printf("--Value >");
            scanf("%d",&value);
            printf("\n");
            push(head, value);

        }else if(userOption == 2){
            remove_last(head);

        }else if (userOption == 4){
            printf("-- Pos >");
            scanf("%d",&value);
            value = get_n_item(head, value);
            printf("\nReturned value: %d\n", value);
        
        }else{

            userOption = 3;
        }
        print_list(head);
        
        
    } while (userOption != 3);
    

    return 0;
}

