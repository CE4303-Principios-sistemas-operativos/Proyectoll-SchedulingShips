#include <stdio.h>
#include <stdlib.h>
#include "Barco.h"
#include "linkedList.h"


node_t * new_list(struct Barco barco){
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head!=NULL){
        head->barco=barco;
        head->next=NULL;        
    }
    return head;
}


void print_list(node_t * head) {
    node_t * current = head;

    printf("Current x position\n");
    while (current != NULL) {
        printf("%f\n", current->barco.position.y);
        current = current->next;
    }
}


void push(node_t * head, struct Barco barco) {
    node_t * current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->barco = barco;
    current->next->next = NULL;
}


struct Barco remove_last(node_t * head) {
    struct Barco retval;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        retval = head->barco;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t * current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->barco;
    free(current->next);
    current->next = NULL;
    return retval;

}