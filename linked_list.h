#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_

#include "types.h"

typedef struct node {
    struct Barco barco;
    struct node * next;
} node_t;


node_t * new_list(struct Barco barco);
void print_list(node_t * head);
void push(node_t * head, struct Barco barco);
struct Barco remove_last(node_t * head);

#endif /* _MY_HEADER_H_ */