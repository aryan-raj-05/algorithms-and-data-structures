#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node {
    int val;
    struct node *prev;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
    int size;
} list;

#endif