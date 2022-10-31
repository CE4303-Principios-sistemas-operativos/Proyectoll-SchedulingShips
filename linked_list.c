#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "linked_list.h"


node_t * new_list(int val){
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head!=NULL){
        head->val=val;
        head->next=NULL;        
    }
    return head;
}


void print_list(node_t * head) {
    node_t * current = head;

    printf("Current list\n");
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}


int get_n_item(node_t * head, int n) {
    node_t * current = head;
    int count = 0;    
    printf("Current list\n");
    while (current != NULL) {
        if (count == n){
            return current->val;
        }
        count++;
        current = current->next;
    }
}





void push(node_t * head, int val) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}


int remove_last(node_t * head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;

}