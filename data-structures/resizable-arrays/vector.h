#ifndef vector_h
#define vector_h

#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 8
#define GROWTH_FACTOR 2

typedef struct {
    int *items;
    int size;
    int capacity;
} vector;

void initVector(vector* v);
void push_back(vector* v, int item);
int itemAt(const vector* v, int index);
void freeVector(vector* v);
void printVector(const vector* v);

#endif